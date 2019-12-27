#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	_transform = new Transform();
	//_physics = new Physics();
}

void GameObject::SetSprite(Image* sprite)
{
	_sprite = sprite;
}

void GameObject::Release()
{
	if (_parent)
		_parent->RemoveChild(this);
	_physics->GetBody()->SetUserData(nullptr);
	delete _transform;
	delete _physics;
	delete this;
}

//GameObject * GameObject::CreateObject(GameObject * parent)
//{
//	GameObject* newObject = new GameObject();
//
//	if (parent == nullptr)
//		newObject->SetParent(SceneManager::GetInstance()->GetNowScene());
//	else
//		newObject->SetParent(parent);
//
//	return newObject;
//}

Image* GameObject::GetSprite()
{
	return _sprite;
}


void GameObject::SetCollisionEnterFunc(function<void(GameObject*,GameObject*)> enter)
{
	_callBack._enter = enter;
}

void GameObject::SetCollisionStayFunc(function<void(GameObject*, GameObject*)> stay)
{
	_callBack._stay = stay;
}

void GameObject::SetCollisionExitFunc(function<void(GameObject*, GameObject*)> exit)
{
	_callBack._exit = exit;
}

void GameObject::Render()
{
	if (!_sprite)
		return;
	Vector2 position = _transform->GetPosition();
	_sprite->SetAngle(_transform->GetRotation());
	_sprite->SetScale(_transform->GetScale());
	_sprite->SetAlpha(_transform->GetAlpha());
	_sprite->SetSize(_transform->GetSize());
	_sprite->Render(position.x, position.y,Pivot::CENTER);
}