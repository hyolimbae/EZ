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

	//IMAGE - ITEM (나중에 생성자 쪽으로 옮길까?
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
	
	//IMAGE - ERIC 
	IMAGEMANAGER->AddFrameImage("Erik_Idle", L"Image/Erik_idle_02.png", 2, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Grinder", L"Image/Erik_Grinder2.png", 9, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Electric", L"Image/Erik_Electric.png", 2, 1);

	//IMAGE - ETC
	IMAGEMANAGER->AddImage("Background", L"Image/Background.png");
	IMAGEMANAGER->AddImage("Wall_z1", L"Image/wall_z1.png");
	IMAGEMANAGER->AddImage("Wall_z2", L"Image/wall_z2.png");
	IMAGEMANAGER->AddImage("Wall_z3", L"Image/wall_z3.png");

	/*IMAGEMANAGER->AddFrameImage("Erik_Idle", L"Image/Erik_Sprite/Erik_idle_02.png", 2, 1);
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
	IMAGEMANAGER->AddFrameImage("Baleog_Shoot_arrow", L"Image/Baleog_sprite/Baleog_Shoot_arrow.png", 8, 1, false);*/


	auto _background = new GameObject();
	_background->SetSprite(IMAGEMANAGER->FindImage("Background"));
	_background->GetTransform()->SetSize(Vector2(4032,2000));
	_background->GetTransform()->SetPosition(Vector2(0,0));
	_background->GetTransform()->SetScale(BACKGROUND_SCALE);

	AddChild(_background);

	//LEFT_TOP
	CAMERAMANAGER->SetPosition(Vector2((-1)*BACKGROUND_WIDTH/2+WINSIZEX/2, (-1)*BACKGROUND_HEIGHT/2+WINSIZEY/2));


	//GROUND
	MakeGround(Vector2(0, 444), 4032,20);
	MakeGround(Vector2(1007, 1859), 1865,20);
	MakeGround(Vector2(50, 1452), 607,20);
	MakeGround(Vector2(2975, 1859), 604,20);
	MakeGround(Vector2(2975, 1200), 100,100);
	MakeGround(Vector2(2672, 1200), 200,100);
	MakeGround(Vector2(1160, 1200), 150,50);
	MakeGround(Vector2(1008, 1200), 50,50);
	MakeGround(Vector2(153, 1859), 200,20);
	MakeGround(Vector2(1562, 1200), 504,100);
	MakeGround(Vector2(2168, 1200), 200,100);
	MakeGround(Vector2(3429, 1403), 604,100);
	MakeGround(Vector2(1311, 1552), 1363,102);
	MakeGround(Vector2(3779, 1856), 203,20);

	//WALL 
	MakeGround(Vector2(3325-20, 948), 20, 706);
	MakeGround(Vector2(3075, 948), 20, 706);
	MakeGround(Vector2(49-20, 1151), 20, 304);
	MakeGround(Vector2(656, 1150), 20, 304);
	MakeGround(Vector2(102+52, 1654), 20, 205);
	MakeGround(Vector2(353, 1654), 20, 205);
	MakeGround(Vector2(27, 38), 20, 409);
	MakeGround(Vector2(1006-20, 948), 20, 708);
	MakeGround(Vector2(1260, 1250), 50, 404);
	MakeGround(Vector2(2672, 1300), 50, 355);
	MakeGround(Vector2(3730, 0), 100, 292);
	MakeGround(Vector2(3680, 948), 100, 303);
	MakeGround(Vector2(3024, 1655), 301, 50);
	MakeGround(Vector2(4027, 948), 5, 454);
	MakeGround(Vector2(4027, 40), 5, 406);
	MakeGround(Vector2(3982, 1503), 20, 354);
	MakeGround(Vector2(1210, 92), 50, 150);
	MakeGround(Vector2(1360, 92), 50, 150);

	//Z-WALL
	MakeZWall("Wall_z1", Vector2(756, 92), 50, 352);
	MakeZWall("Wall_z2", Vector2(1664, 1300), 50, 252);
	MakeZWall("Wall_z2", Vector2(2218, 1300), 50, 252);
	MakeZWall("Wall_z3", Vector2(1260, 1654), 50, 202);
	MakeZWall("Wall_z3", Vector2(1764, 1654), 50, 202);
	MakeZWall("Wall_z3", Vector2(2218, 1654), 50, 202);
	MakeZWall("Wall_z3", Vector2(2672, 1654), 50, 202);



	//SWITCH
	auto _switch1 = (GameObject*) new Switch();
	_switch1->SetTag("Switch");
	_switch1->SetName("Switch1");
	_switch1->GetTransform()->SetSize(Vector2(44, 42));
	_switch1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3024,1552),
		_switch1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_switch1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_switch1);
	_switch1->GetPhysics()->SetBodyType(b2_staticBody);
	_switch1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_switch1,
		_switch1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_switch1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _switch2 = (GameObject*) new Switch();
	_switch2->SetTag("Switch");
	_switch2->SetName("Switch2");
	_switch2->GetTransform()->SetSize(Vector2(44, 44));
	_switch2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3680, 344),
		_switch2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_switch2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_switch2);
	_switch2->GetPhysics()->SetBodyType(b2_staticBody);
	_switch2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_switch2,
		_switch2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_switch2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	//Electric Box
	auto _eBox1 = (GameObject*) new ElectricBox();
	_eBox1->SetTag("ElectricBox");
	_eBox1->GetTransform()->SetSize(Vector2(102, 50));
	_eBox1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(2873, 1906),
		_eBox1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eBox1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_eBox1);
	_eBox1->GetPhysics()->SetBodyType(b2_staticBody);
	_eBox1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_eBox1,
		_eBox1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eBox1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _eBox2 = (GameObject*) new ElectricBox();
	_eBox2->SetTag("ElectricBox");
	_eBox2->GetTransform()->SetSize(Vector2(402, 47));
	_eBox2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(809, 40),
		_eBox2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eBox2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_eBox2);
	_eBox2->GetPhysics()->SetBodyType(b2_staticBody);
	_eBox2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_eBox2,
		_eBox2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eBox2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _eBox3 = (GameObject*) new ElectricBox();
	_eBox3->SetTag("ElectricBox");
	_eBox3->GetTransform()->SetSize(Vector2(2066, 47));
	_eBox3->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(1412, 40),
		_eBox3->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eBox3->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_eBox3);
	_eBox3->GetPhysics()->SetBodyType(b2_staticBody);
	_eBox3->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_eBox3,
		_eBox3->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eBox3->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	//Electric Rod
	auto _eRod = (GameObject*) new ElectricRod();
	_eRod->SetTag("ElectricBox");
	_eRod->GetTransform()->SetSize(Vector2(202, 50));
	_eRod->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(2822, 1352),
		_eRod->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eRod->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_eRod);
	_eRod->GetPhysics()->SetBodyType(b2_staticBody);
	_eRod->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_eRod,
		_eRod->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_eRod->GetTransform()->GetSize().y*BACKGROUND_SCALE/3));


	//Grinder
	auto _grinder = (GameObject*) new Grinder();
	_grinder->SetTag("Grinder");
	_grinder->SetSprite(IMAGEMANAGER->FindImage("Grinder"));
	_grinder->GetTransform()->SetScale(BACKGROUND_SCALE);
	_grinder->GetTransform()->SetSize(Vector2(201, 48));
	_grinder->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3578, 1856),
		_grinder->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_grinder->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_grinder);
	_grinder->GetPhysics()->SetBodyType(b2_staticBody);
	_grinder->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_grinder,
		_grinder->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_grinder->GetTransform()->GetSize().y*BACKGROUND_SCALE / 3));

	//Exit
	auto _exit = (GameObject*) new Grinder();
	_exit->SetTag("Exit");
	_exit->GetTransform()->SetSize(Vector2(204, 201));
	_exit->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3829,243),
		_exit->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_exit->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	AddChild(_exit);
	_exit->GetPhysics()->SetBodyType(b2_staticBody);
	_exit->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_exit,
		_exit->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_exit->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	//KeyHole
	auto _keyHole = (GameObject*) new KeyHole();
	_keyHole->SetTag("KeyHole");
	_keyHole->GetTransform()->SetScale(BACKGROUND_SCALE);
	_keyHole->GetTransform()->SetSize(Vector2(46, 47));
	_keyHole->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3628, 1300),
		_keyHole->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_keyHole->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	_keyHole->SetSprite(IMAGEMANAGER->FindImage("KeyHole"));

	AddChild(_keyHole);
	_keyHole->GetPhysics()->SetBodyType(b2_staticBody);
	_keyHole->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_keyHole,
		_keyHole->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_keyHole->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	//Breaking Wall 
	auto _brokenWall = (GameObject*) new BrokenWall();
	_brokenWall->SetTag("BrokenWall");
	_brokenWall->GetTransform()->SetScale(BACKGROUND_SCALE);
	_brokenWall->GetTransform()->SetSize(Vector2(50, 201));
	_brokenWall->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(959, 1654),
		_brokenWall->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_brokenWall->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	_brokenWall->SetSprite(IMAGEMANAGER->FindImage("BrokenWallStart"));

	AddChild(_brokenWall);
	_brokenWall->GetPhysics()->SetBodyType(b2_staticBody);
	_brokenWall->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_brokenWall,
		_brokenWall->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_brokenWall->GetTransform()->GetSize().y*BACKGROUND_SCALE));


	//■■■■■■■■■■■■■■■■■■■■■■■■■ Lift
	auto _lift = (GameObject*) new Lift();
	_lift->SetTag("lift");
	_lift->SetName("lift");
	_lift->GetTransform()->SetScale(BACKGROUND_SCALE);
	_lift->GetTransform()->SetSize(Vector2(102, 102));
	_lift->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(2872, 1804),
		_lift->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_lift->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_lift->SetSprite(IMAGEMANAGER->FindImage("Lift"));
	AddChild(_lift);
	_lift->GetPhysics()->SetBodyType(b2_staticBody);
	_lift->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_lift,
		_lift->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_lift->GetTransform()->GetSize().y*BACKGROUND_SCALE));


	//■■■■■■■■■■■■■■■■■■■■■■■■■ Door
	auto _doorTop1 = (GameObject*) new Door();
	_doorTop1->SetTag("door1");
	_doorTop1->SetName("doorTop1");
	_doorTop1->GetTransform()->SetScale(BACKGROUND_SCALE);
	_doorTop1->GetTransform()->SetSize(Vector2(50, 76));
	_doorTop1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3704, 1250),
		_doorTop1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorTop1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_doorTop1->SetSprite(IMAGEMANAGER->FindImage("DoorTop"));
	AddChild(_doorTop1);
	_doorTop1->GetPhysics()->SetBodyType(b2_staticBody);
	_doorTop1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_doorTop1,
		_doorTop1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorTop1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _doorBottom1 = (GameObject*) new Door();
	_doorBottom1->SetTag("door1");
	_doorBottom1->SetName("doorBottom1");
	_doorBottom1->GetTransform()->SetScale(BACKGROUND_SCALE);
	_doorBottom1->GetTransform()->SetSize(Vector2(50, 76));
	_doorBottom1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3704, 1326),
		_doorBottom1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorBottom1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_doorBottom1->SetSprite(IMAGEMANAGER->FindImage("DoorBottom"));
	AddChild(_doorBottom1);
	_doorBottom1->GetPhysics()->SetBodyType(b2_staticBody);
	_doorBottom1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_doorBottom1,
		_doorBottom1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorBottom1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _doorSensor1 = (GameObject*) new Door();
	_doorSensor1->SetName("doorSensor1");
	_doorSensor1->GetTransform()->SetScale(BACKGROUND_SCALE);
	_doorSensor1->GetTransform()->SetSize(Vector2(210, 10));
	_doorSensor1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3627, 1392),
		_doorSensor1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorSensor1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_doorSensor1);
	_doorSensor1->GetPhysics()->SetBodyType(b2_staticBody);
	_doorSensor1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_doorSensor1,
		_doorSensor1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorSensor1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _doorTop2 = (GameObject*) new Door();
	_doorTop2->SetTag("door2");
	_doorTop2->SetName("doorTop2");
	_doorTop2->GetTransform()->SetScale(BACKGROUND_SCALE);
	_doorTop2->GetTransform()->SetSize(Vector2(50, 76));
	_doorTop2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3757, 295),
		_doorTop2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorTop2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_doorTop2->SetSprite(IMAGEMANAGER->FindImage("DoorTop"));
	AddChild(_doorTop2);
	_doorTop2->GetPhysics()->SetBodyType(b2_staticBody);
	_doorTop2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_doorTop2,
		_doorTop2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorTop2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _doorBottom2 = (GameObject*) new Door();
	_doorBottom2->SetTag("door2");
	_doorBottom2->SetName("doorBottom2");
	_doorBottom2->GetTransform()->SetScale(BACKGROUND_SCALE);
	_doorBottom2->GetTransform()->SetSize(Vector2(50, 76));
	_doorBottom2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3757, 371),
		_doorBottom2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorBottom2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	_doorBottom2->SetSprite(IMAGEMANAGER->FindImage("DoorBottom"));
	AddChild(_doorBottom2);
	_doorBottom2->GetPhysics()->SetBodyType(b2_staticBody);
	_doorBottom2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_doorBottom2,
		_doorBottom2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorBottom2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _doorSensor2 = (GameObject*) new Door();
	_doorSensor2->SetName("doorSensor2");
	_doorSensor2->GetTransform()->SetScale(BACKGROUND_SCALE);
	_doorSensor2->GetTransform()->SetSize(Vector2(210, 10));
	_doorSensor2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3680, 437),
		_doorSensor2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorSensor2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_doorSensor2);
	_doorSensor2->GetPhysics()->SetBodyType(b2_staticBody);
	_doorSensor2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_doorSensor2,
		_doorSensor2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_doorSensor2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	//■■■■■■■■■■■■■■■■■■■■■■■■■ gravityZone
	auto _gravityZone1 = (GameObject*) new GravityZone();
	_gravityZone1->SetTag("gravityZone");
	_gravityZone1->SetName("gravityZone1");
	_gravityZone1->GetTransform()->SetScale(BACKGROUND_SCALE);
	_gravityZone1->GetTransform()->SetSize(Vector2(372, 352));
	_gravityZone1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(822, 92),
		_gravityZone1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_gravityZone1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_gravityZone1);
	_gravityZone1->GetPhysics()->SetBodyType(b2_staticBody);
	_gravityZone1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_gravityZone1,
		_gravityZone1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_gravityZone1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _gravityZone2 = (GameObject*) new GravityZone();
	_gravityZone2->SetTag("gravityZone");
	_gravityZone2->SetName("gravityZone2");
	_gravityZone2->GetTransform()->SetScale(BACKGROUND_SCALE);
	_gravityZone2->GetTransform()->SetSize(Vector2(777, 352));
	_gravityZone2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(1427, 92),
		_gravityZone2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_gravityZone2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_gravityZone2);
	_gravityZone2->GetPhysics()->SetBodyType(b2_staticBody);
	_gravityZone2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_gravityZone2,
		_gravityZone2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_gravityZone2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _gravityZone3 = (GameObject*) new GravityZone();
	_gravityZone3->SetTag("gravityZone");
	_gravityZone3->SetName("gravityZone3");
	_gravityZone3->GetTransform()->SetScale(BACKGROUND_SCALE);
	_gravityZone3->GetTransform()->SetSize(Vector2(725, 352));
	_gravityZone3->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(2787, 92),
		_gravityZone3->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_gravityZone3->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_gravityZone3);
	_gravityZone3->GetPhysics()->SetBodyType(b2_staticBody);
	_gravityZone3->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_gravityZone3,
		_gravityZone3->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_gravityZone3->GetTransform()->GetSize().y*BACKGROUND_SCALE));


	//■■■■■■■■■■■■■■■■■■■■■■■■■ ladder
	auto _ladder1 = (GameObject*) new Ladder();
	_ladder1->SetTag("ladder");
	_ladder1->SetName("ladder1");
	_ladder1->GetTransform()->SetScale(BACKGROUND_SCALE);
	_ladder1->GetTransform()->SetSize(Vector2(86, 646));
	_ladder1->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(1064, 1210),
		_ladder1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder1->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_ladder1);
	_ladder1->GetPhysics()->SetBodyType(b2_staticBody);
	_ladder1->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_ladder1,
		_ladder1->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder1->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _ladder2 = (GameObject*) new Ladder();
	_ladder2->SetTag("ladder");
	_ladder2->SetName("ladder2");
	_ladder2->GetTransform()->SetScale(BACKGROUND_SCALE);
	_ladder2->GetTransform()->SetSize(Vector2(86, 342));
	_ladder2->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(2072, 1210),
		_ladder2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder2->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_ladder2);
	_ladder2->GetPhysics()->SetBodyType(b2_staticBody);
	_ladder2->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_ladder2,
		_ladder2->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder2->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _ladder3 = (GameObject*) new Ladder();
	_ladder3->SetTag("ladder");
	_ladder3->SetName("ladder3");
	_ladder3->GetTransform()->SetScale(BACKGROUND_SCALE);
	_ladder3->GetTransform()->SetSize(Vector2(86, 342));
	_ladder3->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(2576, 1210),
		_ladder3->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder3->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_ladder3);
	_ladder3->GetPhysics()->SetBodyType(b2_staticBody);
	_ladder3->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_ladder3,
		_ladder3->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder3->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _ladder4 = (GameObject*) new Ladder();
	_ladder4->SetTag("ladder");
	_ladder4->SetName("ladder4");
	_ladder4->GetTransform()->SetScale(BACKGROUND_SCALE);
	_ladder4->GetTransform()->SetSize(Vector2(86, 444));
	_ladder4->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3332, 1412),
		_ladder4->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder4->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_ladder4);
	_ladder4->GetPhysics()->SetBodyType(b2_staticBody);
	_ladder4->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_ladder4,
		_ladder4->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_ladder4->GetTransform()->GetSize().y*BACKGROUND_SCALE));


	//■■■■■■■■■■■■■■■■■■■■■■■■■ teleport
	auto _teleport1A = (GameObject*) new Teleport();
	_teleport1A->SetTag("teleport");
	_teleport1A->SetName("teleport1A");
	_teleport1A->GetTransform()->SetScale(BACKGROUND_SCALE);
	_teleport1A->GetTransform()->SetSize(Vector2(88, 100));
	_teleport1A->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(158, 344),
		_teleport1A->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport1A->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_teleport1A);
	_teleport1A->GetPhysics()->SetBodyType(b2_staticBody);
	_teleport1A->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_teleport1A,
		_teleport1A->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport1A->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _teleport1B = (GameObject*) new Teleport();
	_teleport1B->SetTag("teleport");
	_teleport1B->SetName("teleport1B");
	_teleport1B->GetTransform()->SetScale(BACKGROUND_SCALE);
	_teleport1B->GetTransform()->SetSize(Vector2(88, 100));
	_teleport1B->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(3938, 1301),
		_teleport1B->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport1B->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_teleport1B);
	_teleport1B->GetPhysics()->SetBodyType(b2_staticBody);
	_teleport1B->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_teleport1B,
		_teleport1B->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport1B->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _teleport2A = (GameObject*) new Teleport();
	_teleport2A->SetTag("teleport");
	_teleport2A->SetName("teleport2A");
	_teleport2A->GetTransform()->SetScale(BACKGROUND_SCALE);
	_teleport2A->GetTransform()->SetSize(Vector2(88, 100));
	_teleport2A->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(258, 1352),
		_teleport2A->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport2A->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_teleport2A);
	_teleport2A->GetPhysics()->SetBodyType(b2_staticBody);
	_teleport2A->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_teleport2A,
		_teleport2A->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport2A->GetTransform()->GetSize().y*BACKGROUND_SCALE));

	auto _teleport2B = (GameObject*) new Teleport();
	_teleport2B->SetTag("teleport");
	_teleport2B->SetName("teleport2B");
	_teleport2B->GetTransform()->SetScale(BACKGROUND_SCALE);
	_teleport2B->GetTransform()->SetSize(Vector2(88, 100));
	_teleport2B->GetTransform()->SetPosition(Hyolim_LeftTop(Vector2(208, 1754),
		_teleport2B->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport2B->GetTransform()->GetSize().y*BACKGROUND_SCALE));
	AddChild(_teleport2B);
	_teleport2B->GetPhysics()->SetBodyType(b2_staticBody);
	_teleport2B->GetPhysics()->SetBody(PHYSICSMANAGER->CreateDefaultBody(_teleport2B,
		_teleport2B->GetTransform()->GetSize().x*BACKGROUND_SCALE,
		_teleport2B->GetTransform()->GetSize().y*BACKGROUND_SCALE));



	/*
	민욱 + 은솔 테스트 코드 
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
	
	*/

	return S_OK;
}


