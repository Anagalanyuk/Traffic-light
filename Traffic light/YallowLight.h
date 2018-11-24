#pragma once

#include"BaseState.h"

#include"IState.h"

#include"Greenlight.h"

class YellowLight : public BaseState, public IState
{
public:
	virtual void Update(TrafficLight* traffic)override;
	void DeleteState();
};