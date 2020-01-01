#include "stdafx.h"
#include "Erik.h"


Erik::Erik()
{
	_sprite = IMAGEMANAGER->FindImage("Erik_Idle");
}


Erik::~Erik()
{
}

HRESULT Erik::Init()
{
	Character::Init();
	//부모의 Init을 불러와주기 위해서
	return S_OK;
}
