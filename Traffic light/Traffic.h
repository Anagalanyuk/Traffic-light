#pragma once

#include"IState.h"
class IState;
class TrafficLight // context
{
public:
	void SetState(IState* state);
	void Start();
private:
	IState* m_state = nullptr;
};