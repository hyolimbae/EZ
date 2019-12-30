#include "stdafx.h"
#include "Switch.h"


Switch::Switch()
{
	_physics = new Physics();
}


Switch::~Switch()
{

}

HRESULT Switch::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		_inArea = true;
		//electric 
		if (targetObj->GetTag() == "Character" && thisObj->GetName() == "Switch1")
		{
			rod = (ElectricRod*)targetObj;
		}

		// exit door
		if (targetObj->GetTag() == "Character" && thisObj->GetName() == "Switch2")
		{

		}
	});

	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		//door
		_inArea = false;
	});



	return S_OK;
}

void Switch::Update()
{
	GameObject::Update();

	if (_inArea && KEYMANAGER->IsOnceKeyDown('S') && _name == "Switch1")
	{
		rod->SetSprite(IMAGEMANAGER->FindImage("ElectricRodEnd"));
		rod->setActive(false);
	}

	if (_inArea && KEYMANAGER->IsOnceKeyDown('S') && _name == "Switch2")
	{

	}
}
