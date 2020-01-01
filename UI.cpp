#include "stdafx.h"
#include "UI.h"
#include "CharacterManager.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Render()
{
	int count = 0;
	string charlist[3] = { "","","" };
	for (int i = 0; i < _cm->GetCharacters().size(); i++)
	{
		string name = _cm->GetCharacters()[i]->GetName();
		charlist[count] = name;
		//active 
		if (i == _cm->getNowCharacterNum())
		{
			IMAGEMANAGER->FindImage(name + "Active")->SetSize(Vector2(86, 71));
			IMAGEMANAGER->FindImage(name + "Active")->Render(GetPosByName(name).x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
		}
		else
		{
			IMAGEMANAGER->FindImage(name + "Default")->SetSize(Vector2(86, 71));
			IMAGEMANAGER->FindImage(name + "Default")->Render(GetPosByName(name).x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
		}

		count++;
	}

	//죽었을 때 (벡터사이즈때문에 HP말고 이런식으로 처리)
	if (charlist[0] != "Baleog" && charlist[1] != "Baleog" &&charlist[2] != "Baleog")
	{
		IMAGEMANAGER->FindImage("BaleogDead")->SetSize(Vector2(86, 71));
		IMAGEMANAGER->FindImage("BaleogDead")->Render(GetPosByName("Baleog").x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
	}
	if (charlist[0] != "Erik" && charlist[1] != "Erik" &&charlist[2] != "Erik")
	{
		IMAGEMANAGER->FindImage("ErikDead")->SetSize(Vector2(86, 71));
		IMAGEMANAGER->FindImage("ErikDead")->Render(GetPosByName("Erik").x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
	}
	if (charlist[0] != "Olaf" && charlist[1] != "Olaf" &&charlist[2] != "Olaf")
	{
		IMAGEMANAGER->FindImage("OlafDead")->SetSize(Vector2(86, 71));
		IMAGEMANAGER->FindImage("OlafDead")->Render(GetPosByName("Olaf").x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
	}

	//UI Background 
	IMAGEMANAGER->FindImage("UI")->SetSize(Vector2(WINSIZEX + 4, 170));
	IMAGEMANAGER->FindImage("UI")->Render(0, WINSIZEY - 170, Pivot::LEFT_TOP, true);


	//hp (렌더 순서상 밑으로 뺌)
	for (int i = 0; i < _cm->GetCharacters().size(); i++)
	{
		string name = _cm->GetCharacters()[i]->GetName();
		for (int j = 0; j < _cm->GetCharacters()[i]->GetHP(); j++)
		{
			IMAGEMANAGER->FindImage("hp")->SetSize(Vector2(17, 17));
			IMAGEMANAGER->FindImage("hp")->Render(GetPosByName(name).x + j * 23, WINSIZEY - 170 + 115, Pivot::LEFT_TOP, true);
		}
	}
}


Vector2 UI::GetPosByName(string name)
{
	if (name == "Baleog")
	{
		return Vector2(296, 71);
	}
	else if (name == "Erik")
	{
		return Vector2(117, 71);
	}
	else if (name == "Olaf")
	{
		return Vector2(475, 71);
	}

	return Vector2(0,0);
}


