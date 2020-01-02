#pragma once
#include "gameNode.h"
#include "Map.h"
#include "Erik.h"
#include "Olaf.h"
#include "Baleog.h"

#include "CharacterManager.h"
#include "UI.h"

using namespace std;

class playGround : public gameNode
{
private:
	Map* map;
	CharacterManager* cm;
	UI* ui;

public:
	playGround();
	~playGround();


	virtual HRESULT Init() override;	
};

