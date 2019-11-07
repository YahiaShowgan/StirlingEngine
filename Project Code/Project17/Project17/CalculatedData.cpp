#include "CalculatedData.h"
using namespace std;
CalculatedData::CalculatedData() :RawData()
{
	this->cycleNum = 0;
	this->cycleStage = 0;
	this->normalizedDegree = 0;
	this->cylinderVolume = 0;
	this->workBetweenStages = 0;
}
CalculatedData::CalculatedData(const CalculatedData& cd) :RawData(cd.elapsedTime, cd.degree, cd.pressure, cd.current, cd.wattage, cd.voltage)
{
	this->cycleNum = cd.cycleNum;
	this->cycleStage = cd.cycleStage;
	this->normalizedDegree = cd.normalizedDegree;
	this->cylinderVolume = cd.cylinderVolume;
	this->workBetweenStages = cd.workBetweenStages;
}

CalculatedData::CalculatedData(RawData& data, int cycleNum, int cycleStage, double normalizedDegree, double cylinderVolume, double workBetweenStages) : RawData(data)
{
	if ((cycleNum < 0) || (cycleStage < 0) || (normalizedDegree > (2 * M_PI + 0.01)))
		throw invalid_argument("invalid arguments");
	this->cycleNum = cycleNum;
	this->cycleStage = cycleStage;
	this->normalizedDegree = normalizedDegree;
	this->cylinderVolume = cylinderVolume;
	this->workBetweenStages = workBetweenStages;
}

CalculatedData::CalculatedData(double elapsedTime, double degree, double pressure,
	double current, double wattage, double voltage, int cycleNum, int cycleStage, 
	double normalizedDegree, double cylinderVolume, double workBetweenStages):
	RawData(elapsedTime, degree, pressure, current, wattage, voltage)
{
	if ((cycleNum < 0) || (cycleStage < 0) || (normalizedDegree >(2 * M_PI + 0.01)))
		throw invalid_argument("invalid arguments");
	this->cycleNum = cycleNum;
	this->cycleStage = cycleStage;
	this->normalizedDegree = normalizedDegree;
	this->cylinderVolume = cylinderVolume;
	this->workBetweenStages = workBetweenStages;
}
CalculatedData::~CalculatedData()
{

}

CalculatedData& CalculatedData::operator = (const CalculatedData& cd)
{
	if (this == &cd)
		return *this;
	this->cycleNum = cd.cycleNum;
	this->cycleStage = cd.cycleStage;
	this->normalizedDegree = cd.normalizedDegree;
	this->cylinderVolume = cd.cylinderVolume;
	this->workBetweenStages = cd.workBetweenStages;
	return *this;
}

double CalculatedData::getCylinderVolume()
{
	return cylinderVolume;
}

int CalculatedData::getCycleNum()
{
	return cycleNum;
}
int CalculatedData::getCycleStage()
{
	return cycleStage;
}
double CalculatedData::getNormalizedDegree()
{
	return normalizedDegree;
}
double CalculatedData::getWorkBetweenStages()
{
	return workBetweenStages;
}

void CalculatedData::printData()
{
	RawData::printData();
	std::cout << " \ncycleNum:" <<cycleNum ;
	std::cout << " cycleStage:" << cycleStage;
	std::cout << " normalizedDegree:" << normalizedDegree;
	std::cout << " cylinderVolume:" << cylinderVolume;
	std::cout << " workBetweenStages:" << workBetweenStages;

}