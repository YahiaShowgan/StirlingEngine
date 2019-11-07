#pragma once
#include <vector>
#include "CalculatedData.h"
#include <iostream>

class Cycle
{
protected:
	int cycleNum;
	std::vector<CalculatedData>calculatedDataList;
	double cycleTime, sumOfCycleWork, avgAngularVelocity, avgAngularAcceleration;
	double cycleThermalPower, cycleElectricalPower;
	
public:
	//Contructor
	Cycle();
	//Copy Contructor
	Cycle(const Cycle &c);
	//Constructor
	Cycle(int);
	//Contructor
	Cycle(int, std::vector<CalculatedData>);
	//Contructor
	Cycle(int cycleNum, std::vector<CalculatedData> calculatedDataList, double cycleTime,
		double sumOfCycleWork, double avgAngularVelocity, double avgAngularAcceleration,
		double cycleThermalPower, double cycleElectricalPower);
	//Constructor
	Cycle(double RPM, double cycleThermalPower, double cycleElectricalPower);
	//Destructor
	~Cycle();
	//Operator =
	Cycle& operator = (const Cycle&);
	int getCycleNum();
	double getCycleTime();	
	double getRPM();
	double getSumOfCycleWork();
	double getAngularVelocity();
	double getAngularAcceleration();
	double getCycleThermalPower();
	double getCycleElectricalPower();
	void setCycleWork(double sumOfCycleWork);
	void setCycleThermalPower(double cycleThermalPower);
	void printCycle();
	std::vector<CalculatedData> getCalculatedDataList();
	bool operator < (const Cycle& cycle2) const
	{
		double rpm1 = 60.0 / this->cycleTime;
		double rpm2 = 60.0 / cycle2.cycleTime;
		return (rpm1<rpm2);
	}
};
