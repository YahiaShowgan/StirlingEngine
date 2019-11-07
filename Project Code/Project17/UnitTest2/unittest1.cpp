#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project17/EngineInfo.h"
#include "../Project17/EngineInfo.cpp"
#include "../Project17/RawData.h"
#include "../Project17/RawData.cpp"
#include "../Project17/PolyFunc.h"
#include "../Project17/PolyFunc.cpp"
#include "../Project17/CalculatedData.h"
#include "../Project17/CalculatedData.cpp"
#include "../Project17/DataController.h"
#include "../Project17/DataController.cpp"
#include "../Project17/Cycle.h"
#include "../Project17/Cycle.cpp"
#include "../Project17/InterpolationMethods.h"
#include "../Project17/InterpolationMethods.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTestEngineInfo)
	{
	public:
		/*
		//Test EngineInfo class.
		*/
		TEST_METHOD(TestEngineInfoConstructorValid)
		{
			EngineInfo engineInfo(1, 2, 3, 4, 5, 6);
			Assert::AreEqual(engineInfo.getHotPistonArea(), 1.0);
			Assert::AreEqual(engineInfo.getHotMinCylinderVolume(), 2.0);
			Assert::AreEqual(engineInfo.getHotCrankShaftRadius(), 3.0);
			Assert::AreEqual(engineInfo.getColdPistonArea(), 4.0);
			Assert::AreEqual(engineInfo.getColdMinCylinderVolume(), 5.0);
			Assert::AreEqual(engineInfo.getColdCrankShaftRadius(), 6.0);
		}

		//negative values.
		TEST_METHOD(TestEngineInfoConstructorInvalid)
		{
			bool exceptionThrown = false;
			try
			{
				EngineInfo engineInfo(1, 2, -3, 4, 5, 6);
			}
			catch (invalid_argument e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);	
		}


		/*
		//Test Data class.
		*/

		TEST_METHOD(TestRawDataConstructorValid)
		{
			RawData data(1, 2, 3, 4, 5, 6);
			Assert::AreEqual(1.0, data.getElapsedTime());
			Assert::AreEqual(2.0, data.getDegree());
			Assert::AreEqual(3.0, data.getPressure());
			Assert::AreEqual(4.0, data.getCurrent());
			Assert::AreEqual(5.0, data.getWattage());
			Assert::AreEqual(6.0, data.getVoltage());
		}

		//negative values.
		TEST_METHOD(TestRawDataConstructorNegativeTime)
		{
			bool exceptionThrown = false;
			try
			{
				EngineInfo engineInfo(-1, 2, -3, 4, 5, 6);
			}
			catch (invalid_argument e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}





		/*
		//Test CalculatedData class.
		*/
		TEST_METHOD(TestCalculatedDataConstructorValid)
		{
			CalculatedData calculatedData(1, 2, 3, 4, 5, 6, 7, 8, 2, 10,11);
			Assert::AreEqual(1.0, calculatedData.getElapsedTime());
			Assert::AreEqual(2.0, calculatedData.getDegree());
			Assert::AreEqual(3.0, calculatedData.getPressure());
			Assert::AreEqual(4.0, calculatedData.getCurrent());
			Assert::AreEqual(5.0, calculatedData.getWattage());
			Assert::AreEqual(6.0, calculatedData.getVoltage());
			Assert::AreEqual(7, calculatedData.getCycleNum());
			Assert::AreEqual(8, calculatedData.getCycleStage());
			Assert::AreEqual(2.0, calculatedData.getNormalizedDegree());
			Assert::AreEqual(10.0, calculatedData.getCylinderVolume());
			Assert::AreEqual(11.0, calculatedData.getWorkBetweenStages());
		}

		//normalized degree > 2 pi
		TEST_METHOD(TestCalculatedDataConstructorInvalidDegree)
		{
			double invalidNormalizedDegree = 50; //has to be less than 2 pi.
			bool exceptionThrown = false;
			try
			{
				CalculatedData calculatedData(1, 2, 3, 4, 5, 6, 7, 
					8, invalidNormalizedDegree, 10, 11);
			}
			catch (invalid_argument e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		//negative cycle stage
		TEST_METHOD(TestCalculatedDataConstructorInvalidCycleStage)
		{
			int invalidCycleStage = -2;//has to be non negative
			bool exceptionThrown = false;
			try
			{
				CalculatedData calculatedData(1, 2, 3, 4, 5, 6, 7,
					-2, 2, 10, 11);
			}
			catch (invalid_argument e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		/*
		DataController tests
		*/
		TEST_METHOD(TestDataControllerImportFromExcelValid)
		{
			DataController dataController;
			dataController.getDataFromExcel
				("C:/Users/Yahia/Dropbox/Experiment.2.1.csv",1);
			double elapsedTime=0.035,degree=0,pressure=175.7*1000,
				current=0,wattage= 1.66E-05,voltage=-0.02;
			RawData data8(elapsedTime, degree, pressure,current, wattage, voltage);
			elapsedTime = 1.66, degree = 92.123, pressure = 207*1000,
				current = -5.35E-04, wattage = 0, voltage = 2.37;
			RawData data333(elapsedTime, degree, pressure, current, wattage, voltage);
			Assert::AreEqual(DataController::dataList[7].getCurrent(),data8.getCurrent());
			Assert::AreEqual(DataController::dataList[7].getDegree(), data8.getDegree());
			Assert::AreEqual(DataController::dataList[7].getElapsedTime(), data8.getElapsedTime());
			Assert::AreEqual(DataController::dataList[7].getPressure(), data8.getPressure());
			Assert::AreEqual(DataController::dataList[7].getVoltage(), data8.getVoltage());
			Assert::AreEqual(DataController::dataList[7].getWattage(), data8.getWattage());

			Assert::AreEqual(DataController::dataList[332].getCurrent(), data333.getCurrent());
			Assert::AreEqual(DataController::dataList[332].getDegree(), data333.getDegree());
			Assert::AreEqual(DataController::dataList[332].getElapsedTime(), data333.getElapsedTime());
			Assert::AreEqual(DataController::dataList[332].getPressure(), data333.getPressure());
			Assert::AreEqual(DataController::dataList[332].getVoltage(), data333.getVoltage());
			Assert::AreEqual(DataController::dataList[332].getWattage(), data333.getWattage());
		}

		TEST_METHOD(TestDataControllerImportFromExcelInvalidType)
		{
			DataController dataController;
			vector<RawData> dataList;
			bool exceptionThrown = false;
			try
			{
				dataController.getDataFromExcel
					("C:/Users/Yahia/Dropbox/IMG_20180615_110341_HDR.jpg", 1);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		TEST_METHOD(TestDataControllerImportFromExcelNonExistantFile)
		{
			DataController dataController;
			vector<RawData> dataList;
			bool exceptionThrown = false;
			try
			{
				dataController.getDataFromExcel
				("C:/Users/Yahia/NonExistantFile.csv", 1);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		TEST_METHOD(TestDataControllerImportFromExcelNonExistantRun)
		{
			DataController dataController;
			vector<RawData> dataList;
			bool exceptionThrown = false;
			try
			{
				dataController.getDataFromExcel
				("C:/Users/Yahia/Dropbox/Experiment.2.1.csv", 3);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}
		TEST_METHOD(TestDataControllerThomasAlgorithmValid)
		{
			InterpolationMethods interpolationMethods;
			double x = 27.0 / 23.0, y = -1.0 / 23.0, z = -31.0 / 23.0, w = 41.0 / 23.0;
			vector < vector<double> >mat = { { 1,4,0,0 },{ 3,4,1,0 } ,{ 0,2,3,4 } ,{ 0,0,1,3 } };
			vector <double> vec = { 1,2,3,4 };
			vector <double> ans;
			ans = interpolationMethods.thomasAlg(mat, vec);
			Assert::AreEqual(((int)(x*10000))/10000.0, ((int)(ans[0] * 10000)) / 10000.0);
			Assert::AreEqual(((int)(y * 10000)) / 10000.0, ((int)(ans[1] * 10000)) / 10000.0);
			Assert::AreEqual(((int)(z * 10000)) / 10000.0, ((int)(ans[2] * 10000)) / 10000.0);
			Assert::AreEqual(((int)(w * 10000)) / 10000.0, ((int)(ans[3] * 10000)) / 10000.0);
		}

		TEST_METHOD(TestDataControllerThomasAlgorithmMatrixNotTridiagonal1)
		{
			bool exceptionThrown = false;
			vector < vector<double> >mat = { { 1,4,0,0 },{ 3,4,1,0 } ,{ 0,2,3,4 } ,{ 0,6,1,3 } };
			vector <double> vec = { 1,2,3,4 };
			InterpolationMethods interpolationMethods;

			vector <double> ans;
			try
			{ 
			ans = interpolationMethods.thomasAlg(mat, vec);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		TEST_METHOD(TestDataControllerThomasAlgorithmMatrixNotTridiagonal2)
		{
			bool exceptionThrown = false;
			vector < vector<double> >mat = { { 1,4,0,0 },{ 3,4,1,9 } ,{ 0,2,3,4 } ,{ 0,0,1,3 } };
			vector <double> vec = { 1,2,3,4 };
			InterpolationMethods interpolationMethods;

			vector <double> ans;
			try
			{
				ans = interpolationMethods.thomasAlg(mat, vec);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		TEST_METHOD(TestDataControllerThomasAlgorithmInvalidMatrixSize1)
		{
			bool exceptionThrown = false;
			vector < vector<double> >mat = { { 1,4,0,0 },{ 3,4,1,0 } ,{ 0,2,3,4 } ,{ 0,0,1,3 } };
			vector <double> vec = { 1,2,3};
			InterpolationMethods interpolationMethods;

			vector <double> ans;
			try
			{
				ans = interpolationMethods.thomasAlg(mat, vec);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		TEST_METHOD(TestDataControllerThomasAlgorithmInvalidMatrixSize2)
		{
			bool exceptionThrown = false;
			vector < vector<double> >mat = { { 1,4,0,0 },{ 3,4,1,0 } ,{ 0,2,3,4 } };
			vector <double> vec = { 1,2,3,4};
			InterpolationMethods interpolationMethods;
			vector <double> ans;
			try
			{
				ans = interpolationMethods.thomasAlg(mat, vec);
			}
			catch (exception e)
			{
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

		TEST_METHOD(TestDataControllerInterpolateSplinesValid)
		{
			InterpolationMethods interpolationMethods;
			vector<double> xVals = { 0,1,2,3,4,5,6 };
			vector<double> yVals = { 0,10,30,10,13,166,122 };
			vector<PolyFunc> expPolyList;
			expPolyList.push_back(PolyFunc(4.9718, -2.5208e-57, 5.0282, 0, 0, 1));
			expPolyList.push_back(PolyFunc(-1.4859e1, 59.492, -54.464, 19.831, 1, 2));
			expPolyList.push_back(PolyFunc(4.4641, -56.446, 1.7741e2, -1.3475e2, 2, 3));
			expPolyList.push_back(PolyFunc(6.0003e1, -5.5629e2, 1.6770e3, -1.6343e3, 3, 4));
			expPolyList.push_back(PolyFunc(-1.1747e2, 1.5734e3, -6.8419e3, 9.7242e3, 4, 5));
			expPolyList.push_back(PolyFunc(6.2895e1, -1.1321e3, 6.6858e3, -1.2822e4, 5, 6));
			DataController dataController;
			vector<PolyFunc> actPolyList = interpolationMethods.interpolateSplines(xVals, yVals);
			Assert::AreEqual(actPolyList.size(), expPolyList.size());
			for (int i = 0; i < actPolyList.size(); i++)
			{
				double error;
				error = abs(actPolyList[i].getThirdDeg() - expPolyList[i].getThirdDeg());
				Assert::IsTrue(error < fmax(0.01,0.01*abs(actPolyList[i].getThirdDeg())));

				error = abs(actPolyList[i].getSecondDeg() - expPolyList[i].getSecondDeg());
				Assert::IsTrue(error<fmax(0.01, 0.01*abs(actPolyList[i].getSecondDeg())));

				error = abs(actPolyList[i].getFirstDeg() - expPolyList[i].getFirstDeg());
				Assert::IsTrue(error<fmax(0.01, abs(0.01*abs(actPolyList[i].getFirstDeg()))));

				error = abs(actPolyList[i].getZeroDeg() - expPolyList[i].getZeroDeg());
				Assert::IsTrue(error<fmax(0.01,0.01*abs(actPolyList[i].getZeroDeg())));
				Assert::IsTrue(abs(actPolyList[i].getStartX()- expPolyList[i].getStartX())<0.01);
				Assert::IsTrue(abs(actPolyList[i].getEndX()- expPolyList[i].getEndX())<0.01);
			}
		}
		TEST_METHOD(TestDataControllerInterpolateSplinesInvalidNumberOfVals)
		{
			vector<double> xVals = { 0,1,2,3,4,5,6 };
			vector<double> yVals = { 0,10,30,10,13,166,122,155 };
			vector<PolyFunc> actPolyList;
			InterpolationMethods interpolationMethods;
			try
			{
				actPolyList = interpolationMethods.interpolateSplines(xVals, yVals);
				Assert::Fail();
			}
			catch (exception e)
			{
				Assert();
			}
		}
		TEST_METHOD(InterpolationMethodsFindFuncValueValid)
		{
			std::vector <PolyFunc> func;
			func.push_back(PolyFunc(1, 1, 0, 0, 0, 2));
			func.push_back(PolyFunc(0, 0, 1, 1, 2, 4));
			func.push_back(PolyFunc(-0.5, 0,0 , 0.5, 4, 6));
			Assert::IsTrue(InterpolationMethods::findFuncValue(func,1) == 2);
			Assert::IsTrue(InterpolationMethods::findFuncValue(func, 3) == 4);
			Assert::IsTrue(InterpolationMethods::findFuncValue(func, 5) == -62);

		}

		TEST_METHOD(InterpolationMethodsFindFuncValueInvalid)
		{
			std::vector <PolyFunc> func;
			func.push_back(PolyFunc(1, 1, 0, 0, 0, 2));
			func.push_back(PolyFunc(0, 0, 1, 1, 2, 4));
			func.push_back(PolyFunc(-0.5, 0, 0, 0.5, 4, 6));
			try
			{
				double ans = InterpolationMethods::findFuncValue(func, 6.5);
				Assert::Fail();
			}
			catch (exception e)
			{
				Assert();
			}
		}

		TEST_METHOD(InterpolationMethodsSolveQuadtraticFormulaValid)
		{
			PolyFunc poly(0, 1, -3, -10, -3, 6);
			std::vector<double>ans=
				InterpolationMethods::solveQuadraticFormula(poly);
			double x1 = 5;
			double x2 = -2;
			Assert::IsTrue(ans[0] == x1);
			Assert::IsTrue(ans[1] == x2);
			PolyFunc poly2(0, 4, -12, 9, 0, 2);
			x1 = x2 = 1.5;
			ans = InterpolationMethods::solveQuadraticFormula(poly2);
			Assert::IsTrue(ans[0] == x1);
			Assert::IsTrue(ans[1] == x2);
		}

		TEST_METHOD(InterpolationMethodsSolveQuadtraticFormulaInvalid)
		{
			PolyFunc poly(0, -1, 6, -10, 0, 6);
			std::vector<double>ans;
			try
			{
				ans = InterpolationMethods::solveQuadraticFormula(poly);
				Assert::Fail();
			}
			catch (exception e)
			{
				Assert();
			}
			
		}

		TEST_METHOD(InterpolationMethodsFindMax)
		{
			PolyFunc poly1(0, 4, -12, 9, 0, 2);
							//4x^2 -12x +9     (0,9)  (1.5, 0)  (2,1)
			PolyFunc poly2(0, 1, -3, -10, 2, 6);
							//x^2 -3x -10     (2,-12)   (5,0)   (6,8)
			std::vector<PolyFunc> func;
			func.push_back(poly1);
			func.push_back(poly2);
			double xMax=InterpolationMethods::findFuncMax(func);
			Assert::IsTrue(xMax, 0);
		}

		TEST_METHOD(InterpolationMethodsAreaUsingInterpolation)
		{
			std::vector<double> xVals{ 0.5,1.27,2.24,3,4.12,
				5.5,5.12,3,1.92,1.06,0.5 };
			std::vector<double> yVals{2,1.278,1.047,1,1.106,
				2,2.53,3,2.902,2.631,2};
			std::vector<double> prevPoint = InterpolationMethods::deCasteljau(xVals, yVals, 0);
			std::vector<double>point;
			double sumCycleWork = 0;
			double step = 0.01;
			double t, workBetweenStages;
			for (t = 0; t <= 1; t += step)
			{
				point = InterpolationMethods::deCasteljau(xVals, yVals, t);
				workBetweenStages = ((point[1] + prevPoint[1]) / 2)*(point[0] - prevPoint[0]);
				sumCycleWork += workBetweenStages;
				prevPoint = point;
			}
			sumCycleWork = abs(sumCycleWork);
			double correctArea = 7.85398163397;
			Assert::IsTrue((sumCycleWork < correctArea+0.1*correctArea) && 
				(sumCycleWork > correctArea -3-0.1*correctArea));
		}
	};
}