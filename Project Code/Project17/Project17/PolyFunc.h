#pragma once
class PolyFunc
{
	double thirdDeg, secondDeg, firstDeg, zeroDeg;
	double startX, endX;
public:
	//Constructor
	PolyFunc(double thirdDeg, double secondDeg, double firstDeg,
		double zeroDeg, double startX, double endX);
	//Constructor
	PolyFunc();
	//Copy Contructor
	PolyFunc(const PolyFunc&);
	//Destructor
	~PolyFunc();
	//Operator =
	PolyFunc& operator = (const PolyFunc&);
	//Prints Poly Info
	void printPoly();
	double getThirdDeg();
	double getSecondDeg();
	double getFirstDeg();
	double getZeroDeg();
	double getStartX();
	double getEndX();
};