#include "stdafx.h"
#include "Olaf.h"


Olaf::Olaf()
{
	_sprite = IMAGEMANAGER->FindImage("Olaf_Idle");
}


Olaf::~Olaf()
{
}

HRESULT Olaf::Init()
{
	Character::Init();

	return S_OK;
}
