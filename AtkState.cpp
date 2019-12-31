#include "stdafx.h"
#include "AtkState.h"
#include "IdleState.h"
#include "Character.h"

void AtkState::EnterState()
{
	//Baleog 공격 타입 KNIFE_UP
	if (_thisObj->GetATKType() == KNIFE_ATTACK)
	{
		int rnd = RND->getFromIntTo(0, 1);

		if (rnd == 0)
		{
			//오른쪽 방향
			if (_thisObj->GetSprite()->GetFlipX() == false)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_down"));
				_thisObj->GetSprite()->SetFlip(false, false);
			}

			//왼쪽 방향
			if (_thisObj->GetSprite()->GetFlipX() == true)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_down"));
				_thisObj->GetSprite()->SetFlip(true, false);
			}
		}
		else
		{
			//오른쪽 방향
			if (_thisObj->GetSprite()->GetFlipX() == false)
			{
				_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Knife_up"));
				_thisObj->GetSprite()->SetFlip(false, false);
			}

			//왼쪽 방향
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
		//오른쪽 
		if (_thisObj->GetSprite()->GetFlipX() == false)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Shoot_arrow"));
			_thisObj->GetSprite()->SetFlip(false, false);
			_bullet->Baleog_BulletFire(Vector2(_thisObj->GetTransform()->GetPosition().x, _thisObj->GetTransform()->GetPosition().y+3), 3, false);
		}

		//왼쪽
		else if (_thisObj->GetSprite()->GetFlipX() == true)
		{
			_thisObj->SetSprite(IMAGEMANAGER->FindImage("Baleog_Shoot_arrow"));
			_thisObj->GetSprite()->SetFlip(true, false);
			_bullet->Baleog_BulletFire(_thisObj->GetTransform()->GetPosition(), -3, true);
		}
	}

	//Baleog 공격 타입 ARROW
		//if (_thisObj->GetATKType() == ARROW)
		//{
		// 불렛 함수 연결
		//}

		//Erik 공격 설정 
		//if (_thisObj->GetATKType() == ???)
		//{
		//박치기 모션
		//}

		//Olaf 공격 설정 
		//if (_thisObj->GetATKType() == ???)
		//{
		//방패 사용 모션 
		//}

	//Current State 가 MaxFrame과 같다면 changeState를 해라 
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
