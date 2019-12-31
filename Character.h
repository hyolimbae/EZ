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

public:
	Character() { _physics = new Physics(); }

	virtual HRESULT Init() override;
	virtual void Release() override;
	virtual void Update() override;
	//virtual void Render() override;
	//GameObject���� Render���ְ��־ �ʿ�����ϴ�.

	void ChangeState(State* state);
	void SetOnGround();
	void GetOnGround();
	//============= GETTER ====================
	ATKType GetATKType() { return _atkType; }

	//============= SETTER ====================
	void SetATKType(ATKType type) { _atkType = type; }
};

