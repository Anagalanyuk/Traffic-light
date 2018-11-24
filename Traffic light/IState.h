#pragma once

#include"Traffic.h"
class TrafficLight;
class IState // State
{
public:
	virtual void Update(TrafficLight* traffic) = 0;
};