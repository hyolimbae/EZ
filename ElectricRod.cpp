#include "stdafx.h"
#include "ElectricRod.h"

ElectricRod::ElectricRod()
{
	_physics = new Physics();
}


ElectricRod::~ElectricRod()
{
}

HRESULT ElectricRod::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character" && _isActive)
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
			//character->SetDeltaTime(0.2);
			_timer = TIMEMANAGER->getWorldTime();
			character->setHP(0);

			if (targetObj->GetName() == "Erik")
			{
				character->SetSprite(IMAGEMANAGER->FindImage("Erik_Electric"));
			}
			else if (targetObj->GetName() == "Olaf")
			{

			}
			else if (targetObj->GetName() == "Baleog")
			{

			}

		}
	});
	return S_OK;
}

void ElectricRod::Update()
{
	GameObject::Update();

	if (_timer > 0)
	{
		//2초있다가 릴리즈 
		if (TIMEMANAGER->getWorldTime() - _timer > 2)
		{
			character->GetParent()->RemoveChild(character);
			_timer = 0;
		}
	}
}
