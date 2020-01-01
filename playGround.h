#pragma once
#include "gameNode.h"
#include "Map.h"
#include "Erik.h"
#include "Olaf.h"
#include "Baleog.h"

using namespace std;

class playGround : public gameNode
{
private:
	Map* map;

public:
	playGround();
	~playGround();


	virtual HRESULT Init() override;	
};

