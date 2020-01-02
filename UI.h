#pragma once
#include "GameObject.h"

using namespace std;

class CharacterManager;

class UI: public GameObject
{
private:

	string characterUIstate;
	CharacterManager* _cm;
	

public:
	UI();
	~UI();

	virtual void Render() override;

	void SetLink(CharacterManager* cm)
	{
		_cm = cm;
	}

	Vector2 GetPosByName(string name);
};


