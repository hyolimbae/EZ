#pragma once
#include "GameObject.h"
#include <list>



class Olaf;
class Erik;
class Baleog;

class Key;
class Meat;
class Tomato;
class Shoes;

class CharacterManager;

class Item : public GameObject
{
protected:
	CharacterManager* _cm;

public:
	Item() 
	{ 
		_physics = new Physics(); 
	}
	~Item() {}

	virtual HRESULT Init() override;
	virtual void Update() override;

	void SetLink(CharacterManager* cm)
	{
		_cm = cm;
	}
};