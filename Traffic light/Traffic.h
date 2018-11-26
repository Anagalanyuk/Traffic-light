#pragma once

#include"IState.h"

class IState;
class TrafficLight
{
public:
	void SetState(IState* state);
	void Start();
	bool GetUpdate();
	~TrafficLight();
private:
	IState* m_state = nullptr;
	int key = 0;
	bool isUpdate = true;
};