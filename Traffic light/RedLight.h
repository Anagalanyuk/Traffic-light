#pragma once

#include<Windows.h>

#include"IState.h"

#include"BaseState.h"

#include"Yalowlight.h"

class RedLight : public BaseState, public IState
{
public:
	virtual void Update(TrafficLight* traffic) override
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
		traffic->SetState(new YelowLight);
	}

	void DeleteState()
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
};