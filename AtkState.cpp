#include "stdafx.h"
#include "AtkState.h"
#include "IdleState.h"
#include "Character.h"

void AtkState::EnterState()
{
	//Baleog ���� Ÿ�� KNIFE_UP
	if (_thisObj->GetATKType() == KNIFE_ATTACK)
	{
		int rnd = RND->getFromIntTo(0, 1);

		if (rnd == 0)
		{
			//������ ����
			if (_thisObj->GetSprite()->GetFlipX() == false)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_down"));
				_thisObj->GetSprite()->SetFlip(false, false);
			}

			//���� ����
			if (_thisObj->GetSprite()->GetFlipX() == true)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_down"));
				_thisObj->GetSprite()->SetFlip(true, false);
			}
		}
		else
		{
			//������ ����
			if (_thisObj->GetSprite()->GetFlipX() == false)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_up"));
				_thisObj->GetSprite()->SetFlip(false, false);
			}

			//���� ����
			if (_thisObj->GetSprite()->GetFlipX() == true)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_up"));
				_thisObj->GetSprite()->SetFlip(true, false);
			}
		}
	}
	
	if (_thisObj->GetATKType() == ARROW)
	{
		auto _bullet = new Bullet; 
		//������ 
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Shoot_arrow"));
			_thisObj->GetSprite()->SetFlip(false, false);
			_bullet->Baleog_BulletFire(Vector2(_thisObj->GetTransform()->GetPosition().x, _thisObj->GetTransform()->GetPosition().y+3), 3, false);
		}

		//����
		else if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Shoot_arrow"));
			_thisObj->GetSprite()->SetFlip(true, false);
			_bullet->Baleog_BulletFire(_thisObj->GetTransform()->GetPosition(), -3, true);
		}
	}

	//Baleog ���� Ÿ�� ARROW
		//if (_thisObj->GetATKType() == ARROW)
		//{
		// �ҷ� �Լ� ����
		//}

		//Erik ���� ���� 
		//if (_thisObj->GetATKType() == ???)
		//{
		//��ġ�� ���
		//}

		//Olaf ���� ���� 
		//if (_thisObj->GetATKType() == ???)
		//{
		//���� ��� ��� 
		//}

	//Current State �� MaxFrame�� ���ٸ� changeState�� �ض� 
	//_thisObj->ChangeState(new IdleState(_thisObj));

	
}

void AtkState::UpdateState()
{
	
	if (_thisObj->GetCurrentPosition().x == _thisObj->GetSprite()->GetMaxFrameX()-1)
	{
		_thisObj->ChangeState(new IdleState(_thisObj));
	}

}

void AtkState::ExitState()
{
}
