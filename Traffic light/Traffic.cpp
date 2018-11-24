#include<iostream>

#include"Traffic.h"

#include"IState.h"

void TrafficLight::SetState(IState* state)
{
	this->m_state = state;
}

void TrafficLight::Start()
{
	std::cout << "S - Start" << std::endl;
	std::cout << "P - Pause" << std::endl;
	std::cout << "E - Exit" << std::endl;

	while (true)
	{
		m_state->Update(this);
	}
}