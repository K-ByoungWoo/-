#pragma once

class Time
{
private:
	static float currTime;
	static float nextTime;

public:
	static float deltaTime; //유니티에서는 C#의 프로그램(Get/Set 프로퍼티) 기능으로..deltaTime을 public으로 사용함

	static void Init();
	static void Update();	
};