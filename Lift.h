#pragma once
#include "GameObject.h"
#include "Character.h"

class Lift : public GameObject
{
private:
	Character* character;

	bool _isOnLift;
	bool _isLiftMovingUp;

public:
	Lift() { _physics = new Physics(); };
	~Lift() {};

	virtual HRESULT Init() override;
	virtual void Update() override;

	void LiftMove();
	bool GetIsOnLift() { return _isOnLift; }
	void SetIsOnLift(bool isOn) { _isOnLift = isOn; }
	bool GetIsLiftMovingUp() { return _isLiftMovingUp; }
	void SetIsLiftMovingUp(bool isMoving) { _isLiftMovingUp = isMoving; }
};