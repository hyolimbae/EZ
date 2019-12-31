#pragma once
#include "GameObject.h"
#include "Character.h"
#include <list>

class Ladder : public GameObject
{
private:
	Character* character;

	list<Character*> _lCharacterAtLadder1;
	list<Character*> _lCharacterAtLadder2;
	list<Character*> _lCharacterAtLadder3;
	list<Character*> _lCharacterAtLadder4;

public:
	Ladder() { _physics = new Physics(); };
	~Ladder() {};

	virtual HRESULT Init() override;
	virtual void Update() override;

	void ClimbingLadder1();
	void ClimbingLadder2();
	void ClimbingLadder3();
	void ClimbingLadder4();
};