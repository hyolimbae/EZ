#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	_physics = new Physics();
}


Character::~Character()
{
}

HRESULT Character::Init()
{
	return S_OK;
}

void Character::Update()
{
	GameObject::Update();


	if (_hp > 0)
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
