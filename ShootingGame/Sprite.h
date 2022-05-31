#pragma once
#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	Image sprite;

public:

	Sprite(string tag, string name, bool active, float px, float py);
	~Sprite();

	void SetSprite(const char* fileName);
	void Draw();
};

