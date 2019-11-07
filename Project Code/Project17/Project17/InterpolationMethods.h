#pragma once
#include <vector>
#include <iostream>
#include "RawData.h"
#include "EngineInfo.h"
#include "CalculatedData.h"
#include <sstream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "PolyFunc.h"
#include "Cycle.h"
#include "InterpolationMethods.h"
#include <math.h>
class InterpolationMethods
{
public:
	static std::vector<double> thomasAlg(std::vector<std::vector<double>> mat, std::vector <double> vec);
	static std::vector<PolyFunc> interpolateSplines(std::vector <double> xVals, std::vector <double> yVals);
	static std::vector<double> InterpolationMethods::deCasteljau(std::vector <double>xVals, std::vector<double>yVals, float t);
	static double findFuncValue(std::vector<PolyFunc> func, double x);
	static double findFuncMax(std::vector<PolyFunc> func);
	static std::vector<double> solveQuadraticFormula(PolyFunc poly);
	static double findAreaUnderPolyList(std::vector<PolyFunc> func);
};