#pragma once
#include "GameObject.h"

class Character : public GameObject
{
private:
	int _hp = 3;

public:
	Character();
	~Character();

	virtual HRESULT Init() override;
	virtual void Update() override;

	int getHP() { return _hp; }
	void setHP(int hp) { _hp = hp; }


	
};

