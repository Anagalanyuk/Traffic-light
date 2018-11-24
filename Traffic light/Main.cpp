#include<iostream>

#include<Windows.h>

#include"Traffic.h"

#include"RedLight.h"



int main()
{
	TrafficLight trafficLight;
	trafficLight.SetState(new RedLight);
	trafficLight.Start();

	//system("pause");
}