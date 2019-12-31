#include "stdafx.h"
#include "Obstacle.h"


Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

HRESULT Obstacle::Init()
{
	_physics = new Physics;

	if (_name == "ground")
	{
		_obsType = GROUND;
	}

	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			Character* player = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
		}
	});

	return S_OK;
}

void Obstacle::Release()
{
}

void Obstacle::Update()
{
	
}

void Obstacle::Render()
{
	RECT rc = RectMakeCenter(_transform->GetPosition().x, _transform->GetPosition().y, _transform->GetSize().x, _transform->GetSize().y);
	IMAGEMANAGER->FillRectangle(rc, DefaultBrush::gray);
}

void Obstacle::MoveUp()
{

}

