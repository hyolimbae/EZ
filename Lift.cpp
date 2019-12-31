#include "stdafx.h"
#include "Lift.h"
#include "playGround.h"

HRESULT Lift::Init()
{
	_isOnLift = false;
	_isLiftMovingUp = false;


	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
			//character->SetState(IDLE);

			if (thisObj->GetName() == "lift")
			{
				Lift* lift = (Lift*)thisObj->GetParent()->GetChildByName("lift");
				lift->SetIsOnLift(true);
			}
		}
	});

	SetCollisionStayFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
		}
	});

	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetName() == "lift")
			{
				Lift* lift = (Lift*)thisObj->GetParent()->GetChildByName("lift");
				lift->SetIsOnLift(false);
			}
		}
	});

	return S_OK;
}

void Lift::Update()
{
	GameObject::Update();
	
	LiftMove();
}


void Lift::LiftMove()
{
	if (_name == "lift")
	{
		if (KEYMANAGER->IsOnceKeyDown(VK_UP) && _isOnLift)
		{
			SetIsLiftMovingUp(true);
		}
		if (KEYMANAGER->IsOnceKeyDown(VK_DOWN) && _isOnLift)
		{
			SetIsLiftMovingUp(false);
		}

		if (_isLiftMovingUp)
		{
			if (_transform->GetPosition().y > playGround::Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 950),
				_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
			{
				_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - 1));
			}
		}
		else
		{
			if (_transform->GetPosition().y < playGround::Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 1804),
				_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
			{
				_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y + 1));
			}
		}
	}
}
