#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>

class EngineInfo
{
private:
	double hotPistonArea, hotMinCylinderVolume, hotCrankShaftRadius;//radius is in mm
	double coldPistonArea, coldMinCylinderVolume, coldCrankShaftRadius;//radius is in mm

public:
	EngineInfo();
	EngineInfo(const EngineInfo&);
	EngineInfo(double hotPistonArea,double hotMinCylinderVolume,double hotCrankShaftRadius, 
		double coldPistonArea, double coldMinCylinderVolume, double coldCrankShaftRadius);
	~EngineInfo();
	//Operator =
	EngineInfo& operator = (const EngineInfo&);
	double getHotPistonArea();
	double getHotMinCylinderVolume();
	double getHotCrankShaftRadius();
	double getColdPistonArea();
	double getColdMinCylinderVolume();
	double getColdCrankShaftRadius();
};
