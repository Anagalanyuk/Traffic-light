#pragma once

#include"Traffic.h"

#include"BaseState.h"

#include"IState.h"

class GreenLight : public BaseState, public IState
{
public:
	virtual void Update(TrafficLight* traffic)override;
	void DeleteState();
};