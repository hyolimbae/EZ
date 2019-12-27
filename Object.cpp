#include "stdafx.h"
#include "Object.h"


void Object::AddChild(Object* child)
{
	child->Init();
	_children.push_back(child);
	child->SetParent(this);
}


void Object::RemoveChild(Object* child)
{
	for (auto c : _children)
	{
		if (c != child)
			continue;
		_children.remove(child);
		break;
	}
}


void Object::SetParent(Object* parent)
{
	if (_parent)
		_parent->RemoveChild(this);
	_parent = parent;
}








