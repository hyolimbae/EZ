#pragma once
#include "GameObject.h"

using namespace std;

class CharacterManager;


struct CharacterInfo
{
	Vector2 UIpos;
	int selectPos;
};

class UI: public GameObject
{
private:

	string characterUIstate;
	CharacterManager* _cm;
	bool _isActive;
	int _count = 0;

	CharacterInfo info[3];

public:
	UI();
	~UI();

	virtual HRESULT Init() override;
	virtual void Render() override;
	virtual void Update() override;

	void SetLink(CharacterManager* cm)
	{
		_cm = cm;
	}

	CharacterInfo GetInfoByName(string name);
	void UIKeyControl();

};


