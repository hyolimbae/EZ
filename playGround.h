#pragma once
#include "gameNode.h"


using namespace std;

class playGround : public gameNode
{
public:
	playGround();
	~playGround();

	virtual HRESULT Init() override;		


};

