#pragma once
#include "gameNode.h"
#include "Map.h"
#include "Erik.h"
#include "Olaf.h"
#include "Baleog.h"

#include "CharacterManager.h"
#include "UI.h"
#include "Item.h"

using namespace std;

class playGround : public gameNode
{
private:
	Map* map;
	CharacterManager* cm;
	UI* ui;
	Item* item;

public:
	playGround();
	~playGround();


	virtual HRESULT Init() override;	
};

