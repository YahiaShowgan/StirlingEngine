#include "EngineInfo.h"

using namespace std;

EngineInfo::EngineInfo(){};
EngineInfo::EngineInfo(const EngineInfo& ei)
{
	this->hotPistonArea = ei.hotPistonArea;
	this->hotMinCylinderVolume = ei.hotMinCylinderVolume;
	this->hotCrankShaftRadius = ei.hotCrankShaftRadius;
	this->coldPistonArea = ei.coldPistonArea;
	this->coldMinCylinderVolume = ei.coldMinCylinderVolume;
	this->coldCrankShaftRadius = ei.coldCrankShaftRadius;
}
EngineInfo::EngineInfo(double hotPistonArea, double hotMinCylinderVolume, double hotCrankShaftRadius,
	double coldPistonArea,double coldMinCylinderVolume, double coldCrankShaftRadius)
{
	if ((hotPistonArea <= 0) || (coldPistonArea <= 0) || (hotMinCylinderVolume <= 0) || (coldMinCylinderVolume <= 0) ||
		(coldCrankShaftRadius <= 0) || (hotCrankShaftRadius <= 0))
		throw invalid_argument("Negative arguments");
	this->hotPistonArea = hotPistonArea;
	this->hotMinCylinderVolume = hotMinCylinderVolume;
	this->hotCrankShaftRadius = hotCrankShaftRadius;
	this->coldPistonArea = coldPistonArea;
	this->coldMinCylinderVolume = coldMinCylinderVolume;
	this->coldCrankShaftRadius = coldCrankShaftRadius;
}
EngineInfo::~EngineInfo()
{

}

EngineInfo& EngineInfo::operator = (const EngineInfo& ei)
{
	if (this == &ei)
		return *this;
	this->hotPistonArea = ei.hotPistonArea;
	this->hotMinCylinderVolume = ei.hotMinCylinderVolume;
	this->hotCrankShaftRadius = ei.hotCrankShaftRadius;
	this->coldPistonArea = ei.coldPistonArea;
	this->coldMinCylinderVolume = ei.coldMinCylinderVolume;
	this->coldCrankShaftRadius = ei.coldCrankShaftRadius;
	return *this;
}

double EngineInfo::getHotPistonArea()
{
	return hotPistonArea;
}
double EngineInfo::getHotMinCylinderVolume()
{
	return hotMinCylinderVolume;
}
double EngineInfo::getHotCrankShaftRadius()
{
	return hotCrankShaftRadius;
}
double EngineInfo::getColdPistonArea()
{
	return coldPistonArea;
}
double EngineInfo::getColdMinCylinderVolume()
{
	return coldMinCylinderVolume;
}
double EngineInfo::getColdCrankShaftRadius()
{
	return coldCrankShaftRadius;
}