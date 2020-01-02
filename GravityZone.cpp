#include "stdafx.h"
#include "GravityZone.h"

HRESULT GravityZone::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			if (thisObj->GetTag() == "gravityZone")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);
			}
		}
	});

	SetCollisionStayFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetTag() == "gravityZone")
			{
				GameObject* GravityZone = (GameObject*)thisObj->GetParent()->GetChildByName("gravityZone");
				character->GetPhysics()->GetBody()->SetGravityScale(-0.05f);
			}
		}
	});

	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetTag() == "gravityZone")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(false);
				character->GetPhysics()->GetBody()->SetGravityScale(1);
			}
		}
	});

	return S_OK;
}

void GravityZone::Update()
{
	GameObject::Update();
}
