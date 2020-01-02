#pragma once
#include "GameObject.h"
#include "Character.h"

class Door : public GameObject
{
private:
	Character* character;

	bool _isDoor1Opening;
	bool _isDoor1Closing;
	bool _isDoor2Opening;
	bool _isDoor2Closing;

public:
	Door() { _physics = new Physics(); };
	~Door() {};

	virtual HRESULT Init() override;
	virtual void Update() override;

	void Door1Opening();
	void Door1Closing();
	void Door2Opening();
	void Door2Closing();
	bool GetIsDoor1Opening() { return _isDoor1Opening; }
	bool GetIsDoor1Closing() { return _isDoor1Closing; }
	void SetIsDoor1Opening(bool isOpening) { _isDoor1Opening = isOpening; }
	void SetIsDoor1Closing(bool isClosing) { _isDoor1Closing = isClosing; }
	bool GetIsDoor2Opening() { return _isDoor2Opening; }
	bool GetIsDoor2Closing() { return _isDoor2Closing; }
	void SetIsDoor2Opening(bool isOpening) { _isDoor2Opening = isOpening; }
	void SetIsDoor2Closing(bool isClosing) { _isDoor2Closing = isClosing; }
};