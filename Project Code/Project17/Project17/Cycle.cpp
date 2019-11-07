#include "Cycle.h"

//Constructor
Cycle::Cycle()
{

}

//Constructor
Cycle::Cycle(int cycleNum)
{
	this->cycleNum = cycleNum;
}

Cycle::Cycle(double RPM, double cycleThermalPower,double cycleElectricalPower)
{
	this->cycleTime = 60.0 / RPM;
	this->cycleThermalPower = cycleThermalPower;
	this->cycleElectricalPower = cycleElectricalPower;
}


//Constructor
Cycle::Cycle(int cycleNum, std::vector<CalculatedData>calculatedDataList)
{
	this->cycleNum = cycleNum;
	this->calculatedDataList = calculatedDataList;
}

Cycle::Cycle(int cycleNum, std::vector<CalculatedData> calculatedDataList, double cycleTime, 
	double sumOfCycleWork, double avgAngularVelocity,double avgAngularAcceleration, 
	double cycleThermalPower, double cycleElectricalPower)
{
	this->cycleNum = cycleNum;
	this->calculatedDataList = calculatedDataList;
	this->cycleTime = cycleTime;
	this->sumOfCycleWork = sumOfCycleWork;
	this->avgAngularVelocity = avgAngularVelocity;
	this->avgAngularAcceleration = avgAngularAcceleration;
	this->cycleThermalPower = cycleThermalPower;
	this->cycleElectricalPower = cycleElectricalPower;
}

//Copy Constructor
Cycle::Cycle(const Cycle &c)
{
	this->calculatedDataList = c.calculatedDataList;
	this->avgAngularAcceleration = c.avgAngularAcceleration;
	this->avgAngularVelocity = c.avgAngularVelocity;
	this->cycleElectricalPower = c.cycleElectricalPower;
	this->cycleNum = c.cycleNum;
	this->cycleThermalPower = c.cycleThermalPower;
	this->cycleTime = c.cycleTime;
	this->sumOfCycleWork = c.sumOfCycleWork;
}

//operator =
Cycle& Cycle::operator = (const Cycle& c)
{
	if (this == &c)
		return *this;
	this->calculatedDataList = c.calculatedDataList;
	this->avgAngularAcceleration = c.avgAngularAcceleration;
	this->avgAngularVelocity = c.avgAngularVelocity;
	this->cycleElectricalPower = c.cycleElectricalPower;
	this->cycleNum = c.cycleNum;
	this->cycleThermalPower = c.cycleThermalPower;
	this->cycleTime = c.cycleTime;
	this->sumOfCycleWork = c.sumOfCycleWork;

}



//Destructor
Cycle::~Cycle()
{

}

int Cycle::getCycleNum()
{
	return cycleNum;
}
double Cycle::getAngularVelocity()
{
	return avgAngularVelocity;
}
double Cycle::getAngularAcceleration()
{
	return avgAngularAcceleration;
}
double Cycle::getCycleThermalPower()
{
	return cycleThermalPower;
}
double Cycle::getCycleElectricalPower()
{
	return cycleElectricalPower;
}

double Cycle::getCycleTime()
{
	return cycleTime;
}

void Cycle::setCycleWork(double sumOfCycleWork)
{
	this->sumOfCycleWork = sumOfCycleWork;
}

void Cycle::setCycleThermalPower(double cycleThermalPower)
{
	this->cycleThermalPower = cycleThermalPower;
}

std::vector<CalculatedData> Cycle::getCalculatedDataList()
{
	return calculatedDataList;
}
double Cycle::getSumOfCycleWork()
{
	return sumOfCycleWork;
}



void Cycle::printCycle()
{
	std::cout << "cycleNum:" << cycleNum;
	std::cout << ",startTime:" << calculatedDataList[0].getElapsedTime();
	std::cout << ",cycleTime:" << cycleTime;
	//cout << ",angularVelocity:" << avgAngularVelocity;
	//cout << ",angularAcceleration:" << avgAngularAcceleration;
	std::cout << "thermalPower:" << cycleThermalPower;
	std::cout << ",electricalPower:" << cycleElectricalPower;
	std::cout << std::endl;
	//for (int i = 0; i < calculatedDataList.size(); i++)
		//calculatedDataList[i].printData();
}
double Cycle::getRPM()
{
	return 60.0 / cycleTime;
}

