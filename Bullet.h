#pragma once
#include "GameObject.h"

enum BULLETTYPE
{
	BALEOG_ARROW,
	ENEMY_BULLET
};

class Bullet : public GameObject
{
public:
	Bullet();
	
	virtual void release();
	virtual void update();

	//Enemy �Ѿ� �߻� & ������ ���� �Լ� 
	void Enemy_BulletFire(); 
	void Enemy_BulletMove(); 

	//Baleog �Ѿ� �߻� & ������ ���� �Լ� 
	void Baleog_BulletFire(Vector2 pos, float speed, bool num);
	void Baleog_BulletMove(); 

	void removeBullet(int arrIndex);

};

