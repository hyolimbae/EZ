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
	//�θ��� Init�� �ҷ����ֱ� ���ؼ�
	return S_OK;
}
