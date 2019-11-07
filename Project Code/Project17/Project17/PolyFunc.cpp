#include "PolyFunc.h"
#include <iostream>
#include <vector>

PolyFunc::PolyFunc(double thirdDeg, double secondDeg, double firstDeg, double zeroDeg, double startX, double endX)
{
	this->thirdDeg = thirdDeg;
	this->secondDeg = secondDeg;
	this->firstDeg = firstDeg;
	this->zeroDeg = zeroDeg;
	this->startX = startX;
	this->endX = endX;
}

PolyFunc::PolyFunc()
{
	this->thirdDeg = 0;
	this->secondDeg = 0;
	this->firstDeg = 0;
	this->zeroDeg = 0;
	this->startX = 0;
	this->endX = 0;
}

PolyFunc::~PolyFunc()
{

}

PolyFunc::PolyFunc(const PolyFunc& pf)
{
	this->startX = pf.startX;
	this->endX = pf.endX;
	this->thirdDeg = pf.thirdDeg;
	this->secondDeg = pf.secondDeg;
	this->firstDeg = pf.firstDeg;
	this->zeroDeg = pf.zeroDeg;
}

PolyFunc& PolyFunc::operator = (const PolyFunc& pf)
{
	if (this == &pf)
		return *this;
	this->startX = pf.startX;
	this->endX = pf.endX;
	this->thirdDeg = pf.thirdDeg;
	this->secondDeg = pf.secondDeg;
	this->firstDeg = pf.firstDeg;
	this->zeroDeg = pf.zeroDeg;
	return *this;

}

void PolyFunc::printPoly()
{
	std:: cout << thirdDeg << "x^3 +" << secondDeg << "x^2 +" << firstDeg << "x +" << zeroDeg;
	std:: cout << "		(" << startX << "," << endX <<")";
	std::cout<<"\n";
}
double PolyFunc::getThirdDeg()
{
	return thirdDeg;
}
double PolyFunc::getSecondDeg()
{
	return secondDeg;
}
double PolyFunc::getFirstDeg()
{
	return firstDeg;
}
double PolyFunc::getZeroDeg()
{
	return zeroDeg;
}
double PolyFunc::getStartX()
{
	return startX;
}
double PolyFunc::getEndX()
{
	return endX;
}