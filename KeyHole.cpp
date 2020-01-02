#include "stdafx.h"
#include "KeyHole.h"


KeyHole::KeyHole()
{
	_physics = new Physics();
}


KeyHole::~KeyHole()
{
}

HRESULT KeyHole::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			_inArea = true;
		}
	});


	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			_inArea = false;
		}
	});


	return S_OK;
}

void KeyHole::Update()
{
	GameObject::Update();

	if (_inArea && KEYMANAGER->IsOnceKeyDown('E'))
	{
		//여기서 문을 열어야하죵 
		//GameObject* obj = (GameObject *)GetParent()->GetChildByName("door");
		//obj->GetPhysics()->SetIsSensor(false);

	}
}
