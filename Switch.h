#pragma once
#include "GameObject.h"
#include "ElectricRod.h"

class Switch: public GameObject
{
private:
	bool _inArea = false;
	ElectricRod* rod;

public:
	Switch();
	~Switch();

	virtual HRESULT Init() override;
	virtual void Update() override;
};

