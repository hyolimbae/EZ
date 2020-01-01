#include "stdafx.h"
#include "CharacterManager.h"

void CharacterManager::AddCharacter(Character* character)
{
	_characters.push_back(character);
	character->SetAllowsUpdate(false);
}

void CharacterManager::ChangeCharacter()
{
	_characters[_nowCharacterNumber]->SetAllowsUpdate(false);
	_nowCharacterNumber = (_nowCharacterNumber + 1) % _characters.size();
	_characters[_nowCharacterNumber]->SetAllowsUpdate(true);
	CAMERAMANAGER->MoveCamera(_characters[_nowCharacterNumber]->GetTransform()->GetPosition(),5.f);
}

void CharacterManager::Update()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_CONTROL))
		ChangeCharacter();
}