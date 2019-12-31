#include "stdafx.h"
#include "Teleport.h"
#include "playGround.h"

HRESULT Teleport::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetName() == "teleport1A")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				_lCharacterAtTeleport1A.push_back(character);
			}
			if (thisObj->GetName() == "teleport1B")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				_lCharacterAtTeleport1B.push_back(character);
			}
			if (thisObj->GetName() == "teleport2A")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				_lCharacterAtTeleport2A.push_back(character);
			}
			if (thisObj->GetName() == "teleport2B")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				_lCharacterAtTeleport2B.push_back(character);
			}
		}
	});

	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();
			//character->SetState(IDLE);

			if (thisObj->GetName() == "teleport1A")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(false);

				_lCharacterAtTeleport1A.remove(character);
			}
			if (thisObj->GetName() == "teleport1B")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(false);

				_lCharacterAtTeleport1B.remove(character);
			}
			if (thisObj->GetName() == "teleport2A")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(false);

				_lCharacterAtTeleport2A.remove(character);
			}
			if (thisObj->GetName() == "teleport2B")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(false);

				_lCharacterAtTeleport2B.remove(character);
			}
		}
	});
	return S_OK;
}

void Teleport::Update()
{
	GameObject::Update();
	
	if (_lCharacterAtTeleport1A.size() > 0) { Teleport1ATo1B(); }
	if (_lCharacterAtTeleport1B.size() > 0) { Teleport1BTo1A(); }
	if (_lCharacterAtTeleport2A.size() > 0) { Teleport2ATo2B(); }
	if (_lCharacterAtTeleport2B.size() > 0) { Teleport2BTo2A(); }
}

void Teleport::Teleport1ATo1B()
{
	for (Character* character : _lCharacterAtTeleport1A)
	{
		if (_lCharacterAtTeleport1A.size() > 0)
		{
			if (KEYMANAGER->IsStayKeyDown('S'))
			{
				Teleport* teleport1B = (Teleport*)GetParent()->GetChildByName("teleport1B");

				character->GetTransform()->SetPosition(playGround::Hyolim_LeftTop(Vector2(3938, 1301),
					teleport1B->GetTransform()->GetSize().x*BACKGROUND_SCALE,
					teleport1B->GetTransform()->GetSize().y*BACKGROUND_SCALE));
			}
		}
	}
}

void Teleport::Teleport1BTo1A()
{
	for (Character* character : _lCharacterAtTeleport1B)
	{
		if (_lCharacterAtTeleport1B.size() > 0)
		{
			if (KEYMANAGER->IsStayKeyDown('S'))
			{
				Teleport* teleport1A = (Teleport*)GetParent()->GetChildByName("teleport1A");

				character->GetTransform()->SetPosition(playGround::Hyolim_LeftTop(Vector2(158, 344),
					teleport1A->GetTransform()->GetSize().x*BACKGROUND_SCALE,
					teleport1A->GetTransform()->GetSize().y*BACKGROUND_SCALE));
			}
		}
	}
}

void Teleport::Teleport2ATo2B()
{
	for (Character* character : _lCharacterAtTeleport2A)
	{
		if (_lCharacterAtTeleport2A.size() > 0)
		{
			if (KEYMANAGER->IsStayKeyDown('S'))
			{
				Teleport* teleport2B = (Teleport*)GetParent()->GetChildByName("teleport2B");

				character->GetTransform()->SetPosition(playGround::Hyolim_LeftTop(Vector2(208, 1754),
					teleport2B->GetTransform()->GetSize().x*BACKGROUND_SCALE,
					teleport2B->GetTransform()->GetSize().y*BACKGROUND_SCALE));
			}
		}
	}
}

void Teleport::Teleport2BTo2A()
{
	for (Character* character : _lCharacterAtTeleport2B)
	{
		if (_lCharacterAtTeleport2B.size() > 0)
		{
			if (KEYMANAGER->IsStayKeyDown('S'))
			{
				Teleport* teleport2A = (Teleport*)GetParent()->GetChildByName("teleport2A");

				character->GetTransform()->SetPosition(playGround::Hyolim_LeftTop(Vector2(258, 1352),
					teleport2A->GetTransform()->GetSize().x*BACKGROUND_SCALE,
					teleport2A->GetTransform()->GetSize().y*BACKGROUND_SCALE));
			}
		}
	}
}