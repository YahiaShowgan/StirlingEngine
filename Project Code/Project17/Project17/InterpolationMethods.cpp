#include "InterpolationMethods.h"
using namespace std;

//input: a system of equations- diagonally dominant matrix and vector.
//output: return answer vector.
vector<double> InterpolationMethods::thomasAlg(vector< vector<double> >mat, vector <double> dVec)
{
	int k, n = dVec.size();
	//matrix should be a square matrix.
	if ((mat.size() != n) || (mat[0].size() != n))
		throw exception("matrix size exception");
	//check if matrix is tridiagonal- valid.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i != j) && (i != j + 1) && (i != j - 1))
				if (mat[i][j] != 0)
					throw exception("matrix isn't tridiagonal");
		}
	}
	double m;
	vector <double> xVec(n);//returning vector.
	for (k = 1; k < n; k++)
	{
		m = mat[k][k - 1] / mat[k - 1][k - 1];
		mat[k][k] -= m*mat[k - 1][k];
		dVec[k] -= m*dVec[k - 1];
	}
	xVec[n - 1] = dVec[n - 1] / mat[n - 1][n - 1];
	for (k = n - 2; k >= 0; k--)
	{
		xVec[k] = (dVec[k] - mat[k][k + 1] * xVec[k + 1]) / mat[k][k];
	}
	return xVec; 
}

//input: a list of points by x and y values.
//output: return a list of polynomials-one between every two given points. 
vector<PolyFunc> InterpolationMethods::interpolateSplines(vector <double> xVals, vector <double> yVals)
{
	int n = xVals.size();
	vector<PolyFunc> polyVec(n - 1);
	if (n != yVals.size())
		throw exception("x and y count aren't the same");
	for (int i = 0; i < n - 1; i++)
	{
		if (xVals[i] >= xVals[i + 1])
			throw exception("illegal function");
	}
	vector<double> vectorA(n);
	vector<double> vectorB(n - 1);
	vector<double> vectorC(n);
	vector<double> vectorD(n - 1);
	vector<double> vectorH(n - 1);
	vector<double> vectorM(n);
	//mat*c=m      mat-matrix, c-vector, m-vector
	vector<vector<double>> mat(n, vector<double>(n));
	for (int i = 0; i < vectorA.size(); i++)
		vectorA[i] = yVals[i];
	for (int i = 0; i < vectorH.size(); i++)
		vectorH[i] = xVals[i + 1] - xVals[i];
	mat[0][0] = 1;
	mat[n - 1][n - 1] = 1;
	for (int i = 1; i < n - 1; i++)
	{
		mat[i][i - 1] = vectorH[i - 1];
		mat[i][i] = 2 * (vectorH[i - 1] + vectorH[i]);
		mat[i][i + 1] = vectorH[i];
	}
	vectorM[0] = 0;
	vectorM[n - 1] = 0;
	for (int i = 1; i < n - 1; i++)
	{
		vectorM[i] = (3 / vectorH[i])*(vectorA[i + 1] - vectorA[i]) -
			(3 / vectorH[i - 1])*(vectorA[i] - vectorA[i - 1]);
	}
	vectorC = thomasAlg(mat, vectorM);
	for (int i = 0; i < vectorD.size(); i++)
	{
		vectorD[i] = (vectorC[i + 1] - vectorC[i]) / (3 * vectorH[i]);
	}
	for (int i = 0; i < vectorB.size(); i++)
	{
		vectorB[i] = (vectorA[i + 1] - vectorA[i]) / vectorH[i] - (vectorH[i] * (2 * vectorC[i] + vectorC[i + 1])) / 3;
	}
	//ax^3+ bx^2+ cx+ d 
	double a, b, c, d;
	double startX, startY, endX, endY;
	for (int i = 0; i < n - 1; i++)
	{
		startX = xVals[i];
		startY = yVals[i];
		endX = xVals[i + 1];
		endY = yVals[i + 1];
		a = vectorD[i];
		b = vectorC[i] - 3 * vectorD[i] * xVals[i];
		c = vectorB[i] - 2 * vectorC[i] * xVals[i] +
			3 * vectorD[i] * xVals[i] * xVals[i];
		d = vectorA[i] - vectorB[i] * xVals[i] + vectorC[i] * xVals[i] * xVals[i] -
			vectorD[i] * xVals[i] * xVals[i] * xVals[i];
		PolyFunc poly = PolyFunc(a, b, c, d, startX, endX);
		polyVec[i] = poly;
	}
	return polyVec;
}


//input: list of points (x doesn't have to be in non-ascending order) and a t.
//output: functions value at that t, 0<t<1
vector <double> InterpolationMethods::deCasteljau(vector <double>xVals, vector<double>yVals, float t)
{
	size_t b_len = xVals.size();
	if (b_len != yVals.size())
		throw exception ("non-valid points");
	if ((t < 0) || (t > 1))
		throw exception("t is out of range");
	vector<double> qX(b_len);
	vector<double> qY(b_len);
	size_t i, k;
	for (i = 0; i<b_len; ++i)
	{
		qX[i] = xVals[i];
		qY[i] = yVals[i];
	}
	for (k = 1; k<b_len; ++k)
	{
		for (i = 0; i<(b_len - k); ++i)
		{
			qX[i] = (1.0 - t)*qX[i] + t*qX[i + 1];
			qY[i] = (1.0 - t)*qY[i] + t*qY[i + 1];
		}
	}
	vector<double>point;
	point.push_back(qX[0]);	point.push_back(qY[0]);
	return point;
}

double InterpolationMethods::findFuncValue(std::vector<PolyFunc> polyList, double x)
{
	double y;
	if ((x < polyList[0].getStartX()) || (x > polyList[polyList.size()-1].getEndX()))
		throw exception("x is not in the function");
	int i = 0;
	while (x > polyList[i].getEndX())
		i++;
	if (i > polyList.size() - 1)
		throw exception("x is out of range");
	//found the containing poly
	y = polyList[i].getThirdDeg()*powf(x, 3);
	y += polyList[i].getSecondDeg()*powf(x, 2);
	y += polyList[i].getFirstDeg()*x;
	y += polyList[i].getZeroDeg();
	return y;
}

std::vector<double> InterpolationMethods::solveQuadraticFormula(PolyFunc poly)
{
	double a, b, c,x1,x2;
	a = poly.getSecondDeg();
	b = poly.getFirstDeg();
	c = poly.getZeroDeg();
	if ((b * b - 4 * a * c) < 0)
		throw exception("no solutions");
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	vector<double> xVec;
	xVec.push_back(x1);
	xVec.push_back(x2);
	return xVec;
}

double InterpolationMethods::findFuncMax(std::vector<PolyFunc> func)
{
	double max = findFuncValue(func,func[0].getStartX());
	double maxX;
	for (int i = 0; i < func.size(); i++)
	{
		if (findFuncValue(func, func[i].getStartX()) > max)
		{
			max = findFuncValue(func, func[i].getStartX());
			maxX = func[i].getStartX();
		}

		if (findFuncValue(func, func[i].getEndX()) > max)
		{
			max = findFuncValue(func, func[i].getEndX());
			maxX = func[i].getEndX();
		}
		double thirdDeg=0,secondDeg= 3*func[i].getThirdDeg(), 
			firstDeg=2*func[i].getSecondDeg(), zeroDeg=func[i].getFirstDeg();
		PolyFunc der(thirdDeg, secondDeg, firstDeg, zeroDeg,
			func[i].getStartX(),func[i].getEndX());
		vector<double> xSols;
		try
		{
			xSols = solveQuadraticFormula(der);
			if ((xSols[0] >= func[i].getStartX()) && (xSols[0] <= func[i].getEndX()))
			{
				if (findFuncValue(func, xSols[0]) > max)
				{
					max = findFuncValue(func, xSols[0]);
					maxX = xSols[0];
				}
			}
			if ((xSols[1] >= func[i].getStartX()) && (xSols[1] <= func[i].getEndX()))
			{
				if (findFuncValue(func, xSols[1]) > max)
				{
					max = findFuncValue(func, xSols[1]);
					maxX = xSols[1];
				}
			}
		}
		catch(exception e){}
	}
	return maxX;
}


//input: list of third degree polynomials
//output: area under the function
double InterpolationMethods::findAreaUnderPolyList(std::vector<PolyFunc> func)
{
	double sum = 0;
	PolyFunc poly;
	for (int i = 0; i < func.size(); i++)
	{
		poly = func[i];
		double a, b, c, d;//f(x)= ax^4+bx^3+cx^2+d
		a = poly.getThirdDeg() / 4;
		b = poly.getSecondDeg() / 3;
		c = poly.getFirstDeg() / 2;
		d = poly.getZeroDeg(); //intergrated function f(x)
		double y2 = a* pow(poly.getEndX(), 4) + b*pow(poly.getEndX(), 3) +
			c*pow(poly.getEndX(), 2) + d*poly.getEndX();
		double y1 = a* pow(poly.getStartX(), 4) + b*pow(poly.getStartX(), 3) +
			c*pow(poly.getStartX(), 2) + d*poly.getStartX();
		sum += y2 - y1;
	}
	return sum;
}