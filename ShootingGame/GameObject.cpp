#include "GameObject.h"

GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag    = tag;
	this->name   = name;
	this->active = active;

	this->px = px;
	this->py = py;
}

GameObject::~GameObject()
{
	cout << "===게임 오브젝트 소멸자===" << endl;
}

void GameObject::Start()
{}

void GameObject::Update()
{}

void GameObject::Draw()
{}

//게터 함수//
string GameObject::GetTag()
{
	return tag;
}

string GameObject::GetName()
{
	return name;
}

bool GameObject::GetActive()
{
	return active;
}

float GameObject::GetPx()
{
	return px;
}
float GameObject::GetPy()
{
	return py;
}

//세터 함수//
void GameObject::SetTag(string tag)
{
	this->tag = tag;
}

void GameObject::SetName(string name)
{
	this->name = name;
}

void GameObject::SetActive(bool active)
{
	this->active = active;
}

void GameObject::SetPx(float px)
{
	this->px = px;
}

void GameObject::SetPy(float py)
{
	this->py = py;
}

//게임오브젝트...이동 함수
void GameObject::Translate(float x, float y)
{
	px = px + x;
	py = py + y;
}