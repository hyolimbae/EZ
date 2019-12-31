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
	//카운트받는건 Enter에서 받게 해줍니다.
	_count = TIMEMANAGER->getWorldTime();

	b2Body* body = _thisObj->GetPhysics()->GetBody();
	if (!body) return;
}

void StopState::UpdateState()
{
	//_count = TIMEMANAGER->getWorldTime();
	//2초후에 다시 Idle State로 돌아갑니다.
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
	//Exit에서 다시 카운트 0으로 만들어줍니다.
	_count = 0;
}
