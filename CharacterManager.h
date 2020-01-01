#pragma once
#include <vector>
#include "GameObject.h"
#include "Character.h"

using namespace std;


class CharacterManager : public GameObject
{
private:

	vector<Character*> _characters;
	int _nowCharacterNumber;

public:
	void AddCharacter(Character* character);
	void ChangeCharacter();
	virtual void Update() override;


	//╟тем 
	vector<Character*> GetCharacters() { return _characters; }
	int getNowCharacterNum() { return _nowCharacterNumber; }
};

