#include "stdafx.h"
#include "MoveState.h"
#include "Character.h"
#include "IdleState.h"
#include "JumpState.h"

void MoveState::UpdateState()
{
	b2Body* body = _thisObj->GetPhysics()->GetBody();

	if (_thisObj->GetTag() == "Character")
	{
		if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
			//���������� ������
		{
			_thisObj->GetSprite()->SetFlip(false, false);
			if (body->GetLinearVelocity().x > 3) //�ٵ� ������ �ӵ��̻� �ö󰡸� return���� �� �̻� �����ʰ����ݴϴ�.
				return;							 //�̰� �Ⱦ��� ������ ������ �ӵ���� �ö󰩴ϴ�.
			//Body�� force�� �־ �����̴� ���� �Դϴ�.
			b2Vec2 force = { 6,0 };
			_thisObj->GetPhysics()->GetBody()->ApplyForceToCenter(force, true);
		}
		else if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
			//�������� ������.
		{
			_thisObj->GetSprite()->SetFlip(true, false);
			if (body->GetLinearVelocity().x < -3) return; //������
			b2Vec2 force = { -6,0 };
			_thisObj->GetPhysics()->GetBody()->ApplyForceToCenter(force, true);
		}
		else
		{
			//�������� ���������� ChangeState�� Idle���·� �ٲ��ֵ��� �߽��ϴ�.
			_thisObj->ChangeState(new IdleState(_thisObj));
		}
	}
	//�������� ����ŷ�� �ӵ��� ���ݾ� �ٸ��ϱ� TagName���� ����� �������մϴ�.
}

void MoveState::EnterState()
{
	if (_thisObj->GetName() == "Erik") _thisObj->SetSprite(IMAGEMANAGER->FindImage("Erik_Run"));
	if (_thisObj->GetName() == "Olaf") _thisObj->SetSprite(IMAGEMANAGER->FindImage("Olaf_Run"));
	if (_thisObj->GetName() == "Baleog") _thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Run"));
}

void MoveState::ExitState()
{
	
}


