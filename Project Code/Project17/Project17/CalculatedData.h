#pragma once
#include "RawData.h"
#define _USE_MATH_DEFINES
#include <math.h>

class CalculatedData :public RawData
{
private:
	int cycleNum, cycleStage;
	double normalizedDegree, cylinderVolume,workBetweenStages;
public:
	//Contructor
	CalculatedData();
	//Copy Contructor
	CalculatedData(const CalculatedData&);
	//Contructor
	CalculatedData(RawData& , int, int, double, double, double);
	//Contructor
	CalculatedData(double elapsedTime, double degree, double pressure,
		double current, double wattage, double voltage, int cycleNum, int cycleStage,
		double normalizedDegree, double cylinderVolume, double workBetweenStages);

	//Operator =
	CalculatedData& operator = (const CalculatedData&);
	//Destructor
	~CalculatedData();
	void printData();
	int getCycleNum();
	int getCycleStage();
	double getNormalizedDegree();
	double getCylinderVolume();	
	double getWorkBetweenStages();

};
