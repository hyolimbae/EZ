#include "stdafx.h"
#include "Grinder.h"


Grinder::Grinder()
{
	_physics = new Physics;
}


Grinder::~Grinder()
{
}

HRESULT Grinder::Init()
{
	SetCollisionEnterFunc([&](GameObject* thisObj, GameObject* targetObj)
	{
		if (targetObj->GetTag() == "Character")
		{
			character = (Character *)targetObj->GetPhysics()->GetBody()->GetUserData();
			character->SetHP(0);	//���߿� �Ŵ������� hp = 0�� �Ǹ� Ű��Ʈ�� �� character update���� ���� �ʵ��� ���� 


			if (targetObj->GetName() == "Erik")
			{
				character->SetSprite(IMAGEMANAGER->FindImage("Erik_Grinder"));
			}
			else if (targetObj->GetName() == "Olaf")
			{

			}
			else if (targetObj->GetName() == "Baleog")
			{

			}
			PHYSICSMANAGER->IgnoreCollision(thisObj, targetObj);
			_timer = TIMEMANAGER->getWorldTime();


			
			//������ Ȱ��ȭ �Ǹ� stay�� �Է¹��� ���ϰ� exit�� enter�� �Է¹��� �� �ִ�.
			//character->GetPhysics()->GetFixture()->SetSensor(true);

		}
	});


	return S_OK;
}

void Grinder::Update()
{
	GameObject::Update();
	//��ȣ�� ���Դٸ� 
	if (_timer > 0)
	{
		//��� ��ٷȴٰ� ������ �������� 
		if (TIMEMANAGER->getWorldTime() - _timer > 1)
		{
			character->GetPhysics()->SetGravityScale(0.1f);
			//character->SetDeltaTime(0.25);
		}
		else
		{
			character->GetPhysics()->SetGravityScale(0.f);
			
			character->SetDeltaTime(0.25);
			if (!_isDown)
			{
				character->GetTransform()->SetPosition(character->GetTransform()->GetPosition() + Vector2(0, 30));
				_isDown = true;
			}
				
		}

		if (character->GetCurrentPosition().x == character->GetSprite()->GetMaxFrameX())
		{
			character->GetParent()->RemoveChild(character);
			_isDown = false;
		}
	}
}



