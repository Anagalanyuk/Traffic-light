#include<iostream>

#include<Windows.h>

#include"Traffic.h"

#include"Red Light.h"



int main()
{
	TrafficLight trafficLight;
	trafficLight.SetState(new RedLight);
	trafficLight.Start();

	//system("pause");
}