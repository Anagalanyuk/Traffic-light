#pragma once

#include"IState.h"

class TrafficLight // context
{
public:
	void SetState(IState* state)
	{
		this->state = state;
	}

	void Start()
	{
		std::cout << "S - Start" << std::endl;
		std::cout << "P - Pause" << std::endl;
		std::cout << "E - Exit" << std::endl;

		while (true)
		{
			state->Update(this);
		}
	}
private:
	IState* state = nullptr;
};