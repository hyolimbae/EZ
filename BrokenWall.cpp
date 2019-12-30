#include "stdafx.h"
#include "BrokenWall.h"


BrokenWall::BrokenWall()
{
	_physics = new Physics();
}


BrokenWall::~BrokenWall()
{
}

HRESULT BrokenWall::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetName() == "Erik")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
			//공격 상태라면 
			//if (character->getState() == ATTACK)
			//{
				thisObj->SetSprite(IMAGEMANAGER->FindImage("BrokenWall_Frame"));
				thisObj->SetDeltaTime(0.2);

				//targetObj->GetPhysics()->GetBody()->GetFixtureList()->SetRestitution(1.5);

				b2Vec2 force = b2Vec2(100, -300);
				character->GetPhysics()->GetBody()->ApplyForceToCenter(force, true);
				character->GetPhysics()->GetBody()->GetFixtureList()->SetFriction(0.8);
				character->GetPhysics()->GetFixture()->SetRestitution(0.4);


				_timer = TIMEMANAGER->getWorldTime();
			//셋 스프라이트 하고 maxframe 다다르면 유지 
			//그리고 플레이어 상태 STOP enter

		}
	});
	return S_OK;
}

void BrokenWall::Update()
{
	GameObject::Update();
	if (_timer > 0)
	{		
		character->GetPhysics()->GetBody()->SetLinearVelocity(character->GetPhysics()->GetBody()->GetLinearVelocity() + b2Vec2(0.00000001, 0));

		if (TIMEMANAGER->getWorldTime() - _timer > 0.5)
		{
			character->GetPhysics()->GetBody()->SetLinearVelocity(b2Vec2(0, character->GetPhysics()->GetBody()->GetLinearVelocity().y));
			character->GetPhysics()->GetFixture()->SetRestitution(0.f);
		}

		if (_currentPosition.x == _sprite->GetMaxFrameX()-1)
		{
			SetSprite(IMAGEMANAGER->FindImage("BrokenWallEnd"));
		}
	}
}
