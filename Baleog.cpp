#include "stdafx.h"
#include "Baleog.h"


Baleog::Baleog()
{
	_sprite = IMAGEMANAGER->FindImage("Baleog_Idle");
}


Baleog::~Baleog()
{

}

HRESULT Baleog::Init()
{
	Character::Init();

	return S_OK;
}
