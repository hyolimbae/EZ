#include "stdafx.h"
#include "Ladder.h"

HRESULT Ladder::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetName() == "ladder1")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				character->GetPhysics()->SetGravityScale(0);

				_lCharacterAtLadder1.push_back(character);
			}
			if (thisObj->GetName() == "ladder2")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				character->GetPhysics()->SetGravityScale(0);

				_lCharacterAtLadder2.push_back(character);
			}
			if (thisObj->GetName() == "ladder3")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				character->GetPhysics()->SetGravityScale(0);

				_lCharacterAtLadder3.push_back(character);
			}
			if (thisObj->GetName() == "ladder4")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				character->GetPhysics()->SetGravityScale(0);

				_lCharacterAtLadder4.push_back(character);
			}
		}
	});


	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();
			//character->SetState(IDLE);

			if (thisObj->GetName() == "ladder1")
			{
				character->GetPhysics()->SetGravityScale(1);

				_lCharacterAtLadder1.remove(character);
			}
			if (thisObj->GetName() == "ladder2")
			{
				character->GetPhysics()->SetGravityScale(1);

				_lCharacterAtLadder2.remove(character);
			}
			if (thisObj->GetName() == "ladder3")
			{
				character->GetPhysics()->SetGravityScale(1);

				_lCharacterAtLadder3.remove(character);
			}
			if (thisObj->GetName() == "ladder4")
			{
				character->GetPhysics()->SetGravityScale(1);

				_lCharacterAtLadder4.remove(character);
			}
		}
	});

	return S_OK;
}

void Ladder::Update()
{
	GameObject::Update();

	if (_lCharacterAtLadder1.size() > 0) { ClimbingLadder1(); }
	if (_lCharacterAtLadder2.size() > 0) { ClimbingLadder2(); }
	if (_lCharacterAtLadder3.size() > 0) { ClimbingLadder3(); }
	if (_lCharacterAtLadder4.size() > 0) { ClimbingLadder4(); }
}

void Ladder::ClimbingLadder1()
{
	for (Character* character : _lCharacterAtLadder1)
	{
		if (KEYMANAGER->IsStayKeyDown(VK_UP))
		{
			character->GetTransform()->SetPosX(_transform->GetPosition().x);
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y - 2));
		}
		if (KEYMANAGER->IsStayKeyDown(VK_DOWN))
		{
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y + 2));
		}
	}
}

void Ladder::ClimbingLadder2()
{
	for (Character* character : _lCharacterAtLadder2)
	{
		if (KEYMANAGER->IsStayKeyDown(VK_UP))
		{
			character->GetTransform()->SetPosX(_transform->GetPosition().x);
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y - 2));
		}
		if (KEYMANAGER->IsStayKeyDown(VK_DOWN))
		{
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y + 2));
		}
	}
}

void Ladder::ClimbingLadder3()
{
	for (Character* character : _lCharacterAtLadder3)
	{
		if (KEYMANAGER->IsStayKeyDown(VK_UP))
		{
			character->GetTransform()->SetPosX(_transform->GetPosition().x);
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y - 2));
		}
		if (KEYMANAGER->IsStayKeyDown(VK_DOWN))
		{
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y + 2));
		}
	}
}

void Ladder::ClimbingLadder4()
{
	for (Character* character : _lCharacterAtLadder4)
	{
		if (KEYMANAGER->IsStayKeyDown(VK_UP))
		{
			character->GetTransform()->SetPosX(_transform->GetPosition().x);
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y - 2));
		}
		if (KEYMANAGER->IsStayKeyDown(VK_DOWN))
		{
			character->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, character->GetTransform()->GetPosition().y + 2));
		}
	}
}
