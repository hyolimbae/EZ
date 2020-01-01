#pragma once
#include "GameObject.h"
#include "Character.h"

//컨트롤 체인지
//카메라 체인지
//카메라 체인지 되었을때 깜빡거림
//UI처리 

class GameManager : public GameObject
{
private:

public:
	GameManager();
	~GameManager();

	virtual HRESULT Init() override;
 	virtual void Update() override;



};

