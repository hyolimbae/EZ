#pragma once
#include "Item.h"
#include "Character.h"

class Meat : public Item
{
private:
	Character* character;

public:
	Meat() {};
	~Meat() {};
	virtual HRESULT Init() override;
	virtual void Update() override;
};