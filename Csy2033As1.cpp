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

using namespace std;

void initialise();
void display();
void reshape(int w, int h);
void idle();

RgbaColour backgroundColour;
PolygonVertices polygonVertices;
PolygonStruct mainPolygon;
GLuint listAddress = 1;

int main(int argc, char* argv[])
{
	// Local Variables

	// Main main()
    std::cout << "CSY2033 Assignment 1 program starting.\n";

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

	initialise();

	glutMainLoop();

	std::cout << "Closing program.";

	return 0;
}

void initialise()
{
	glEnable(GL_DEPTH);
	SavePolygonVerticesToFile(CalculateRegularPolygonVertices(5, 1), "Pentagon");
	polygonVertices = LoadPolygonVerticesFromFile("Pentagon");

	glNewList(listAddress, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < polygonVertices.size(); i++)
	{
		glVertex3f(polygonVertices[i][0], polygonVertices[i][1], 0.0);
		cout << "x: " << polygonVertices[i][0] << ", y: " << polygonVertices[i][1] << endl;
	}
	glEnd();
	glEndList();
}

void display() 
{
	glClearColor(backgroundColour.red, backgroundColour.green, backgroundColour.blue, backgroundColour.alpha);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(mainPolygon.translation.x, mainPolygon.translation.y, mainPolygon.translation.z);
	glRotatef(mainPolygon.translation.rotation, 0.0, 0.0, 1.0);
	glScalef(mainPolygon.translation.scale, mainPolygon.translation.scale, mainPolygon.translation.scale);
	glCallList(listAddress);
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

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
	gluLookAt(0.0, 0.0, 5.0,     // eye's position
		0.0, 0.0, 1.0,     // center of interest
		0.0f, 1.0f, 0.0f); // up direction
}

void idle()
{
	glutPostRedisplay();
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
