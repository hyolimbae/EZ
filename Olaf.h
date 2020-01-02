#pragma once
#include "Character.h"

class Olaf : public Character
{

public:

	Olaf();
	~Olaf();

	virtual HRESULT Init() override;
};

