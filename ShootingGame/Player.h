#pragma once
#include"ShootingGame.h"
#include "Sprite.h"

class Player : public Sprite
{
private:
	float speed;

public:
	Player(float px, float py);
	~Player();

	void Start();
	void Update();
};

