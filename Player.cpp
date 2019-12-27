#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	_physics = new Physics;

}


Player::~Player()
{
}

HRESULT Player::Init()
{
	
	//그 외 변수 
	_hp = 50;
	_state = IDLE;
	_jumpCount = 0;

	if (_name == "player1") _isActive = true;
	else if (_name == "player2") _isActive = false;

	_sprite = IMAGEMANAGER->FindImage("stitch");

	return S_OK;
}

void Player::Release()
{
}

void Player::Update()
{
	if (_isActive)
	{
		KeyControl();

	}

	StateControl();

	if (KEYMANAGER->IsOnceKeyDown(VK_CONTROL))
	{
		_isActive = !_isActive;
	}
}

void Player::Render()
{
	//플레이어 hp
	_gaugeFront = RectMake(_transform->GetPosition().x-_transform->GetSize().x/2, _transform->GetPosition().y - 50, _hp, 10);
	_gaugeBack = RectMake(_transform->GetPosition().x - _transform->GetSize().x / 2, _transform->GetPosition().y - 50, 50, 10);
	
	IMAGEMANAGER->DrawRectangle(_gaugeBack, DefaultBrush::white);
	IMAGEMANAGER->FillRectangle(_gaugeFront, DefaultBrush::green);

	GameObject::Render();
}

void Player::KeyControl()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE) && _jumpCount < 2)
	{
		_state = ISJUMP;
		_jumpPower += PLAYERJUMPPOWER;
		_jumpCount++;
	}
	else
	{
		if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
		{
			GetTransform()->SetPosition(GetTransform()->GetPosition() - Vector2(2, 0));
		}
		else if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
		{
			GetTransform()->SetPosition(GetTransform()->GetPosition() + Vector2(2, 0));
		}
	}
}



void Player::StateControl()
{
	if (_state == IDLE)
	{
		_jumpCount = 0;
		_jumpPower = 0;
	}
	else if(_state == ISJUMP)
	{
		GetTransform()->SetPosition(Vector2(GetTransform()->GetPosition().x,GetTransform()->GetPosition().y - _jumpPower));
	}
}
