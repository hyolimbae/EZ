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
	
	//IMAGE - ERIC 
	IMAGEMANAGER->AddFrameImage("Erik_Idle", L"Erik_idle_02.png", 2, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Grinder", L"Erik_Grinder2.png", 9, 1);
	IMAGEMANAGER->AddFrameImage("Erik_Electric", L"Erik_Electric.png", 2, 1);

	auto _background = new GameObject();
	_background->SetSprite(IMAGEMANAGER->FindImage("Background"));
	_background->GetTransform()->SetSize(Vector2(4032,2000));
	_background->GetTransform()->SetPosition(Vector2(0,0));
	_background->GetTransform()->SetScale(BACKGROUND_SCALE);

	AddChild(_background);

	//LEFT_TOP
	CAMERAMANAGER->SetPosition(Vector2((-1)*BACKGROUND_WIDTH/2+WINSIZEX/2, (-1)*BACKGROUND_HEIGHT/2+WINSIZEY/2));


	//GROUND
	MakeGround(Vector2(0, 444), 4032);
	MakeGround(Vector2(1007, 1859), 1865);
	MakeGround(Vector2(50, 1452), 607);
	MakeGround(Vector2(2975, 1859), 604);

	MakeGround(Vector2(2975, 1200), 100);
	MakeGround(Vector2(2672, 1200), 200);
	MakeGround(Vector2(1159, 1200), 150);
	MakeGround(Vector2(1008, 1200), 50);
	MakeGround(Vector2(153, 1859), 200);
	MakeGround(Vector2(1563, 1202), 504);
	MakeGround(Vector2(2168, 1200), 200);
	MakeGround(Vector2(3429, 1403), 604);
	MakeGround(Vector2(1311, 1552), 1363);
	MakeGround(Vector2(3779, 1856), 203);


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


