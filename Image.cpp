#include "stdafx.h"
#include "image.h"

ID2D1HwndRenderTarget*  Image::_RT = nullptr;

HRESULT Image::Init(ID2D1Bitmap * bitmap, tagLoadedImageInfo loadinfo)
{
	_bitmap = bitmap;
	_loadInfo = loadinfo;

	_size.x = (float)_bitmap->GetPixelSize().width;
	_size.y = (float)_bitmap->GetPixelSize().height;

	center = { _size.x * 0.5f, _size.y * 0.5f };

	_scale.x = _scale.y = 1.0f;
	_alpha = 1.0f;
	_angle = 0;

	WICRect rc;
	rc.X = rc.Y = 0;
	rc.Width = _size.x;
	rc.Height = _size.y;
	_frameInfo.push_back(rc);

	_maxFrameX = _maxFrameY = 1;

	return S_OK;
}

HRESULT Image::Init(ID2D1Bitmap * bitmap, tagLoadedImageInfo loadinfo, int maxframeX, int maxframeY)
{
	_bitmap = bitmap;
	_loadInfo = loadinfo;

	_size.x = (float)_bitmap->GetPixelSize().width;
	_size.y = (float)_bitmap->GetPixelSize().height;

	_scale.x = _scale.y = 1.0f;
	_alpha = 1.0f;
	_angle = 0;

	int frameX = _size.x / maxframeX;
	int frameY = _size.y / maxframeY;

	WICRect rc;
	for (int j = 0; j < maxframeY; ++j)
	{
		for (int i = 0; i < maxframeX; ++i)
		{
			rc.X = i * frameX;
			rc.Y = j * frameY;
			rc.Width = frameX;
			rc.Height = frameY;
			_frameInfo.push_back(rc);
		}
	}

	_maxFrameX = maxframeX -1 ;
	_maxFrameY = maxframeY -1 ;

	return S_OK;
}

void Image::Release()
{
	_bitmap->Release();
	_bitmap = nullptr;

	if (_pixelCollisionDC)
	{
		DeleteDC(_pixelCollisionDC);
	}

}
D2D1::Matrix3x2F Image::SetupRender(int x, int y)
{
	POINT pt = { x,y };

	//_RT->SetTransform(D2D1::Matrix3x2F::Identity());

	return D2D1::Matrix3x2F::Translation(pt.x, pt.y);
}

Vector2 Image::GetPivotPosition(int x, int y, Pivot::Enum pivot)
{
	if (pivot == Pivot::LEFT_TOP) return Vector2(x, y);

	Vector2 pos = Vector2(x,y);

	switch (pivot)
	{
	case Pivot::CENTER:
		pos.x -= _size.x * _scale.x * 0.5f;
		pos.y -= _size.y * _scale.y * 0.5f;
		break;

	case Pivot::BOTTOM:
		pos.x -= _size.x * _scale.x * 0.5f;
		pos.y -= _size.y * _scale.y;
		break;

	case Pivot::TOP:
		pos.x -= _size.x * _scale.x * 0.5f;
		break;
	}

	return pos;
}

void Image::Render(int x, int y, Pivot::Enum pivot, bool isRelativePos)
{
	//SCALE
	_size.x *= _scale.x;
	_size.y *= _scale.y;


	Vector2 render = GetPivotPosition(x, y, pivot);

	////if (isRelativePos)
	////{
	////	//카메라
	////	float zoom = 1 / 2;
	////	//여기서 ZOOM = ZOOMED / ORIGINAL? 

	////	//so you scale things down here 
	////	vector2D scale = vector2D(zoom, zoom);
	////	_size.x *= scale.x;
	////	_size.y *= scale.y;


	////}

	////카메라에 없으면 랜더x

	////relative pos - size needs to be somewhere in between 0 and winsizex (which we decided to be the range of camera)
	////so why do we have to scale things down and up?
	//if (render.x-_size.x > WINSIZEX || render.x + _size.x < 0 ||
	//	render.y-_size.y > WINSIZEY || render.y + _size.y < 0)
	//{
	//	resetRenderOption();
	//	return;
	//}

	////--->From here, in range of camera 


	//and scale things up here again?
	Vector2 factor = Vector2(_size.x / _scale.x, _size.y / _scale.y);
	D2D1_SIZE_F size = { factor.x, factor.y };
	D2D1::Matrix3x2F scale = D2D1::Matrix3x2F::Identity();


	//회전, 이동 , 반전 
	D2D1::Matrix3x2F rotation = D2D1::Matrix3x2F::Rotation(_angle, D2D1::Point2F()); 	//Applying ARG1 angle around ARG2. 
	D2D1::Matrix3x2F translation = D2D1::Matrix3x2F::Translation(x, y);
	D2D1::Matrix3x2F flip = D2D1::Matrix3x2F::Identity();
	if (_flipX) flip._11 = -1;
	if (_flipY) flip._22 = -1;



	D2D1_RECT_F dxArea;
	switch (pivot)
	{
	case Pivot::LEFT_TOP:
		dxArea = D2D1::RectF(0, 0, _size.x, _size.y);
		break;


	case Pivot::CENTER:
		dxArea = D2D1::RectF(-_size.x / 2, -_size.y / 2, _size.x / 2, _size.y / 2);
		break;



	case Pivot::BOTTOM:
		dxArea = D2D1::RectF(-_size.x / 2, -_size.y, _size.x / 2, 0);
		break;

	case Pivot::TOP:
		dxArea = D2D1::RectF(-_size.x / 2, 0, _size.x / 2, _size.y);
		break;
	}

	//BE AWARE: matrix multiplication is not commutative
	_RT->SetTransform(D2D1::Matrix3x2F::Identity() * scale* flip *rotation *translation);
	//_RT->SetTransform(D2D1::Matrix3x2F::Identity() * flip *rotation *translation);
	_RT->DrawBitmap(_bitmap, dxArea, _alpha);


	//RESET
	//before you render, make sure to set option values independently; 
	//it works this way in order not to interfere with other images you render.
	_RT->SetTransform(D2D1::Matrix3x2F::Identity());
	ResetRenderOption();

}

void Image::FrameRender(int x, int y, int frameX, int frameY, Pivot::Enum pivot, bool isRelativePos)
{
	int frame = frameY * _maxFrameX + frameX;
	_size = GetFrameSize(frame);

	_size.x = _size.x;
	_size.y = _size.y;

	D2D1::Matrix3x2F rotation = D2D1::Matrix3x2F::Rotation(_angle, D2D1::Point2F());
	D2D1::Matrix3x2F trans = D2D1::Matrix3x2F::Translation(x, y);
	D2D1::Matrix3x2F flip = D2D1::Matrix3x2F::Identity();
	if (_flipX) flip._11 = -1;
	if (_flipY) flip._22 = -1;

	D2D1_RECT_F dxArea;
	switch (pivot)
	{
	case Pivot::LEFT_TOP:
		dxArea = D2D1::RectF(0, 0, _size.x, _size.y);
		break;
	case Pivot::CENTER:
		dxArea = D2D1::RectF(-_size.x / 2, -_size.y / 2, _size.x / 2, _size.y / 2);
		break;

	case Pivot::BOTTOM:
		dxArea = D2D1::RectF(-_size.x / 2, -_size.y, _size.x / 2, 0);
		break;

	case Pivot::TOP:
		dxArea = D2D1::RectF(-_size.x / 2, 0, _size.x / 2, _size.y);
		break;
	}
	D2D1_RECT_F dxSrc = D2D1::RectF(_frameInfo[frame].X, _frameInfo[frame].Y,
		_frameInfo[frame].X + _frameInfo[frame].Width, _frameInfo[frame].Y + _frameInfo[frame].Height);
	_RT->SetTransform(D2D1::Matrix3x2F::Identity()* rotation*flip * trans);
	_RT->DrawBitmap(_bitmap, dxArea, _alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &dxSrc);

	_RT->SetTransform(D2D1::Matrix3x2F::Identity());

	ResetRenderOption();

}


void Image::ResetRenderOption()
{
	_alpha = 1.0f;
	_scale.x = 1.0f;
	_scale.y = 1.0f;
	//_size.x = _bitmap->GetPixelSize().width;
	//_size.y = _bitmap->GetPixelSize().height;

}

