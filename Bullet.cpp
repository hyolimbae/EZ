#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_physics = new Physics;
}

void Bullet::release()
{
}

void Bullet::update()
{
}

void Bullet::Enemy_BulletFire()
{
	/*Bullet* _EnemyBullet = new Bullet; 
	_EnemyBullet->SetName*/
}

void Bullet::Enemy_BulletMove()
{

}

void Bullet::Baleog_BulletFire(Vector2 pos, float speed, bool num)
{
	//BULLETMAKE 
	Bullet* _baleogArrow = new Bullet;
	_baleogArrow->SetSprite(IMAGEMANAGER->FindImage("Baleog_arrow")); 
	_baleogArrow->SetName("Baleog_arrow"); 
	_baleogArrow->GetTransform()->SetSize(Vector2(14, 5)); 
	_baleogArrow->GetTransform()->SetPosition(pos);
	_baleogArrow->GetSprite()->SetFlip(num, false);

	//BULLET BODY 
	_baleogArrow->GetPhysics()->SetBodyType(b2_dynamicBody); 
	_baleogArrow->GetPhysics()->SetBody(PHYSICSMANAGER->CreateBody(_baleogArrow)); 
	_baleogArrow->GetPhysics()->SetGravityScale(0); 
	_baleogArrow->GetPhysics()->SetVelocity(Vector2(speed, 0)); 
	_baleogArrow->GetPhysics()->SetShapeType(BOX); 

	//BULLET SHAPE & FIXTURE
	b2Shape* _beleogArrrowShape = PHYSICSMANAGER->CreateShape(_baleogArrow->GetPhysics()->GetBody(),
	_baleogArrow->GetTransform()->GetSize().x,
	_baleogArrow->GetTransform()->GetSize().y);
	_baleogArrow->GetPhysics()->SetFixture(PHYSICSMANAGER->CreateFixture(_baleogArrow->GetPhysics()->GetBody(), _beleogArrrowShape));
	
	_baleogArrow->GetPhysics()->SetIsSensor(true); 

	SceneManager::GetInstance()->GetNowScene()->AddChild(_baleogArrow);

}

void Bullet::Baleog_BulletMove()
{

}

void Bullet::removeBullet(int arrNum)
{

}
