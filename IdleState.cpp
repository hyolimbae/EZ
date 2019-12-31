#include "stdafx.h"
#include "IdleState.h"
#include "Character.h"
#include "MoveState.h"
#include "JumpState.h"
#include "StopState.h"
#include "AtkState.h"

void IdleState::UpdateState()
{
	if (KEYMANAGER->IsStayKeyDown(VK_LEFT) && _thisObj->GetTag() == "Character")
	{
		_thisObj->ChangeState(new MoveState(_thisObj));
	}
	if (KEYMANAGER->IsStayKeyDown(VK_RIGHT) && _thisObj->GetTag() == "Character")
	{
		_thisObj->ChangeState(new MoveState(_thisObj));
	}
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE) && _thisObj->GetName() == "Erik")
		//������ ������ �� ���ֽ��ϴ�.
	{
		_thisObj->ChangeState(new JumpState(_thisObj));
	}
	if (KEYMANAGER->IsOnceKeyDown('Q') && _thisObj->GetTag() == "Character")
	{
		_thisObj->ChangeState(new StopState(_thisObj));
	}
	//���� Ű ������ �� 
	if (KEYMANAGER->IsOnceKeyDown('D'))
	{
		_thisObj->ChangeState(new AtkState(_thisObj));
		if (_thisObj->GetName() == "Baleog")
		{
			_thisObj->SetATKType(KNIFE_ATTACK);
		}

		//DŰ ������ �� "Erik" ���� Ÿ�� ����
		/*if (_thisObj->GetName() == "Erik")
		{
			_thisObj->SetATKType();
		}*/

		//DŰ ������ �� "Olaf" ���� Ÿ�� ���� 
	/*	if (_thisObj->GetName() == "Olaf")
		{
			_thisObj->SetATKType();
		}*/
	}

	if (_thisObj->GetName() == "Baleog")
	{
		if (KEYMANAGER->IsOnceKeyDown('F'))
		{
			_thisObj->ChangeState(new AtkState(_thisObj));
			_thisObj->SetATKType(ARROW);
		}
	}
}

void IdleState::EnterState()
{
	//�ٷ��� �������� flip�Ǿ��ִ°��� ���� Idle�̹����� ��������� ������� �����մϴ�.
	if (_thisObj->GetName() == "Erik")
	{
		if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Idle"));
			_thisObj->GetSprite()->SetFlip(true, false);
		}
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Idle"));
			_thisObj->GetSprite()->SetFlip(false, false);
		}
	}
	if (_thisObj->GetName() == "Olaf")
	{
		if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Olaf_Idle"));
			_thisObj->GetSprite()->SetFlip(true, false);
		}
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Olaf_Idle"));
			_thisObj->GetSprite()->SetFlip(false, false);
		}
	}
	if (_thisObj->GetName() == "Baleog")
	{
		if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Idle"));
			_thisObj->GetSprite()->SetFlip(true, false);
		}
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Idle"));
			_thisObj->GetSprite()->SetFlip(false, false);
		}
	}
	b2Body* body = _thisObj->GetPhysics()->GetBody();
	if (!body) return;
	//MoveState���� IdleState�� ���� �ӵ��� 0���� �ٲ㼭 �������� �����.
	body->SetLinearVelocity(b2Vec2{ 0, 0 });
}

void IdleState::ExitState()
{

}
