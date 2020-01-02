#pragma once
#include "Item.h"

class Tomato : public Item
{
private:

public:
	Tomato() {};
	~Tomato() {};
	virtual HRESULT Init() override;
	virtual void Update() override;
};

