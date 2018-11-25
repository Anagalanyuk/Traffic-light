#pragma once

#include"Traffic.h"

class TrafficLight;
class IState
{
public:
	virtual void Update(TrafficLight* traffic) = 0;
};