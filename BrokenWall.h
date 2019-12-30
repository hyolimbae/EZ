#pragma once
#include "gameObject.h"
#include "Character.h"
class BrokenWall : public GameObject
{
private:
	Character* character;

	float _timer;

public:
	BrokenWall();
	~BrokenWall();

	virtual HRESULT Init() override;
	virtual void Update() override;

};

