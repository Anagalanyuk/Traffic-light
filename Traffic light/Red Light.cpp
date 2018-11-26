#include<iostream>

#include"Red Light.h"

#include"YellowLight.h"

#include"Traffic.h"

void RedLight::Update(TrafficLight* traffic)
{
	offSet = 1;
	width = 5;
	point.X = x;
	point.Y = y;

	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			SetConsoleCursorPosition(handle, point);
			std::cout << cell << std::endl;
			point.X++;
		}
		if (i < 2)
		{
			width += 2;
			point.X = x - i - offSet;
		}
		else
		{
			width -= 2;
			point.X = x - offSet;
			offSet--;
		}
		point.Y++;
	}
	DeleteState();
	traffic->SetState(new YellowLight);
}

void RedLight::DeleteState()
{
	offSet = 1;
	width = 5;
	point.X = x;
	point.Y = y;
	Sleep(2000);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			SetConsoleCursorPosition(handle, point);
			std::cout << space << std::endl;
			point.X++;
		}
		if (i < 2)
		{
			width += 2;
			point.X = x - i - offSet;
		}
		else
		{
			width -= 2;
			point.X = x - offSet;
			offSet--;
		}
		point.Y++;
	}
}