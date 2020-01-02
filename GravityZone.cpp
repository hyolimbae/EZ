#include "stdafx.h"
#include "GravityZone.h"
#include "Olaf.h"
#include "Erik.h"
#include "Baleog.h"

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
			Olaf* olaf = (Olaf*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Erik* erik = (Erik*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Baleog* baleog = (Baleog*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetTag() == "gravityZone")
			{
				if (targetObj->GetName() == "Olaf")
				{
					if (olaf->GetIfUsedShoe() == true)
					{
						olaf->GetPhysics()->GetBody()->SetGravityScale(1);
					}
					else 
					{
						targetObj->GetPhysics()->GetBody()->SetGravityScale(-0.05f);
					}
				}
				if (targetObj->GetName() == "Erik")
				{
					if (erik->GetIfUsedShoe() == true)
					{
						erik->GetPhysics()->GetBody()->SetGravityScale(1);
					}
					else
					{
						targetObj->GetPhysics()->GetBody()->SetGravityScale(-0.05f);
					}
				}
				if (targetObj->GetName() == "Baleog")
				{
					if (baleog->GetIfUsedShoe() == true)
					{
						baleog->GetPhysics()->GetBody()->SetGravityScale(1);
					}
					else
					{
						targetObj->GetPhysics()->GetBody()->SetGravityScale(-0.05f);
					}
				}
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
