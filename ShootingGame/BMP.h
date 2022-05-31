#pragma once

struct Image
{
	int width;
	int height;
	unsigned int* argb;
};

class BMP
{
private:
public:
	static bool ReadBMP(const char* fileName, Image* img);
	static void DrawBMP(float px, float py, Image* img);
};