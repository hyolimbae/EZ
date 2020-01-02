#include "stdafx.h"
#include "Meat.h"
#include "Olaf.h"
#include "Erik.h"
#include "Baleog.h"

HRESULT Meat::Init()
{

	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Olaf* olaf = (Olaf*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Erik* erik = (Erik*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Baleog* baleog = (Baleog*)targetObj->GetPhysics()->GetBody()->GetUserData();

			// meat ¸Ô¾úÀ» ¶§
			if (thisObj->GetName() == "meat")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				if (targetObj->GetName() == "Olaf")
				{
					olaf->GetVInvenOlaf().push_back(thisObj);
				}
				if (targetObj->GetName() == "Erik")
				{
					erik->GetVInvenErik().push_back(erik);
				}
				if (baleog->GetName() == "Baleog")
				{
					baleog->GetVInvenBaleog().push_back(thisObj);
				}

				thisObj->GetParent()->RemoveChild(thisObj);
			}
		}
	});



	return S_OK;
}

void Meat::Update()
{
	Item::Update();
}
