#pragma once
#include "State.h"
#include "Character.h"
#include "IdleState.h"

class MoveState : public State
{
public:
	MoveState(Character* thisObj) : State(thisObj) {}
	virtual void UpdateState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	
};

