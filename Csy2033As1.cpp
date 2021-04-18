// Csy2033As1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
//#include <gl\GL.h>
//#include <gl\GLU.h>
#include "glut.h"
#include "AssignmentOneGlutClass.h"
#include "Menus.h"

#if _DEBUG
#define DEBUGLOG "[Debug] "
#else
#define DEBUGLOG ""
#endif // _DEBUG

using namespace std;

void initialise(int state);
void display();
void reshape(int w, int h);
void idle();
void mouse_click(int button, int state, int x, int y);
void mouse_motion(int x, int y);

Menus menu;

RgbaColour backgroundColour;
PolygonVertices polygonVertices;
PolygonStruct mainPolygon;
GLuint listAddress = 1;

string verticesPathName;

// Likely to be removed
// global var, rotation angle
float angle = 0.0;
float vertices[5][2]; // 5 vertices, and x, y coordinates
GLuint listname = 1;
float dx = 0.0;
float dy = 0.0;
float dz = 0.0;
float scale = 1.0;

// mouse click
int x_click, y_click;
int button;
// End of example variables

int main(int argc, char* argv[])
{
	// Local Variables

	// Main main()
	std::cout << "CSY2033 Assignment 1 program starting.\n";

	menu.currentState = menu.MainMenu();

	if (menu.currentState == -1)
	{
		return 74;
	}

	// initialize glut
	glutInit(&argc, argv);

	backgroundColour.AssignColour(0.0f, 0.0f, 0.0f);

	// initialize window position
	
	glutInitWindowPosition(10, 10);
	
	// window size
	glutInitWindowSize(1200, 600);

	// display mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	// create a window
	glutCreateWindow("CSY2033 Assignment 1");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMouseFunc(mouse_click);
	glutMotionFunc(mouse_motion);

	initialise(menu.currentState);

	glutMainLoop();

	std::cout << "Closing program.";

	return 0;
}

void initialise(int state)
{
	RegularPolygonStruct tempStruct;

#if _DEBUG
	cout << DEBUGLOG "[initialise(int)] Starting." << endl;
#endif // _DEBUG

	glEnable(GL_DEPTH);

	switch (state)
	{
	case menu.DefaultPolygon:
		SavePolygonVerticesToFile(CalculateRegularPolygonVertices(5, 1));
		mainPolygon.vertices = LoadPolygonVerticesFromFile();
		break;
	case menu.CustomRegularPolygon:
		tempStruct = menu.CustomRegularPolygonMenu();

		verticesPathName = tempStruct.filePath;
		SavePolygonVerticesToFile(CalculateRegularPolygonVertices(tempStruct.numberOfVertices, tempStruct.distanceFromCentre), verticesPathName);
		mainPolygon.vertices = LoadPolygonVerticesFromFile(verticesPathName);
		break;
	default:
		break;
	}

	glNewList(listAddress, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < mainPolygon.vertices.size(); i++)
	{
		glVertex3f(mainPolygon.vertices[i][0], mainPolygon.vertices[i][1], 0.0);
		cout << "x: " << mainPolygon.vertices[i][0] << ", y: " << mainPolygon.vertices[i][1] << endl;
	}
	glEnd();
	glEndList();

#if _DEBUG
	cout << DEBUGLOG "[initialise(int)] Finished." << endl;
#endif // _DEBUG
}

void display() 
{
#if _DEBUG
#define LOCALLOG DEBUGLOG "[display()] "
	cout << LOCALLOG "Starting." << endl;
#endif // _DEBUG

	glClearColor(backgroundColour.red, backgroundColour.green, backgroundColour.blue, backgroundColour.alpha);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(mainPolygon.translation.x, mainPolygon.translation.y, mainPolygon.translation.z);
	glRotatef(mainPolygon.translation.rotation, 0.0, 0.0, 1.0);
	glScalef(mainPolygon.translation.scale, mainPolygon.translation.scale, mainPolygon.translation.scale);
	glCallList(listAddress);
	glPopMatrix();

	glutSwapBuffers();

#if _DEBUG
	cout << LOCALLOG "Finished." << endl;
#endif // _DEBUG
}

/// <summary>
/// Adjusts the scaling dependant on the new size of the window.
/// </summary>
/// <param name="w">Width of the screen in pixels</param>
/// <param name="h">Height of the screen in pixels</param>
void reshape(int w, int h)
{
#if _DEBUG
	cout << DEBUGLOG "[reshape(int, int)] Starting." << endl;
#endif // _DEBUG

	/* Prevent a divide by zero, when window is too short
	*  (you cant make a window of zero width).*/
	if (h == 0)
	{
		h = 1;
	}

	float ratio = 1.0 * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 5.0f,  // eye's position
			  0.0f, 0.0f, 1.0f,  // center of interest
			  0.0f, 1.0f, 0.0f); // up direction

#if _DEBUG
	cout << DEBUGLOG "[reshape(int, int)] Finished." << endl;
#endif // _DEBUG
}

void idle()
{
#if _DEBUG
	cout << DEBUGLOG "[idle()] Starting." << endl;
#endif // _DEBUG

	glutPostRedisplay();

#if _DEBUG
	cout << DEBUGLOG "[idle()] Finished." << endl;
#endif // _DEBUG
}

void mouse_click(int button, int state, int x, int y)
{
#if _DEBUG
#define LOCALLOG DEBUGLOG "[mouse_click(int, int, int, int)] "
	cout << LOCALLOG "Starting." << endl;
#endif // _DEBUG

	if (state == GLUT_DOWN)
	{
		x_click = x;
		y_click = y;
		::button = button; // button = GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
	}
	else
	{
		::button = -1;
	}

#if _DEBUG
	cout << LOCALLOG "Finished." << endl;
#endif // _DEBUG
}

void mouse_motion(int x, int y)
{
#if _DEBUG
#define LOCALLOG DEBUGLOG "[mouse_motion(int, int)] "
	cout << LOCALLOG "Starting." << endl
		<< LOCALLOG "int x = " << x << endl
		<< LOCALLOG "int y = " << y << endl;
#endif // _DEBUG

	double mvmatrix[16];
	double projmatrix[16];
	int    viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);

	double cur_y = double(viewport[3] - y);
	double obj_cur_y, obj_cur_x, obj_cur_z;
	gluUnProject((double)x, cur_y, 0.5, mvmatrix, projmatrix, viewport, &obj_cur_x, &obj_cur_y, &obj_cur_z);

	double pre_y = double(viewport[3] - y_click);
	double obj_pre_y, obj_pre_x, obj_pre_z;
	gluUnProject((double)x_click, pre_y, 0.5, mvmatrix, projmatrix, viewport, &obj_pre_x, &obj_pre_y, &obj_pre_z);

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		mainPolygon.translation.x += (obj_cur_x - obj_pre_x) * 2.5;
		mainPolygon.translation.y -= (obj_pre_y - obj_cur_y) * 2.5;
		break;
	case GLUT_RIGHT_BUTTON:
		mainPolygon.translation.rotation -= (x_click - x);
		break;
	case GLUT_MIDDLE_BUTTON:
		mainPolygon.translation.scale -= (x_click - x) * 0.02;
		break;
	}
	x_click = x;
	y_click = y;

#if _DEBUG
	cout << LOCALLOG "Finished." << endl;
#endif // _DEBUG
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
