// Csy2033As1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glut.h"
#include "AssignmentOneGlutClass.h"

using namespace std;

void display();

RgbaColour backgroundColour;

int main(int argc, char* argv[])
{
    std::cout << "CSY2033 Assignment 1 program starting.\n";
	std::cout << CalculateRegularPolygonVertices(5, 1).front()[0];
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

	glutMainLoop();

	std::cout << "Closing program.";

	return 0;
}

void display() 
{
	glClearColor(backgroundColour.red, backgroundColour.green, backgroundColour.blue, backgroundColour.alpha);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
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
