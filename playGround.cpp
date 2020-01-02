#include "stdafx.h"
#include "playGround.h"


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

#pragma region AddImage

	//IMAGE - UI 
	IMAGEMANAGER->AddImage("UI", L"Image/UI/UI_background.png");
	IMAGEMANAGER->AddImage("hp", L"Image/UI/hp.png");
	IMAGEMANAGER->AddImage("select", L"Image/UI/select.png");
	IMAGEMANAGER->AddImage("BaleogActive", L"Image/UI/BaleogActive.png");
	IMAGEMANAGER->AddImage("BaleogDead", L"Image/UI/BaleogDead.png");
	IMAGEMANAGER->AddImage("BaleogDefault", L"Image/UI/BaleogDefault.png");
	IMAGEMANAGER->AddImage("ErikActive", L"Image/UI/ErikActive.png");
	IMAGEMANAGER->AddImage("ErikDead", L"Image/UI/ErikDead.png");
	IMAGEMANAGER->AddImage("ErikDefault", L"Image/UI/ErikDefault.png");
	IMAGEMANAGER->AddImage("OlafActive", L"Image/UI/OlafActive.png");
	IMAGEMANAGER->AddImage("OlafDead", L"Image/UI/OlafDead.png");
	IMAGEMANAGER->AddImage("OlafDefault", L"Image/UI/OlafDefault.png");


	//IMAGE - MAP 
	IMAGEMANAGER->AddFrameImage("Grinder", L"Grinder.png", 3, 1);
	IMAGEMANAGER->AddFrameImage("ElectricBox", L"ElectricBox.png", 6, 1);
	IMAGEMANAGER->AddFrameImage("ElectricRod", L"ElectricRod.png", 3, 1);
	IMAGEMANAGER->AddFrameImage("BrokenWall_Frame", L"wallBroken.png", 13, 1);
	IMAGEMANAGER->AddImage("BrokenWallStart", L"wallBroken_1.png");
	IMAGEMANAGER->AddImage("BrokenWallEnd", L"wallBroken_2.png");
	IMAGEMANAGER->AddImage("KeyHole", L"Keyhole.png");
	IMAGEMANAGER->AddImage("ElectricRodEnd", L"ElectricRod_End.png");
	IMAGEMANAGER->AddImage("Background", L"Background.png");
	IMAGEMANAGER->AddImage("Lift", L"Lift.png");
	IMAGEMANAGER->AddImage("DoorTop", L"DoorTop.png");
	IMAGEMANAGER->AddImage("DoorBottom", L"DoorBottom.png");
	IMAGEMANAGER->AddImage("Background", L"Image/Background.png");
	IMAGEMANAGER->AddImage("Wall_z1", L"Image/wall_z1.png");
	IMAGEMANAGER->AddImage("Wall_z2", L"Image/wall_z2.png");
	IMAGEMANAGER->AddImage("Wall_z3", L"Image/wall_z3.png");


	//IMAGE - CHARACTER
	IMAGEMANAGER->AddFrameImage("Erik_Grinder", L"Image/Erik_Grinder2.png", 9, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Electric", L"Image/Erik_Electric.png", 2, 1);


	IMAGEMANAGER->AddFrameImage("Erik_Idle", L"Image/Erik_Sprite/Erik_idle_02.png", 2, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Run", L"Image/Erik_Sprite/Erik_Run.png", 8, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Jump", L"Image/Erik_Sprite/Erik_jump.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Hit", L"Image/Erik_Sprite/Erik_hit.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("Olaf_Idle", L"Image/Olaf_sprite/Olaf_Idle1.png", 1, 1, false);
	IMAGEMANAGER->AddFrameImage("Olaf_Run", L"Image/Olaf_sprite/Oalf_Run.png", 8, 1, false);
	IMAGEMANAGER->AddFrameImage("Olaf_Hit", L"Image/Olaf_sprite/Olaf_Hit.png", 1, 1, false);
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
#pragma endregion 
	

	//LEFT_TOP
	//CAMERAMANAGER->SetPosition(Vector2((-1)*BACKGROUND_WIDTH/2+WINSIZEX/2, (-1)*BACKGROUND_HEIGHT/2+WINSIZEY/2));

	//map init 
	map = new Map();
	map->Init();



	cm = new CharacterManager();


	//character test inint 
	auto _erik = new Erik();
	_erik->SetTag("Character");
	_erik->SetName("Erik");
	_erik->Init();
	_erik->GetTransform()->SetSize(Vector2(26, 33));
	_erik->GetTransform()->SetScale(2.5f);
	_erik->GetTransform()->SetPosition(Hyolim_LeftTop(	Vector2(555, 100),
														_erik->GetTransform()->GetSize().x,
														_erik->GetTransform()->GetSize().y));
	_erik->SetDeltaTime(0.7);


	_erik->GetPhysics()->SetBodyType(b2_dynamicBody);
	_erik->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_erik));
	_erik->GetPhysics()->SetVelocity(Vector2(0.f, 0.f));
	_erik->GetPhysics()->SetShapeType(BOX);
	b2Shape* erikShape = PHYSICSMANAGER->CreateShape(	_erik->GetPhysics()->GetBody(),true);
	_erik->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_erik->GetPhysics()->GetBody(), erikShape));
	_erik->GetPhysics()->SetCategoryBit(0x0002);
	AddChild(_erik);


	auto _olaf = new Olaf();
	_olaf->SetTag("Character");
	_olaf->SetName("Olaf");
	_olaf->Init();
	_olaf->GetTransform()->SetSize(Vector2(26, 33));
	_olaf->GetTransform()->SetScale(2.5f);
	_olaf->GetTransform()->SetPosition(Hyolim_LeftTop(	Vector2(1833, 1066),
														_olaf->GetTransform()->GetSize().x*BACKGROUND_SCALE,
														_olaf->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_olaf->GetPhysics()->SetBodyType(b2_dynamicBody);
	_olaf->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_olaf));
	_olaf->GetPhysics()->SetVelocity(Vector2(0.f, 0.f));
	_olaf->GetPhysics()->SetShapeType(BOX);

	b2Shape* olafShape = PHYSICSMANAGER->CreateShape(_olaf->GetPhysics()->GetBody(),true);

	_olaf->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_olaf->GetPhysics()->GetBody(), olafShape));
	_olaf->GetPhysics()->SetCategoryBit(0x0004);
	AddChild(_olaf);


	auto _baleog =  new Baleog();
	_baleog->SetTag("Character");
	_baleog->SetName("Baleog");
	_baleog->Init();
	_baleog->GetTransform()->SetSize(Vector2(26, 33));
	_baleog->GetTransform()->SetScale(2.5);
	_baleog->GetTransform()->SetPosition(Hyolim_LeftTop(	Vector2(2535, 1731),
															_baleog->GetTransform()->GetSize().x*BACKGROUND_SCALE,
															_baleog->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_baleog->GetPhysics()->SetBodyType(b2_dynamicBody);
	_baleog->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_baleog));
	_baleog->GetPhysics()->SetVelocity(Vector2(0.f, 0.f));
	_baleog->GetPhysics()->SetShapeType(BOX);
	b2Shape* baleogShape = PHYSICSMANAGER->CreateShape(	_baleog->GetPhysics()->GetBody(),true);
	_baleog->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_baleog->GetPhysics()->GetBody(), baleogShape));
	_baleog->GetPhysics()->SetCategoryBit(0x0006);
	AddChild(_baleog);



	cm->AddCharacter(_erik);
	cm->AddCharacter(_baleog);
	cm->AddCharacter(_olaf);
	AddChild(cm);


	ui = new UI();
	AddChild(ui);
	ui->SetZOrder(10);
	ui->SetIsUI(true);
	ui->SetLink(cm);
	
	PHYSICSMANAGER->IgnoreCollision(_olaf,   _erik);
	PHYSICSMANAGER->IgnoreCollision(_olaf,   _baleog);
	PHYSICSMANAGER->IgnoreCollision(_baleog, _erik);
	
	

	return S_OK;
}


