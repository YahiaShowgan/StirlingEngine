#include "DataController.h"
#include <algorithm>

std::vector<RawData> DataController::dataList;//initialize
std::vector <CalculatedData> DataController::calculatedDataList;//initialize
std::vector <Cycle> DataController::cycleList;//initialize
std::vector <Cycle> DataController::averageCycleList;//initialize
std::vector <RawData> DataController::averageElectricalPowerByCurrentList;//initialize
bool DataController::firstGlut = true;

DataController::DataController()
{
	
}

//input: path of csv file and number of run wanted to import.
//output: list of data from file and given run. 
void DataController::getDataFromExcel(std::string path, int runNum)
{
	
	if (path.length() < 5)
		throw std::exception ("file path too short exception.");
	if ((path[path.length() - 1] != 'v') || (path[path.length() - 2] != 's')
		|| (path[path.length() - 3] != 'c') || (path[path.length() - 4] != '.'))
		throw std::exception ("file type exception, it has to be csv.");
	std::vector<std::string> strList;
	std::string tempStr = "";
	int count = 0,i=0;
	int indexElapsedTime;
	int indexDegree;
	int indexPressure;
	int indexCurrent;
	int indexWattage;
	int indexVoltage;
	std::ifstream infile;
	std::ifstream testfile;
	std::ios_base::iostate exceptionMask = testfile.exceptions() | std::ios::failbit;
	testfile.exceptions(exceptionMask);
	try
	{
		testfile.open(path);
		testfile.close();
		infile.open(path);
	}
	catch (std::ios_base::failure& e)
	{
		throw std::exception ("non existant file or error reading");
	}
	std::string line;
	int runCount;
	try
	{
		runCount = getExcelRunCount(path);//Get how many runs where in the file
	}
	catch (std::exception e)
	{
		throw std::exception (e.what());
	}
	if ((runNum > runCount) ||(runNum<1))
		throw std::exception("Non existent run");
	getline(infile, line, '\n');
	int dataCount = (getStringVectorFromLine(line)).size()/runCount;
	getline(infile, line, '\n');
	strList=getStringVectorFromLine(line);
	try //get index of every wanted value.
	{
		indexElapsedTime = getIndexOfStr(strList, "Time (s)");
		indexDegree = getIndexOfStr(strList, "Angle (rad)");
		indexPressure = getIndexOfStr(strList, "Absolute Pressure (kPa)");
		indexCurrent = getIndexOfStr(strList, "Current (A)");
		indexWattage = getIndexOfStr(strList, "Power (W)");
		indexVoltage = getIndexOfStr(strList, "Voltage (V)");
	}
	catch (std::exception e)
	{
		throw std::exception("One of the values is not found in excel");
	}
	int startIndex = (runNum - 1) * dataCount; //Where the specific run starts from.
	while (getline(infile, line, '\n'))//untill the last line.
	{
		if (line.size() == 0)//empty line.
			break;
		strList = getStringVectorFromLine(line);
		try
		{
			double elapsedTime = stod(strList[startIndex + indexElapsedTime]);
			double degree = stod(strList[startIndex + indexDegree]);
			double pressure = 1000.0*stod(strList[startIndex + indexPressure]);//KPa too Pa
			double current = stod(strList[startIndex + indexCurrent]);
			double wattage = stod(strList[startIndex + indexWattage]);
			double voltage = stod(strList[startIndex + indexVoltage]);
			RawData data = RawData(elapsedTime, degree, pressure, current, wattage, voltage);
			dataList.push_back(data);
		}
		catch(std::exception e)
		{
			const char* str = e.what();
			if (strcmp("invalid stod argument", str) == 0)
				break;
		}
	}
	return;
}


//input: a string of words.
//output: a vector of the words.
std::vector<std::string> DataController::getStringVectorFromLine(std::string line)
{
	std::vector<std::string> strList;
	std::string tempStr = "";
	int i = 0;
	//get a list of words in our vector strList.
	while (i<line.size())
	{
		if (line[i] == ',')//words are seperated by commas
		{
			strList.push_back(tempStr);
			tempStr = "";
		}
		else
			tempStr += line[i];
		i++;
	}
	strList.push_back(tempStr);
	return strList;
}



//input: path of excel file (csv) that has data exported from Pasco's software.
//output: how many runs in the experiment. also check if file is valid.
int DataController::getExcelRunCount(std::string path)
{
	std::vector<std::string> strList;
	int count = 0;
	std::ifstream infile(path);
	std::string line;
	getline(infile, line, '\n'); //get first line 
	strList = getStringVectorFromLine(line);
	std::string run = "Run #1";
	int firstRun = 1;
	int dataCount = 0;
	for (int i = 0; i < strList.size(); i++)
	{
		if ((!firstRun)&&(i % dataCount == 0))
		{
			count++;
			run = "Run #";
			run.append(std::to_string(count+1));
		}
		if (run.compare(strList[i]) != 0) //first line should be all Run# and numbers.
		{
			if (firstRun)
			{
				firstRun = 0;
				count++;
				run = "Run #";
				run.append(std::to_string(count+1));
			}
			else
				throw std::exception("Problem with runs");
		}
		else
		{
			if (firstRun)
				dataCount++;
		}
	}
	return count+1;
}

//input: get a vector of strings and a word to find.
//output: return index of the word in our vector.
int DataController::getIndexOfStr(std::vector<std::string> strList, std::string str)
{
	for (int i = 0; i < strList.size(); i++)
		if (str.compare(strList[i]) == 0)//word found.
			return i;
	throw std::exception("String not found in vector"); //word isn't in our vector.
}

double DataController::modulo(double num1, double num2)
{
	return num1- num2*((floor)(num1 / num2));
}


//input: get vector of data and engine info.
//output: return a vector of calculated data from the data vector.
std::vector<CalculatedData> DataController::calculateData(std::vector<RawData> dataList, EngineInfo engineInfo)
{
	std::vector<CalculatedData> calculatedDataList;
	if (dataList.size() <= 2000)
	{
		throw std::exception("Experiment should be at least 10 seconds long.");
	}
	double cycleStartDeg = dataList[100].getDegree()- modulo(dataList[100].getDegree(), 2 * M_PI);
	int cycleNum=1, cycleStage=1;
	double normalizedDegree, hotCylinderVolume, coldCylinderVolume, absolutePressure, workBetweenStages;
	double cylinderVolume;
	int j = 0;
	for (int i = 100; i < dataList.size(); i++) //start from 100 to exclude negative angles in the first seconds. 
	{
		if (dataList[i].getDegree() >= cycleStartDeg + 2 * M_PI)//new cycle started.
		{
			cycleNum++;
			cycleStage = 1; //first stage of new cycle
			cycleStartDeg += 2 * M_PI;
		}
		else
		{
			cycleStage++;
		}
		normalizedDegree = dataList[i].getDegree() - cycleStartDeg;
		hotCylinderVolume = (engineInfo.getHotPistonArea()*(cos(normalizedDegree)*engineInfo.getHotCrankShaftRadius() 
			+ engineInfo.getHotCrankShaftRadius()) + engineInfo.getHotMinCylinderVolume()) / 1000000000;

		coldCylinderVolume = (engineInfo.getColdPistonArea()*(cos(normalizedDegree)*engineInfo.getColdCrankShaftRadius() 
			+ engineInfo.getColdCrankShaftRadius()) + engineInfo.getColdMinCylinderVolume()) / 1000000000;

		cylinderVolume = hotCylinderVolume + coldCylinderVolume;
		if (i == 100)
			workBetweenStages = 0;//first stage of the first cycle.
		else
			workBetweenStages= ((dataList[i].getPressure()+dataList[i-1].getPressure())/2)*(cylinderVolume-calculatedDataList[j-1].getCylinderVolume());
		calculatedDataList.push_back(CalculatedData(dataList[i], cycleNum, cycleStage, normalizedDegree, cylinderVolume, workBetweenStages));
		j++;//count calculated data.
	}
	return calculatedDataList;
}


//input: vector of calculated data.
//output: vector of the cycles with 0 angular acceleration containing lists of calculated data.
std::vector<Cycle> DataController::calculateCycles(std::vector <CalculatedData> calculatedDataList)
{
	std::vector<Cycle> cycleList;
	int i = 0;
	int j = 0;
	int countStages;
	double cycleWork;
	double avgAngularVelocity;
	double sumWattage;
	double cycleElectricalPower;
	double cycleTime,rpm,cyclePower, avgAngularAcceleration=-1;
	double cycleNum;
	//start at a beginning of a cycle.
	while ((calculatedDataList[i].getCycleStage() != 1) && (i<calculatedDataList.size()))
		i++;
	double prevRPM=-1;
	while (i < calculatedDataList.size())
	{
		cycleNum = calculatedDataList[i].getCycleNum();
		cycleWork = 0;
		countStages = 0;
		sumWattage = 0;
		std::vector<CalculatedData> cycleCalculatedData;
		//from start to the end of a specific cycle.
		while ((i < calculatedDataList.size())&&(calculatedDataList[i].getCycleNum() == cycleNum))
		{
			//cycleWork without the interpolation.
			cycleWork += calculatedDataList[i].getWorkBetweenStages();
			//keep a list of calculated data in cycle.
			cycleCalculatedData.push_back(calculatedDataList[i]);
			countStages++;
			sumWattage += calculatedDataList[i].getWattage();
			i++;
		}
		cycleTime = countStages*0.005;//stages*time per stage.
		cycleElectricalPower = sumWattage / (double)countStages;//avg
		rpm = 60.0 / cycleTime;//RPM= 60/T
		cyclePower = cycleWork / cycleTime;
		if (j != 0)
		{
			avgAngularAcceleration = (rpm - prevRPM) / cycleTime;
		}
		else
			avgAngularAcceleration = -1;//first one.
		avgAngularVelocity = (2 * M_PI) / cycleTime;

		if (avgAngularAcceleration == 0)
		{		
			//return only cycles with 0 angular acceleration.
			Cycle c(cycleNum, cycleCalculatedData, cycleTime, cycleWork, avgAngularVelocity,
			avgAngularAcceleration, cyclePower, cycleElectricalPower);
			c.setCycleWork(calculateCycleWork(c));
			c.setCycleThermalPower(c.getSumOfCycleWork() / c.getCycleTime());
			if (cycleNum == 74)
			{
				for (int i = 0; i < cycleCalculatedData.size(); i++)
					std::cout << cycleCalculatedData[i].getCylinderVolume() << std::endl;
				for (int i = 0; i < cycleCalculatedData.size(); i++)
					std::cout << cycleCalculatedData[i].getPressure() << std::endl;
			}
			cycleList.push_back(c);
		}
		prevRPM = rpm;
		j++;
	}
	return cycleList;
}

double DataController::calculateCycleWork(Cycle c)
{
	InterpolationMethods interpolationMethods;
	std::vector<CalculatedData> calculatedDataList= c.getCalculatedDataList();
	double  workBetweenStages;
	double t;
	double step = 0.01;
	std::vector <double>xValsInitial;
	std::vector<double>yValsInitial;
	for (int i = 0; i < calculatedDataList.size(); i++)
	{
		xValsInitial.push_back(calculatedDataList[i].getCylinderVolume());
		yValsInitial.push_back(calculatedDataList[i].getPressure());
	}
	std::vector <double>xVals;
	std::vector<double>yVals;
	//find the smallest x in xValsInitial
	int minIndex=std::min_element(xValsInitial.begin(), xValsInitial.end()) - xValsInitial.begin();
	for (int i = minIndex; i < xValsInitial.size(); i++)
	{
		xVals.push_back(xValsInitial[i]);
		yVals.push_back(yValsInitial[i]);
	}
	for (int i = 0; i < minIndex; i++)
	{
		xVals.push_back(xValsInitial[i]);
		yVals.push_back(yValsInitial[i]);
	}
	xVals.push_back(xVals[0]); yVals.push_back(yVals[0]);
	int i;
	for (i = 0; i < xVals.size() - 1; i++)
	{
		if (xVals[i] > xVals[i + 1])
			break;
	}
	std::vector<double>xVals1(xVals.begin(), xVals.begin() + i + 1);
	std::vector<double>yVals1(yVals.begin(), yVals.begin() + i + 1);

	std::vector<double>xVals2(xVals.begin() + i, xVals.end());
	std::vector<double>yVals2(yVals.begin() + i, yVals.end());
	std::reverse(xVals2.begin(), xVals2.end());
	std::reverse(yVals2.begin(), yVals2.end());

	std::vector<PolyFunc> polyList1 = InterpolationMethods::interpolateSplines(xVals1, yVals1);
	std::vector<PolyFunc> polyList2 = InterpolationMethods::interpolateSplines(xVals2, yVals2);

	double area1 = InterpolationMethods::findAreaUnderPolyList(polyList1);
	double area2 = InterpolationMethods::findAreaUnderPolyList(polyList2);
	double areaInClosedCurve = abs(abs(area1) - abs(area2));
	return areaInClosedCurve;
}



std::vector<Cycle> DataController::getAverageCycles(std::vector <Cycle> cycleList)
{
	std::vector<Cycle> averageCycles;
	std::sort(cycleList.begin(), cycleList.end());
	double rpm = cycleList[0].getRPM();
	int count=1;
	double powerSum=cycleList[0].getCycleThermalPower();
	double electricalPowerSum = cycleList[0].getCycleElectricalPower();
	for (int i = 1; i < cycleList.size(); i++)
	{
		if (cycleList[i].getRPM() != rpm)
		{
			Cycle c(rpm, powerSum / (double)count, electricalPowerSum/(double)count);
			averageCycles.push_back(c);
			rpm = cycleList[i].getRPM();
			count = 1;
			powerSum = cycleList[i].getCycleThermalPower();
			electricalPowerSum = cycleList[i].getCycleElectricalPower();
		}
		else
		{
			count++;
			powerSum += cycleList[i].getCycleThermalPower();
			electricalPowerSum += cycleList[i].getCycleElectricalPower();
		}
	}
	return averageCycles;
}



std::vector<RawData> DataController::averageElectricalPowerByCurrent(std::vector <RawData> dataList)
{
	std::vector<RawData> averageData;
	std::sort(dataList.begin(), dataList.end(),
		[](RawData & d1, RawData & d2) -> bool
	{
		return d1.getCurrent() < d2.getCurrent();
	});

	double current = dataList[0].getCurrent();
	int count = 1;
	double powerSum = dataList[0].getWattage();
	for (int i = 1; i < dataList.size(); i++)
	{
		if (dataList[i].getCurrent() != current)
		{
			if (current >= 0)
			{
				RawData d(current, powerSum / (double)count);
				averageData.push_back(d);
			}
			current = dataList[i].getCurrent();
			count = 1;
			powerSum = dataList[i].getWattage();
		}
		else
		{
			count++;
			powerSum += dataList[i].getWattage();
		}
	}
	return averageData;
}