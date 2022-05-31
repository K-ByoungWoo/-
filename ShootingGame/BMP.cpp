#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#include "BMP.h"
#include "Graphic.h"

bool BMP::ReadBMP(const char* fileName, Image* img)
{
	//비트맵 파일 읽기//
	FILE* stream;

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//BITMAPFILEHEADER 읽어오기//
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		/*************************
		printf("-----비트맵파일헤더 출력-------\n");
		printf("bfType : 0x%x\n", fileHeader.bfType);			//내부데이타에서..bmp 파일 형식인지를 확인하는 코드(매직코드)
		printf("bfSize : %d 바이트\n", fileHeader.bfSize);      //파일크기	
		printf("bfReserved1 : %d\n", fileHeader.bfReserved1);   //향후 사용을 위해서..예약된 변수1
		printf("bfReserved2 : %d\n", fileHeader.bfReserved2);   //향후 사용을 위해서..예약된 변수2
		printf("bfOffBits : %d\n", fileHeader.bfOffBits);		//그림데이타(bitmap 데이타)가 저장된곳 까지의 떨어진 간격(Offset)
		**************************/

		//BITMAPINFOHEADER 읽어오기//
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		/*******************************
		printf("-------비트맵인포헤더 출력--------\n");
		printf("biWidth    : %d\n", infoHeader.biWidth);
		printf("biHeight   : %d\n", infoHeader.biHeight);
		printf("biBitCount : %d\n", infoHeader.biBitCount);
		*******************************/

		//비트맵 픽셀 데이타 읽어오기//
		int width = infoHeader.biWidth;
		int height = infoHeader.biHeight;
		int length = width * height;

		unsigned int* argb = new unsigned int[length];

		fread(argb, sizeof(unsigned int), length, stream);

		//파일 닫기
		fclose(stream);

		//비트맵 정보...구조체 배열에 저장하기
		img->width = width;
		img->height = height;
		img->argb = argb;

		return true;  //이미지 로드 성공
	}
	else {
		printf("비트맵 파일을 읽어올수 없습니다\n");

		return false;  //이미지 로드 실패
	}
}

void BMP::DrawBMP(float px, float py, Image* img)
{
	//이미지 draw//
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			unsigned int pixel = img->argb[y * img->width + x];

			SetPixel(px + x, py + y, pixel);
		}
	}
}