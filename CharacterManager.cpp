#include "stdafx.h"
#include "CharacterManager.h"

void CharacterManager::AddCharacter(Character* character)
{
	if (_characters.size())
		character->SetAllowsUpdate(false);

	_characters.push_back(character);
}

void CharacterManager::ChangeCharacter()
{
	_characters[_nowCharacterNumber]->SetAllowsUpdate(false);
	_nowCharacterNumber = (_nowCharacterNumber + 1) % _characters.size();
	_characters[_nowCharacterNumber]->SetAllowsUpdate(true);
	CAMERAMANAGER->MoveCamera(_characters[_nowCharacterNumber]->GetTransform()->GetPosition(),1.f);
}

void CharacterManager::Update()
{
	if(!CAMERAMANAGER->GetIsMoving())
		CAMERAMANAGER->SetPosition(_characters[_nowCharacterNumber]->GetTransform()->GetPosition());
	if (KEYMANAGER->IsOnceKeyDown(VK_CONTROL) && !CAMERAMANAGER->GetIsMoving())
		ChangeCharacter();
}