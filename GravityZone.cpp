#include "stdafx.h"
#include "GravityZone.h"

HRESULT GravityZone::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			if (thisObj->GetName() == "gravityZone")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);
			}
		}
	});

	SetCollisionStayFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetName() == "gravityZone")
			{
				GameObject* GravityZone = (GameObject*)thisObj->GetParent()->GetChildByName("gravityZone");
				character->GetPhysics()->GetBody()->SetGravityScale(-0.05f);
			}
		}
	});

	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetName() == "gravityZone")
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
