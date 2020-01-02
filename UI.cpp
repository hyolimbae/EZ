#include "stdafx.h"
#include "UI.h"
#include "CharacterManager.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Update()
{
	_count++;
	UIKeyControl();
}

HRESULT UI::Init()
{
	for (int i = 0; i < 3; i++)
	{
		info[i].selectPos = 0;
		info[i].UIpos = Vector2(117 + i * 179,71);
	}
	return S_OK;
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
			IMAGEMANAGER->FindImage(name + "Active")->Render(info[i].UIpos.x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
		}
		else
		{
			IMAGEMANAGER->FindImage(name + "Default")->SetSize(Vector2(86, 71));
			IMAGEMANAGER->FindImage(name + "Default")->Render(info[i].UIpos.x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
		}

		count++;
	}

	//죽었을 때 (벡터사이즈때문에 HP말고 이런식으로 처리)
	if (charlist[0] != "Baleog" && charlist[1] != "Baleog" &&charlist[2] != "Baleog")
	{
		IMAGEMANAGER->FindImage("BaleogDead")->SetSize(Vector2(86, 71));
		IMAGEMANAGER->FindImage("BaleogDead")->Render(info[1].UIpos.x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
	}
	if (charlist[0] != "Erik" && charlist[1] != "Erik" &&charlist[2] != "Erik")
	{
		IMAGEMANAGER->FindImage("ErikDead")->SetSize(Vector2(86, 71));
		IMAGEMANAGER->FindImage("ErikDead")->Render(info[0].UIpos.x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
	}
	if (charlist[0] != "Olaf" && charlist[1] != "Olaf" &&charlist[2] != "Olaf")
	{
		IMAGEMANAGER->FindImage("OlafDead")->SetSize(Vector2(86, 71));
		IMAGEMANAGER->FindImage("OlafDead")->Render(info[2].UIpos.x, WINSIZEY - 170 + 45, Pivot::LEFT_TOP, true);
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
			IMAGEMANAGER->FindImage("hp")->Render(info[i].UIpos.x + j * 23, WINSIZEY - 170 + 115, Pivot::LEFT_TOP, true);
		}
	}

	//SELECT
	for (int i = 0; i < _cm->GetCharacters().size(); i++)
	{
		string name = _cm->GetCharacters()[i]->GetName();
		//active 
		if (i == _cm->getNowCharacterNum())
		{
			if (_isActive)
			{
				IMAGEMANAGER->FindImage("select")->SetSize(Vector2(40, 40));
				if (_count>50)
				{
					IMAGEMANAGER->FindImage("select")->Render(info[i].UIpos.x+85 + (info[i].selectPos%2)*38, WINSIZEY - 125 + (info[i].selectPos / 2) * 43, Pivot::LEFT_TOP, true);
					if(_count>100) _count = 0;
				}
			}
			else
			{
				IMAGEMANAGER->FindImage("select")->SetSize(Vector2(40, 40));
				IMAGEMANAGER->FindImage("select")->Render(info[i].UIpos.x + 85 + (info[i].selectPos % 2) * 38, WINSIZEY - 125 + (info[i].selectPos / 2) * 43, Pivot::LEFT_TOP, true);
			}
			continue;
		}

		IMAGEMANAGER->FindImage("select")->SetSize(Vector2(40, 40));
		IMAGEMANAGER->FindImage("select")->Render(info[i].UIpos.x + 85 + (info[i].selectPos % 2) * 38, WINSIZEY - 125 + (info[i].selectPos / 2) * 43, Pivot::LEFT_TOP, true);

	}

}


CharacterInfo UI::GetInfoByName(string name)
{
	if (name == "Baleog")
	{
		return info[1];
	}
	else if (name == "Erik")
	{
		return info[0];
	}
	else if (name == "Olaf")
	{
		return info[2];
	}
}


void UI::UIKeyControl()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_TAB))
	{
		_isActive = !_isActive;
	}
	
	for (int i = 0; i < _cm->GetCharacters().size(); i++)
	{
		string name = _cm->GetCharacters()[i]->GetName();

		//액티브한 하나만 업데이트 
		if (_isActive && i == _cm->getNowCharacterNum())
		{
			if (KEYMANAGER->IsOnceKeyDown(VK_LEFT)&& (GetInfoByName(name).selectPos)%2 !=0)
			{
				info[i].selectPos -= 1;
			}
			if (KEYMANAGER->IsOnceKeyDown(VK_RIGHT) &&(GetInfoByName(name).selectPos+1)%2 !=0)
			{
				info[i].selectPos += 1;
			}
			if (KEYMANAGER->IsOnceKeyDown(VK_UP)&& (GetInfoByName(name).selectPos >1))
			{
				info[i].selectPos -= 2;
			}
			if (KEYMANAGER->IsOnceKeyDown(VK_DOWN)&& (GetInfoByName(name).selectPos <2))
			{
				info[i].selectPos += 2;
			}
		}
	}
	
}



