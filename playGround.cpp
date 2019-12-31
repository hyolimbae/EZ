#include "stdafx.h"
#include "playGround.h"
#include "Erik.h"
#include "Olaf.h"
#include "Baleog.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::Init()
{
	gameNode::Init(true);

	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	IMAGEMANAGER->AddFrameImage("Erik_Idle", L"Image/Erik_Sprite/Erik_idle_02.png", 2, 1, false);
	IMAGEMANAGER->AddFrameImage("Erik_Run", L"Image/Erik_Sprite/Erik_Run.png", 8, 1, false);
	IMAGEMANAGER->AddFrameImage("Erik_Jump", L"Image/Erik_Sprite/Erik_jump.png", 4, 1, false);
	IMAGEMANAGER->AddFrameImage("Erik_Hit", L"Image/Erik_Sprite/Erik_hit.png", 1, 1, false);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	IMAGEMANAGER->AddFrameImage("Olaf_Idle", L"Image/Olaf_sprite/Olaf_Idle1.png", 1, 1, false);
	IMAGEMANAGER->AddFrameImage("Olaf_Run", L"Image/Olaf_sprite/Oalf_Run.png", 8, 1, false);
	IMAGEMANAGER->AddFrameImage("Olaf_Hit", L"Image/Olaf_sprite/Olaf_Hit.png", 1, 1, false);
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	IMAGEMANAGER->AddFrameImage("Baleog_Idle", L"Image/Baleog_sprite/Baleog_Idle.png", 2, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Run", L"Image/Baleog_sprite/Baleog_Walk.png", 8, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Hit", L"Image/Baleog_sprite/Baleog_Hit.png", 1, 1, false);

	IMAGEMANAGER->AddFrameImage("Baleog_Climb_up", L"Image/Baleog_sprite/Baleog_Climb_up.png", 4, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_After_Climb", L"Image/Baleog_sprite/Baleog_After_Climb.png", 2, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Falldown", L"Image/Baleog_sprite/Baleog_Falldown.png", 2, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Teleport", L"Image/Baleog_sprite/Baleog_Teleport.png", 2, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Knife_down", L"Image/Baleog_sprite/Baleog_Knife_down.png", 4, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Knife_up", L"Image/Baleog_sprite/Baleog_Knife_up.png", 4, 1, false);
	IMAGEMANAGER->AddImage("Baleog_arrow", L"Image/Baleog_sprite/Baleog_arrow.png", false);
	IMAGEMANAGER->AddFrameImage("baleog_broken_arrow_right", L"Image/Baleog_sprite/baleog_broken_arrow_right.png", 3, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Electric_shock_main", L"Image/Baleog_sprite/Baleog_Electric_shock_main.png", 2, 1, false);
	IMAGEMANAGER->AddFrameImage("Baleog_Shoot_arrow", L"Image/Baleog_sprite/Baleog_Shoot_arrow.png", 8, 1, false);

	//테스트용 ground (나중에 지워줘야해요
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	auto _ground = (GameObject*) new Obstacle;
	_ground->SetName("ground");
	_ground->Init();
	_ground->GetTransform()->SetSize(Vector2(WINSIZEX, 100));
	_ground->GetTransform()->SetPosition(Vector2(WINSIZEX / 2, WINSIZEY));
	AddChild(_ground);
	_ground->GetPhysics()->SetBodyType(b2_staticBody);
	_ground->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_ground,
		_ground->GetTransform()->GetSize().x,
		_ground->GetTransform()->GetSize().y));
	//Test용 Erik이에요
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	auto _erik = (GameObject*) new Erik();
	_erik->SetTag("Character");
	_erik->SetName("Erik");
	_erik->Init();
	_erik->GetTransform()->SetSize(Vector2(70, 70));
	_erik->GetTransform()->SetPosition(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	_erik->GetPhysics()->SetBodyType(b2_dynamicBody);
	_erik->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_erik));
	_erik->GetPhysics()->SetVelocity(Vector2(0.f, 0.f));
	_erik->GetPhysics()->SetShapeType(BOX);
	b2Shape* erikShape = PHYSICSMANAGER->CreateShape(_erik->GetPhysics()->GetBody(),
		_erik->GetTransform()->GetSize().x,
		_erik->GetTransform()->GetSize().y);
	_erik->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_erik->GetPhysics()->GetBody(), erikShape));
	_erik->GetPhysics()->SetCategoryBit(0x0002);
	AddChild(_erik);
	//Test용 Olaf에요
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	auto _olaf = (GameObject*) new Olaf();
	_olaf->SetTag("Character");
	_olaf->SetName("Olaf");
	_olaf->Init();
	_olaf->GetTransform()->SetSize(Vector2(70, 70));
	_olaf->GetTransform()->SetPosition(Vector2(WINSIZEX / 2 + 100, WINSIZEY / 2));
	_olaf->GetPhysics()->SetBodyType(b2_dynamicBody);
	_olaf->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_olaf));
	_olaf->GetPhysics()->SetVelocity(Vector2(0.f, 0.f));
	_olaf->GetPhysics()->SetShapeType(BOX);
	b2Shape* olafShape = PHYSICSMANAGER->CreateShape(_olaf->GetPhysics()->GetBody(),
		_olaf->GetTransform()->GetSize().x,
		_olaf->GetTransform()->GetSize().y);
	_olaf->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_olaf->GetPhysics()->GetBody(), olafShape));
	_olaf->GetPhysics()->SetCategoryBit(0x0004);
	AddChild(_olaf);
	//Test용 Baleog에요
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	auto _baleog = (GameObject*) new Baleog();
	_baleog->SetTag("Character");
	_baleog->SetName("Baleog");
	_baleog->Init();
	_baleog->GetTransform()->SetSize(Vector2(70, 70));
	_baleog->GetTransform()->SetPosition(Vector2(WINSIZEX / 2 + 200, WINSIZEY / 2));
	_baleog->GetPhysics()->SetBodyType(b2_dynamicBody);
	_baleog->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_baleog));
	_baleog->GetPhysics()->SetVelocity(Vector2(0.f, 0.f));
	_baleog->GetPhysics()->SetShapeType(BOX);
	b2Shape* baleogShape = PHYSICSMANAGER->CreateShape(_baleog->GetPhysics()->GetBody(),
		_baleog->GetTransform()->GetSize().x,
		_baleog->GetTransform()->GetSize().y);
	_baleog->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_baleog->GetPhysics()->GetBody(), baleogShape));
	_baleog->GetPhysics()->SetCategoryBit(0x0006);
	AddChild(_baleog);
	//충돌예외 처리
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	PHYSICSMANAGER->IgnoreCollision(_olaf, _erik);
	PHYSICSMANAGER->IgnoreCollision(_olaf, _baleog);
	PHYSICSMANAGER->IgnoreCollision(_baleog, _erik);

	return S_OK;
}

