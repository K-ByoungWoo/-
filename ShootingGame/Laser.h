#pragma once
#include"ShootingGame.h"
#include"Sprite.h"

class Laser:public Sprite
{
private:
	float speed;
public:
	Laser(float px, float py);
	~Laser();

	void Start();
	void Update();
};

