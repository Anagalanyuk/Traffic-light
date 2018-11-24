#pragma once

#pragma once

#include<Windows.h>

#include"IState.h"

#include"BaseState.h"

#include"Yalowlight.h"

class RedLight : public BaseState, public IState
{
public:
	virtual void Update(TrafficLight* traffic) override;
	void DeleteState();
};