#pragma once
#include "Grinder.h"
#include "ElectricBox.h"
#include "ElectricRod.h"
#include "BrokenWall.h"
#include "Ground.h"
#include "KeyHole.h"
#include "Switch.h"
#include "Exit.h"
#include "Lift.h"
#include "Door.h"
#include "GravityZone.h"
#include "Teleport.h"
#include "Ladder.h"

class Map : public GameObject
{
private:

public:
	Map();
	~Map();

	virtual HRESULT Init() override;

	void MakeGround(Vector2 pos, float width, float height);
	void MakeZWall(string sprite, Vector2 pos, float width, float height);


};

