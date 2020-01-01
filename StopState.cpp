#include "stdafx.h"
#include "StopState.h"
#include "Character.h"
#include "IdleState.h"

void StopState::EnterState()
{
	if (_thisObj->GetName() == "Erik")
	{
		if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Hit"));
			_thisObj->GetSprite()->SetFlip(true, false);
		}
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Hit"));
			_thisObj->GetSprite()->SetFlip(false, false);
		}
	}
	if (_thisObj->GetName() == "Olaf")
	{
		if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Olaf_Hit"));
			_thisObj->GetSprite()->SetFlip(true, false);
		}
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Olaf_Hit"));
			_thisObj->GetSprite()->SetFlip(false, false);
		}
	}
	if (_thisObj->GetName() == "Baleog")
	{
		if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Hit"));
			_thisObj->GetSprite()->SetFlip(true, false);
		}
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Hit"));
			_thisObj->GetSprite()->SetFlip(false, false);
		}
	}
	//ī��Ʈ�޴°� Enter���� �ް� ���ݴϴ�.
	_count = TIMEMANAGER->getWorldTime();

	b2Body* body = _thisObj->GetPhysics()->GetBody();
	if (!body) return;
}

void StopState::UpdateState()
{
	//_count = TIMEMANAGER->getWorldTime();
	//2���Ŀ� �ٽ� Idle State�� ���ư��ϴ�.
	if (TIMEMANAGER->getWorldTime() - _count > 2 && _thisObj->GetName() == "Erik")
	{
		_thisObj->ChangeState(new IdleState(_thisObj));
	}
	if(TIMEMANAGER->getWorldTime() - _count > 2 && _thisObj->GetName() == "Olaf")
	{
		_thisObj->ChangeState(new IdleState(_thisObj));
	}
	if (TIMEMANAGER->getWorldTime() - _count > 2 && _thisObj->GetName() == "Baleog")
	{
		_thisObj->ChangeState(new IdleState(_thisObj));
	}
}

void StopState::ExitState()
{
	//Exit���� �ٽ� ī��Ʈ 0���� ������ݴϴ�.
	_count = 0;
}
