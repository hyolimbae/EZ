#pragma once
#include "GameObject.h"
#include "State.h"

class State;

enum ATKType
{
	KNIFE_ATTACK,
	ARROW
};

class Character : public GameObject
{
private:
	State* _state;
	bool _onGround;
	ATKType _atkType;
	int _hp =3;

public:
	Character() { _physics = new Physics(); }

	virtual HRESULT Init() override;
	virtual void Release() override;
	virtual void Update() override;

	void ChangeState(State* state);
	void SetOnGround();
	void GetOnGround();
	//============= GETTER ====================
	ATKType GetATKType() { return _atkType; }
	int GetHP() { return _hp; }

	//============= SETTER ====================
	void SetATKType(ATKType type) { _atkType = type; }
	void SetHP(int hp) { _hp = hp; }
};

