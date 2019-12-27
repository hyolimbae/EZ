#pragma once
#include "Object.h"
#include "Physics.h"
#include "Transform.h"
#include "gameNode.h"
#include <functional>
#include <list>

using namespace std;
class GameObject;

struct CollisionCallBack
{
	function<void(GameObject*, GameObject*)> _enter = [](GameObject*, GameObject*) {};
	function<void(GameObject*, GameObject*)> _stay = [](GameObject*, GameObject*) {};
	function<void(GameObject*, GameObject*)> _exit = [](GameObject*, GameObject*) {};
};

class b2Body;
class b2Fixture;

class GameObject : public Object
{
protected:

	GameObject();


	Physics*			_physics;
	Transform*			_transform;
	Image*				_sprite = nullptr;
	CollisionCallBack	_callBack;


public:
	virtual void Render() override;
	virtual void Release() override;

	//static GameObject* CreateObject(GameObject* parent = nullptr);


	//CALLBACK 
	void SetCollisionEnterFunc(function<void(GameObject*, GameObject*)> enter);
	void SetCollisionStayFunc(function<void(GameObject*, GameObject*)> stay);
	void SetCollisionExitFunc(function<void(GameObject*, GameObject*)> exit);

	//GETTER
	CollisionCallBack GetCollisionCallBack() { return _callBack; }
	Image* GetSprite();
	Physics* GetPhysics() { return _physics; }
	Transform* GetTransform() { return _transform; }

	//SETTER
	void SetSprite(Image* sprite);



	template <typename T>
	static GameObject* CreateObject(T, GameObject* parent = nullptr)
	{
		GameObject* newObject = (GameObject *) new T();

		if (parent == nullptr)
		{
			SceneManager::GetInstance()->GetNowScene()->AddChild(newObject);
		}
		else
			newObject->SetParent(parent);

		return newObject;
	}
};

