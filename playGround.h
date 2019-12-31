#pragma once
#include "gameNode.h"

#include "Character.h"
#include "Obstacle.h"

#include <string>

using namespace std;

class playGround : public gameNode
{
private:

public:
	playGround();
	~playGround();

	virtual HRESULT Init() override;	


};

