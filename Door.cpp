#include "stdafx.h"
#include "Door.h"
#include "playGround.h"

HRESULT Door::Init()
{
	_isDoor1Opening = _isDoor1Closing = false;
	_isDoor2Opening = _isDoor2Closing = false;

	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();
			//character->SetState(IDLE);

			if (thisObj->GetName() == "doorSensor1")
			{
				Door* door1B = (Door*)thisObj->GetParent()->GetChildByName("doorBottom1");
				door1B->SetIsDoor1Opening(true);
				door1B->SetIsDoor1Closing(false);
				Door* door1T = (Door*)thisObj->GetParent()->GetChildByName("doorTop1");
				door1T->SetIsDoor1Opening(true);
				door1T->SetIsDoor1Closing(false);

				thisObj->GetPhysics()->GetFixture()->SetSensor(true);
			}
			if (thisObj->GetName() == "doorSensor2")
			{
				Door* door1B = (Door*)thisObj->GetParent()->GetChildByName("doorBottom2");
				door1B->SetIsDoor2Opening(true);
				door1B->SetIsDoor2Closing(false);
				Door* door1T = (Door*)thisObj->GetParent()->GetChildByName("doorTop2");
				door1T->SetIsDoor2Opening(true);
				door1T->SetIsDoor2Closing(false);

				thisObj->GetPhysics()->GetFixture()->SetSensor(true);
			}
		}
	});

	SetCollisionExitFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "character")
		{
			Character* character = (Character*)targetObj->GetPhysics()->GetBody()->GetUserData();

			if (thisObj->GetName() == "doorSensor1")
			{
				Door* door2B = (Door*)thisObj->GetParent()->GetChildByName("doorBottom1");
				door2B->SetIsDoor1Opening(false);
				door2B->SetIsDoor1Closing(true);
				Door* door2T = (Door*)thisObj->GetParent()->GetChildByName("doorTop1");
				door2T->SetIsDoor1Opening(false);
				door2T->SetIsDoor1Closing(true);

				thisObj->GetPhysics()->GetFixture()->SetSensor(false);
			}
			if (thisObj->GetName() == "doorSensor2")
			{
				Door* door2B = (Door*)thisObj->GetParent()->GetChildByName("doorBottom2");
				door2B->SetIsDoor2Opening(false);
				door2B->SetIsDoor2Closing(true);
				Door* door2T = (Door*)thisObj->GetParent()->GetChildByName("doorTop2");
				door2T->SetIsDoor2Opening(false);
				door2T->SetIsDoor2Closing(true);

				thisObj->GetPhysics()->GetFixture()->SetSensor(false);
			}
		}
	});

	return S_OK;
}

void Door::Update()
{
	GameObject::Update();

	if (_tag == "door1")
	{
		if (_isDoor1Opening)		{ Door1Opening(); }
		else if (_isDoor1Closing)	{ Door1Closing(); }
	}
	if (_tag == "door2")
	{
		if (_isDoor2Opening)		{ Door2Opening(); }
		else if (_isDoor2Closing)	{ Door2Closing(); }
	}
}


void Door::Door1Opening()
{
	if (_name == "doorTop1")
	{
		if (_transform->GetPosition().y > Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 1250 - 76),
				_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - 2));
		}
	}
	else if (_name == "doorBottom1")
	{
		if (_transform->GetPosition().y < Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 1326 + 76),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y + 2));
		}
	}
}

void Door::Door1Closing()
{
	if (_name == "doorTop1")
	{
		if (_transform->GetPosition().y < Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 1250),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y + 2));
		}
	}
	else if (_name == "doorBottom1")
	{
		if (_transform->GetPosition().y > Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 1326),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - 2));
		}
	}
}

void Door::Door2Opening()
{
	if (_name == "doorTop2")
	{
		if (_transform->GetPosition().y > Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 295 - 76),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - 2));
		}
	}
	else if (_name == "doorBottom2")
	{
		if (_transform->GetPosition().y < Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 371 + 76),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y + 2));
		}
	}
}

void Door::Door2Closing()
{
	if (_name == "doorTop2")
	{
		if (_transform->GetPosition().y < Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 295),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y + 2));
		}
	}
	else if (_name == "doorBottom2")
	{
		if (_transform->GetPosition().y > Hyolim_LeftTop(Vector2(_transform->GetPosition().x, 371),
			_transform->GetSize().x*BACKGROUND_SCALE, _transform->GetSize().y*BACKGROUND_SCALE).y)
		{
			_transform->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - 2));
		}
	}
}