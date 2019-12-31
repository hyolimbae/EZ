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

	//IMAGE - OBSTACLE
	IMAGEMANAGER->AddFrameImage("Grinder", L"Image/Grinder.png", 3, 1);
	IMAGEMANAGER->AddFrameImage("ElectricBox", L"Image/ElectricBox.png", 6, 1);
	IMAGEMANAGER->AddFrameImage("ElectricRod", L"Image/ElectricRod.png", 3, 1);
	IMAGEMANAGER->AddFrameImage("BrokenWall_Frame", L"Image/wallBroken.png", 13, 1);
	IMAGEMANAGER->AddImage("BrokenWallStart", L"Image/wallBroken_1.png");
	IMAGEMANAGER->AddImage("BrokenWallEnd", L"Image/wallBroken_2.png");
	IMAGEMANAGER->AddImage("KeyHole", L"Image/Keyhole.png");
	IMAGEMANAGER->AddImage("ElectricRodEnd", L"Image/ElectricRod_End.png");
	
	//IMAGE - ERIC 
	IMAGEMANAGER->AddFrameImage("Erik_Idle", L"Image/Erik_idle_02.png", 2, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Grinder", L"Image/Erik_Grinder2.png", 9, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Electric", L"Image/Erik_Electric.png", 2, 1);

	//IMAGE - ETC
	IMAGEMANAGER->AddImage("Background", L"Image/Background.png");
	IMAGEMANAGER->AddImage("Wall_z1", L"Image/wall_z1.png");
	IMAGEMANAGER->AddImage("Wall_z2", L"Image/wall_z2.png");
	IMAGEMANAGER->AddImage("Wall_z3", L"Image/wall_z3.png");

	MakeZWall("Wall_z1", Vector2(756-50, 92), 50, 352);


	auto _background = new GameObject();
	_background->SetSprite(IMAGEMANAGER->FindImage("Background"));
	_background->GetTransform()->SetSize(Vector2(4032,2000));
	_background->GetTransform()->SetPosition(Vector2(0,0));
	_background->GetTransform()->SetScale(BACKGROUND_SCALE);

	AddChild(_background);

	//LEFT_TOP
	CAMERAMANAGER->SetPosition(Vector2((-1)*BACKGROUND_WIDTH/2+WINSIZEX/2, (-1)*BACKGROUND_HEIGHT/2+WINSIZEY/2));
	//CAMERAMANAGER->SetPosition(Vector2(1000,0));


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
	//MakeZWall("Wall_z1", Vector2(756, 92), 50, 352);
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

	

	return S_OK;
}


