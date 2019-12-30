#include "stdafx.h"
#include "ElectricBox.h"
#include "Character.h"



ElectricBox::ElectricBox()
{
	_physics = new Physics();
}


ElectricBox::~ElectricBox()
{
}

HRESULT ElectricBox::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
			character->SetDeltaTime(0.5);
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

void ElectricBox::Update()
{
	GameObject::Update();

	if (_timer > 0)
	{
		//2초있다가 릴리즈 
		if (TIMEMANAGER->getWorldTime() - _timer > 2)
		{
			character->GetParent()->RemoveChild(character);

		}
	}
}
