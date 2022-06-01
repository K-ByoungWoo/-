#include "Laser.h"

Laser::Laser(float px, float py) :Sprite("", "", true, px, py)
{
	this->speed = 500;
}
Laser::~Laser()
{}

void Laser::Start()
{
	SetSprite("Asset/·¹ÀÌÀú.bmp");
}
void Laser::Update()
{
	Translate(0, -speed * Time::deltaTime);
}