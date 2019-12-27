#pragma once
#include "GameObject.h"

#define MAXJUMP 2
#define PLAYERSPEED 5.0f
#define PLAYERJUMPPOWER 5.0f

enum PLAYERSTATE
{
	IDLE,
	ISJUMP
};

class Player : GameObject
{
private:
	int _jumpCount;
	float _jumpPower;
	int _hp;
	bool _isActive;

	PLAYERSTATE _state;
	Vector2 _position;

	RECT _gaugeFront;
	RECT _gaugeBack;

public:
	Player();
	~Player();

	virtual HRESULT Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void KeyControl();
	void StateControl();

	//SETTER
	void SetHP(int hp) 
	{
		if (hp < 0) _hp = 0;
		else
		{
			_hp = hp;
		}
	}
	void SetState(PLAYERSTATE state) { _state = state; }
	void SetIsActive(bool isActive) { _isActive = isActive; }

	//GETTER
	int GetHP() { return _hp; }
	bool GetIsActive() { return _isActive; }

};

