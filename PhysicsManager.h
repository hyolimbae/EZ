#pragma once
#include "singletonBase.h"
#include <functional>
#include "GameObject.h"
#include "Vector2.h"
#include "Box2D/Box2D.h"

#define PIXELTOMETER 1/50.0f
#define METERTOPIXEL 50.0f

class PhysicsManager : public singletonBase<PhysicsManager>, public b2ContactListener
{
private:
	b2World* _world;
	bool isDebug = false;


public:
	PhysicsManager();
	~PhysicsManager();

	HRESULT Init();
	void Release();
	void Update();
	void Render();

	//convert
	Vector2 p2m(Vector2 pixel) { return Vector2(pixel.x*PIXELTOMETER, pixel.y*PIXELTOMETER); }
	Vector2 m2p(Vector2 meter) { return Vector2(meter.x*METERTOPIXEL, meter.y*METERTOPIXEL); }

	//create & destroy body
	b2Body* CreateBody(GameObject* obj);
	b2Shape* CreateShape(b2Body* body, float width, float height);
	b2Shape* CreateShape(b2Body* body);
	b2Fixture* CreateFixture(b2Body* body, b2Shape* shape);
	void DestroyBody(b2Body* body);

	b2Body* CreateDefaultBody(GameObject* obj, float width, float height);

	//setpos
	void SetBodyPosition();
	static void IgnoreCollision(GameObject* obj1, GameObject* obj2);

	

	//contact
	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;


	void SetWorld(b2World* world);



	//getter
	b2World* GetWorld() { return _world; }

};

