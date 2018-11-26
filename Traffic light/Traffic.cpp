#include<iostream>

#include<Windows.h>

#include<conio.h>

#include"Traffic.h"

#include"IState.h"

#include"Key.h"

bool TrafficLight::GetUpdate()
{
	return isUpdate;
}

void TrafficLight::SetState(IState* state)
{
	this->m_state = state;
}

void TrafficLight::Start()
{
	std::cout << "S - Start" << std::endl;
	std::cout << "P - Pause" << std::endl;
	std::cout << "E - Exit" << std::endl;

	CONSOLE_CURSOR_INFO cursor = {};
	cursor.bVisible = false;
	cursor.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

	COORD point;
	point.X = 30;
	point.Y = 15;

	key = _getch();
	while (key != start && key != escape)
	{
		if (key != start)
		{
			key = _getch();
		}
	}

	while (key != escape)
	{
		if (isUpdate)
		{
			m_state->Update(this);
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == pause)
			{
				key = _getch();
				key = pause;
				if (isUpdate)
				{
					isUpdate = false;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
					std::cout << "Pause";
				}
				else
				{
					isUpdate = true;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
					std::cout << "     ";
				}
			}
		}
	}
}

TrafficLight::~TrafficLight()
{
	delete m_state;
}