#pragma once

#include"Traffic.h"

#include"RedLight.h"

#include"BaseState.h"

#include"IState.h"


class GreenLight : public BaseState, public IState
{
public:
	virtual void Update(TrafficLight* traffic)override
	{
		offSet = 1;
		width = 5;
		point.X = x;
		point.Y = y + 12;

		SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
		Sleep(3000);
		DeleteState();
		//traffic->SetState(new RedLight);
	}

	void DeleteState()
	{
		COORD point;
		offSet = 1;
		width = 5;
		point.X = x;
		point.Y = y + 12;
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