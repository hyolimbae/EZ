#pragma once
#include "GameObject.h"
#include "Character.h"

class ElectricRod: public GameObject
{
private:
	float _timer = 0;
	Character* character;
	bool _isActive = true;

public:
	ElectricRod();
	~ElectricRod();

	virtual HRESULT Init() override;
	virtual void Update() override;

	void setActive(bool active) { _isActive = active; }
};

