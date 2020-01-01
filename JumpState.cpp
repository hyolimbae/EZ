#include "stdafx.h"
#include "Character.h"
#include "JumpState.h"
#include "MoveState.h"
#include "IdleState.h"

void JumpState::UpdateState()
{
	
	
}

void JumpState::EnterState()
{
	//플레이어가 Ground에 착지했다는 정보가 필요합니다.
	_thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Jump"));
	b2Body* body = _thisObj->GetPhysics()->GetBody();
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		b2Vec2 force = { 0, -700 };
		_thisObj->GetPhysics()->GetBody()->ApplyForceToCenter(force, true);
		_thisObj->ChangeState(new IdleState(_thisObj));
	}
}

void JumpState::ExitState()
{
	
}
