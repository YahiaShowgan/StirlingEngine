#pragma once
#include <iostream>

//using namespace std;

class RawData
{
protected:
	double elapsedTime, degree, pressure, current, wattage, voltage;

public:
	//Contructor
	RawData(double, double, double, double, double, double);
	RawData(double current, double wattage);
	//Copy Contructor
	RawData(const RawData&);
	//Constructor
	RawData();
	//Destructor
	~RawData();
	//Operator =
	RawData& operator = (const RawData&);
	//print info of data
	virtual void printData();


	double getElapsedTime();
	double getDegree();
	double getPressure();
	double getCurrent();
	double getWattage();
	double getVoltage();

};
