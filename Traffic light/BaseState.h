#pragma once

#include<Windows.h>

class  BaseState
{
protected:
	const char cell = 'O';
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const char space = ' ';
	const int x = 10;
	const int y = 5;

	int offSet = 1;
	COORD point;
	int width = 5;
};