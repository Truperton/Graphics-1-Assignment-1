#pragma once

#include <iostream>

using namespace std;

struct RegularPolygonStruct
{
	string filePath = "Default";
	int numberOfVertices = 5;
	int distanceFromCentre = 1;
};

class Menus
{
public:
	static enum ProgramStates
	{
		Exit = -1,
		MainMenuDisplayed,
		DefaultPolygon,
		CustomRegularPolygon
	};

	int currentState = 0;

	int MainMenu();

	RegularPolygonStruct CustomRegularPolygonMenu();
};

