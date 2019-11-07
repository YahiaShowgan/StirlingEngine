#pragma once
#include <windows.h>
#include "DataController.h"
#include <algorithm>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL\freeglut.h>



using namespace System::Windows::Forms;

namespace ElectricalPowerByCurrentOpenGLForm
{
	public ref class COpenGL : public System::Windows::Forms::NativeWindow
	{

	public:
		int handle;
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				if (DataController::firstGlut)
				{
					int argc = 1;
					char *argv[1] = { (char*)"Something" };
					glutInit(&argc, argv);
					DataController::firstGlut = false;
				}
			}

			rtri = 0.0f;
			rquad = 0.0f;
		}


		System::Void Render(System::Void)
		{
			if (firstTime)
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
				glLoadIdentity();									// Reset the current modelview matrix
				glTranslatef(-1.0f, -0.5f, -3.0f);						// Move right 1.5 units and into the screen 7.0

				//draw axis x and y as arrows
				glBegin(GL_LINES);
				glLineWidth(2);
				glColor3f(0, 1, 0);
				glVertex2f(0, -0.5);
				glVertex2f(0, 1);
				glVertex2f(-0.03, 0.95);
				glVertex2f(0, 1);
				glVertex2f(0.03, 0.95);
				glVertex2f(0, 1);

				glColor3f(0, 1, 0);
				glVertex2f(-0.5, 0);
				glVertex2f(1.8, 0);
				glVertex2f(1.75, -0.03);
				glVertex2f(1.8, 0);
				glVertex2f(1.75, 0.03);
				glVertex2f(1.8, 0);
				glEnd();

				//y axis name
				char *yS = "Pe(Watts)";
				glColor3f(1, 0, 0);
				glRasterPos2f(-0.1, 1.05);
				const unsigned char* t = reinterpret_cast<const unsigned char *>(yS);
				glutBitmapString(GLUT_BITMAP_HELVETICA_12, t);

				//x axis name
				char *xS = "I(Amperes)";
				glColor3f(1, 0, 0);
				glRasterPos2f(1.85, -0.03);
				t = reinterpret_cast<const unsigned char *>(xS);
				glutBitmapString(GLUT_BITMAP_HELVETICA_12, t);

				std::vector<double> xVals;
				std::vector<double> yVals;
				DataController::averageElectricalPowerByCurrentList = DataController::averageElectricalPowerByCurrent(DataController::dataList);
				//push points for interpolating.
				for (int i = 0; i < DataController::averageElectricalPowerByCurrentList.size(); i++)
				{
					xVals.push_back(DataController::averageElectricalPowerByCurrentList[i].getCurrent());
					yVals.push_back(DataController::averageElectricalPowerByCurrentList[i].getWattage());
				}
				//get a list of splines from our points.
				std::vector <PolyFunc> polyList = InterpolationMethods::interpolateSplines(xVals, yVals);
				double xBegin = polyList[0].getStartX();
				double xEnd = polyList[polyList.size() - 1].getEndX();
				glBegin(GL_LINES);
				glLineWidth(1);
				glColor3f(1, 0, 0);
				double step = xEnd / 100;
				double x = xBegin;
				double xMax = InterpolationMethods::findFuncMax(polyList);
				double yMax = InterpolationMethods::findFuncValue(polyList, xMax);
				double normalizerX = xEnd;
				normalizerX /= 1.8;
				double normalizerY = yMax;
				glVertex2f(xBegin / normalizerX, InterpolationMethods::findFuncValue(polyList, xBegin) / normalizerY);
				for (x = x + step; x < xEnd; x += step)
				{
					glVertex2f(x / normalizerX, InterpolationMethods::findFuncValue(polyList, x) / normalizerY);
					glVertex2f(x / normalizerX, InterpolationMethods::findFuncValue(polyList, x) / normalizerY);
				}
				glVertex2f(xEnd / normalizerX, InterpolationMethods::findFuncValue(polyList, xEnd) / normalizerY);
				glEnd();
				glPointSize(5);
				glBegin(GL_POINTS);
				glVertex2f(xMax / normalizerX, yMax / normalizerY);
				glEnd();
				double stepSize = 0.00001;
				int count = 0;
				while (stepSize * 10 <= normalizerX*1.8)
				{
					if (count % 2 == 0)
						stepSize *= 5;
					else
						stepSize *= 2;
					count++;
				}

				//add number on axis x.
				for (int i = 1; i*stepSize <= normalizerX*1.8; i++)
				{
					char xStr[50];
					sprintf(xStr, "%.2f", i*stepSize);
					glColor3f(0, 1, 0);
					glRasterPos2f(-0.05 + i*stepSize / normalizerX, -0.1);
					const unsigned char* t1 = reinterpret_cast<const unsigned char *>(xStr);
					glutBitmapString(GLUT_BITMAP_HELVETICA_10, t1);
					glBegin(GL_POINTS);
					glColor3f(0, 1, 0);
					glVertex2f(i*stepSize / normalizerX, 0);
					glEnd();
				}
				stepSize = 0.00001;
				count = 0;
				while (stepSize * 15 <= normalizerY)
				{
					if (count % 2 == 0)
						stepSize *= 5;
					else
						stepSize *= 2;
					count++;
				}
				//add numbers on axis y.
				for (int i = 1; i*stepSize <= normalizerY; i++)
				{
					char yStr[50];
					sprintf(yStr, "%.2f", i*stepSize);
					glColor3f(0, 1, 0);
					glRasterPos2f(-0.15, -0.05 + i*stepSize / normalizerY);
					const unsigned char* t1 = reinterpret_cast<const unsigned char *>(yStr);
					glutBitmapString(GLUT_BITMAP_HELVETICA_10, t1);
					glBegin(GL_POINTS);
					glColor3f(0, 1, 0);
					glVertex2f(0, i*stepSize / normalizerY);
					glEnd();
				}

				//show max point
				double xPoint = xMax / normalizerX;
				double yPoint = yMax / normalizerY;
				double yStep = yPoint / 8;
				double xStep = xPoint / 8;
				for (double i = 0; i + yStep < yPoint; i += 2 * yStep)
				{
					glBegin(GL_LINES);
					glColor3f(0, 1, 0);
					glVertex2f(xPoint, i);
					glVertex2f(xPoint, i + yStep);
					glEnd();
				}
				for (double i = 0; i + xStep < xPoint; i += 2 * xStep)
				{
					glBegin(GL_LINES);
					glColor3f(0, 1, 0);
					glVertex2f(i, yPoint);
					glVertex2f(i + xStep, yPoint);
					glEnd();
				}

				char str[50];
				glColor3d(0, 0, 1);
				sprintf(str, "Pe=%.3f Watts, I=%.3f Amperes", xMax, yMax);
				glRasterPos2f(xMax / normalizerX - 0.02, yMax / normalizerY + 0.05);
				const unsigned char* t1 = reinterpret_cast<const unsigned char *>(str);
				glutBitmapString(GLUT_BITMAP_HELVETICA_10, t1);
			}
		}


		System::Void SwapOpenGLBuffers(System::Void)
		{
			if (firstTime)
			{
				SwapBuffers(m_hDC);
			}
			firstTime = false;
		}

	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		GLfloat	rtri;				// Angle for the triangle
		GLfloat	rquad;				// Angle for the quad
		boolean firstTime = true;


	protected:
		~COpenGL(System::Void)
		{
			firstTime = true;
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,										// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok
		}

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}

			glViewport(0, 0, width, height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

																// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}
	};
}