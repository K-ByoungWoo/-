#include "ShootingGame.h"

GameBG::GameBG(float px, float py):Sprite("", "", true, px, py)
{
	
}
GameBG::~GameBG()
{}

void GameBG::Start()
{
	SetSprite("Asset/게임배경.bmp");
}
void GameBG::Update()
{

}