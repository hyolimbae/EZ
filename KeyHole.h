#pragma once
#include "GameObject.h"


class KeyHole: public GameObject
{
private:
	bool _inArea = false;

public:
	KeyHole();
	~KeyHole();

	virtual HRESULT Init() override;
	virtual void Update() override;
	
};

