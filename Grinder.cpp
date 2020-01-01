#include "stdafx.h"
#include "Grinder.h"


Grinder::Grinder()
{
	_physics = new Physics;
}


Grinder::~Grinder()
{
}

HRESULT Grinder::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
			character->SetHP(0);	//나중에 매니저에서 hp = 0이 되면 키컨트롤 즉 character update쪽이 돌지 않도록 설정 


			if (targetObj->GetName() == "Erik")
			{
				character->SetSprite(IMAGEMANAGER->FindImage("Erik_Grinder"));
			}
			else if (targetObj->GetName() == "Olaf")
			{

			}
			else if (targetObj->GetName() == "Baleog")
			{

			}
			PHYSICSMANAGER->IgnoreCollision(thisObj, targetObj);
			_timer = TIMEMANAGER->getWorldTime();


			
			//센서가 활성화 되면 stay는 입력받지 못하고 exit과 enter만 입력받을 수 있다.
			//character->GetPhysics()->GetFixture()->SetSensor(true);

		}
	});


	return S_OK;
}

void Grinder::Update()
{
	GameObject::Update();
	//신호가 들어왔다면 
	if (_timer > 0)
	{
		//잠시 기다렸다가 밑으로 떨어지기 
		if (TIMEMANAGER->getWorldTime() - _timer > 1)
		{
			character->GetPhysics()->SetGravityScale(0.1f);
			//character->SetDeltaTime(0.25);
		}
		else
		{
			character->GetPhysics()->SetGravityScale(0.f);
			
			character->SetDeltaTime(0.25);
			if (!_isDown)
			{
				character->GetTransform()->SetPosition(character->GetTransform()->GetPosition() + Vector2(0, 30));
				_isDown = true;
			}
				
		}

		if (character->GetCurrentPosition().x == character->GetSprite()->GetMaxFrameX())
		{
			character->GetParent()->RemoveChild(character);
			_isDown = false;
		}
	}
}



