#pragma once
#include "GameObject.h"
#include "Character.h"

//��Ʈ�� ü����
//ī�޶� ü����
//ī�޶� ü���� �Ǿ����� �����Ÿ�
//UIó�� 

class GameManager : public GameObject
{
private:

public:
	GameManager();
	~GameManager();

	virtual HRESULT Init() override;
 	virtual void Update() override;



};

