#include "stdafx.h"
#include "MoveState.h"
#include "Character.h"
#include "IdleState.h"
#include "JumpState.h"

void MoveState::UpdateState()
{
	b2Body* body = _thisObj->GetPhysics()->GetBody();

	if (_thisObj->GetTag() == "Character")
	{
		if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
			//오른쪽으로 움직임
		{
			_thisObj->GetSprite()->SetFlip(false, false);
			if (body->GetLinearVelocity().x > 3) //바디에 일정한 속도이상 올라가면 return으로 더 이상 받지않게해줍니다.
				return;							 //이거 안쓰면 누르고 있을때 속도계속 올라갑니다.
			//Body에 force를 주어서 움직이는 형식 입니다.
			b2Vec2 force = { 6,0 };
			_thisObj->GetPhysics()->GetBody()->ApplyForceToCenter(force, true);
		}
		else if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
			//왼쪽으로 움직임.
		{
			_thisObj->GetSprite()->SetFlip(true, false);
			if (body->GetLinearVelocity().x < -3) return; //역방향
			b2Vec2 force = { -6,0 };
			_thisObj->GetPhysics()->GetBody()->ApplyForceToCenter(force, true);
		}
		else
		{
			//움직임이 없을때에는 ChangeState로 Idle상태로 바꿔주도록 했습니다.
			_thisObj->ChangeState(new IdleState(_thisObj));
		}
	}
	//세마리의 바이킹이 속도가 조금씩 다르니까 TagName별로 나누어서 만들어야합니다.
}

void MoveState::EnterState()
{
	if (_thisObj->GetName() == "Erik") _thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Run"));
	if (_thisObj->GetName() == "Olaf") _thisObj->SetSprite(IMAGEMANAGER->FindImage("Olaf_Run"));
	if (_thisObj->GetName() == "Baleog") _thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Run"));
}

void MoveState::ExitState()
{
	
}


