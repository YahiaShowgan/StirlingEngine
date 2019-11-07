#include "RawData.h"


RawData::RawData(double elapsedTime, double degree, double pressure, double current, double wattage, double voltage)
{
	if (elapsedTime < 0)
		throw std::invalid_argument("negative time");
	this->elapsedTime= elapsedTime;
	this->degree = degree;
	this->pressure = pressure;
	this->current = current;
	this->wattage = wattage;
	this->voltage = voltage;
}
RawData::RawData(double current, double wattage)
{
	this->current = current;
	this->wattage = wattage;
}
RawData::RawData()
{
	this->elapsedTime = 0;
	this->degree = 0;
	this->pressure = 0;
	this->current = 0;
	this->wattage = 0;
	this->voltage = 0;
}

RawData::RawData(const RawData& data)
{
	this->elapsedTime = data.elapsedTime;
	this->degree = data.degree;
	this->pressure = data.pressure;
	this->current = data.current;
	this->wattage = data.wattage;
	this->voltage = data.voltage;
}

RawData::~RawData()
{

}

RawData& RawData::operator = (const RawData& data)
{
	if (this == &data)
		return *this;
	this->elapsedTime = data.elapsedTime;
	this->degree = data.degree;
	this->pressure = data.pressure;
	this->current = data.current;
	this->wattage = data.wattage;
	this->voltage = data.voltage;
	return *this;
}

void RawData::printData()
{
	std::cout;
	std::cout << "\n elapsed time:" << elapsedTime;
	std::cout << " degree:" << degree;
	std::cout << " pressure:" << pressure;
	std::cout << " current:" << current;
	std::cout << " wattage:" << wattage;
	std::cout << " voltage:" << voltage;
}

double RawData::getElapsedTime()
{
	return elapsedTime;
}
double RawData::getDegree()
{
	return degree;
}
double RawData::getPressure()
{
	return pressure;
}
double RawData::getCurrent()
{
	return current;
}
double RawData::getWattage()
{
	return wattage;
}
double RawData::getVoltage()
{
	return voltage;
}