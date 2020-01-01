#pragma once
#include "gameNode.h"
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


using namespace std;

class playGround : public gameNode
{
private:

public:
	playGround();
	~playGround();


	virtual HRESULT Init() override;	


	//Æ÷Åä¼¥ ÁÂÇ¥ -> °ÔÀÓ ÁÂÇ¥
	Vector2 Hyolim_Center(Vector2 vec)
	{
		Vector2 temp;
		temp.x = (vec.x)*BACKGROUND_SCALE - BACKGROUND_WIDTH / 2;
		temp.y = (vec.y)*BACKGROUND_SCALE - BACKGROUND_HEIGHT / 2;
		return temp;
	}

	static Vector2 Hyolim_LeftTop(Vector2 vec, float width, float height)
	{
		Vector2 temp;
		temp.x = (vec.x) * BACKGROUND_SCALE + width /  2  - BACKGROUND_WIDTH / 2;
		temp.y = (vec.y) * BACKGROUND_SCALE + height / 2 - BACKGROUND_HEIGHT / 2;
		return temp;
	}

	void MakeGround(Vector2 pos, float width, float height)
	{
		auto _ground = (GameObject*)new Ground();
		_ground->SetTag("Ground");
		_ground->GetTransform()->SetSize(Vector2(width, height));
		_ground->GetTransform()->SetPosition(Hyolim_LeftTop(pos,
			_ground->GetTransform()->GetSize().x*BACKGROUND_SCALE,
			_ground->GetTransform()->GetSize().y*BACKGROUND_SCALE));

		AddChild(_ground);
		_ground->GetPhysics()->SetBodyType(b2_staticBody);
		_ground->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_ground,
			_ground->GetTransform()->GetSize().x*BACKGROUND_SCALE,
			_ground->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	}

	void MakeZWall(string sprite, Vector2 pos, float width, float height)
	{
		auto _zWall = new GameObject();
		_zWall->SetTag("zWall");
		_zWall->SetSprite(IMAGEMANAGER->FindImage(sprite));
		_zWall->GetTransform()->SetScale(BACKGROUND_SCALE);
		_zWall->GetTransform()->SetSize(Vector2(width, height));
		_zWall->GetTransform()->SetPosition(Hyolim_LeftTop(pos,
			_zWall->GetTransform()->GetSize().x*BACKGROUND_SCALE,
			_zWall->GetTransform()->GetSize().y*BACKGROUND_SCALE));

		_zWall->SetZOrder(5);
		AddChild(_zWall);
	}

};

