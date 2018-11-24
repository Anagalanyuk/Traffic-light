#pragma once

#include<Windows.h>

#include"BaseState.h"

class RedLight: public BaseState
{
public:
	void Show()
	{
		COORD point;
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
		width = 5;
		offSet = 1;
	}
};