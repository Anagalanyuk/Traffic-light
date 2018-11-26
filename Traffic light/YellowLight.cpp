#include<iostream>

#include"YellowLight.h"

#include"Traffic.h"

#include"Greenlight.h"

void YellowLight::Update(TrafficLight* traffic)
{
	for (int i = 0; i < 4; ++i)
	{
		offSet = 1;
		width = 5;
		point.X = x;
		point.Y = y + 6;

		SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
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
				point.X = x - i - 1;
			}
			else
			{
				width -= 2;
				point.X = x - offSet;
				offSet--;
			}
			point.Y++;
		}
		Sleep(500);
		DeleteState();
		Sleep(500);
	}

	traffic->SetState(new GreenLight);
};

void YellowLight::DeleteState()
{
	{
		offSet = 1;
		width = 5;
		point.X = x;
		point.Y = y + 6;
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
				point.X = x - i - 1;
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
}