#pragma once

#include <vector>
#include "GameObject.h"

class ObjectManager
{
private:
	//게임객체 저장 stl vector를 사용//
	static vector<GameObject*> gameObjects;

public:	

	//게임객체를..목록에 추가해서..실제로 동작하는 인스턴스로 만드는 함수
	static void Instantiate(GameObject* o);

	//게임 목록 업데이트 함수
	static void Update();

	//게임 목록 Draw 함수
	static void Draw();

	//게임 목록 전체 Clear 함수
	static void Clear();
};

