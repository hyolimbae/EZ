#pragma once
#include "State.h"
#include "Bullet.h"

class AtkState : public State
{
public:

	AtkState(Character* thisObj) : State(thisObj) {} 

	virtual void EnterState() override; 
	virtual void UpdateState() override; 
	virtual void ExitState() override; 

};

