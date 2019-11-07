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


class DataController
{

public:
	DataController();

	static std::vector<RawData> dataList;	
	static std::vector <CalculatedData> calculatedDataList;
	static std::vector <Cycle> cycleList;
	static std::vector <Cycle> averageCycleList;
	static std::vector <RawData> averageElectricalPowerByCurrentList;
	static bool firstGlut;
	//input: path of excel file (csv) that has data exported from Pasco's software.
	//output: return a list of data from the file.
	static void getDataFromExcel(std::string path, int runNum);

	//input: path of excel file (csv) that has data exported from Pasco's software.
	//output: how many runs in the experiment. also check if file is valid.
	static int getExcelRunCount(std::string path);

	//input: a string that consists of words seperated by commas.
	//output: a vector of the words.
	static std::vector<std::string> getStringVectorFromLine(std::string line);

	//input: a vector of strings and and string to search for.
	//output: the index of the string in the vector.
	static int getIndexOfStr(std::vector<std::string> strList, std::string str);

	//input: a vector of Data.
	//output: a calculated vector of CalculatedData.
	static std::vector<CalculatedData> calculateData(std::vector<RawData> dataList, EngineInfo engineInfo);

	static double modulo(double, double);

	std::vector<Cycle> calculateCycles(std::vector <CalculatedData> calculatedData);
	double calculateCycleWork(Cycle c);
	static std::vector<Cycle> getAverageCycles(std::vector <Cycle> cycleList); //Average Power of same RPM cycles
	static std::vector<RawData> averageElectricalPowerByCurrent(std::vector <RawData> dataList);
};