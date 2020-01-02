#include "stdafx.h"
#include "Tomato.h"

#include "Olaf.h"
#include "Erik.h"
#include "Baleog.h"

HRESULT Tomato::Init()
{

	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Olaf* olaf = (Olaf*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Erik* erik = (Erik*)targetObj->GetPhysics()->GetBody()->GetUserData();
			Baleog* baleog = (Baleog*)targetObj->GetPhysics()->GetBody()->GetUserData();

			// tomato ¸Ô¾úÀ» ¶§
			if (thisObj->GetName() == "tomato")
			{
				thisObj->GetPhysics()->GetFixture()->SetSensor(true);

				if (targetObj->GetName() == "Olaf")
				{
					olaf->GetVInvenOlaf().push_back(thisObj);
				}
				if (targetObj->GetName() == "Erik")
				{
					erik->GetVInvenErik().push_back(thisObj);
				}
				if (targetObj->GetName() == "Baleog")
				{
					baleog->GetVInvenBaleog().push_back(thisObj);
				}

				thisObj->GetParent()->RemoveChild(thisObj);
			}
		}
	});



	return S_OK;
}

void Tomato::Update()
{
	Item::Update();
}
