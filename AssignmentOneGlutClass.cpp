#include "AssignmentOneGlutClass.h"

void RgbaColour::AssignColour(float inputRed, float inputGreen, float inputBlue)
{
	// Local variables

	// Main "AssignColour()"
	red = inputRed;
	green = inputGreen;
	blue = inputBlue;
	alpha = 1.0;
}

void RgbaColour::AssignColour(float inputRed, float inputGreen, float inputBlue, float inputAlpha)
{
	// Local variables

	// Main "AssignColour()"
	red = inputRed;
	green = inputGreen;
	blue = inputBlue;
	alpha = inputAlpha;
}

vector<array<float, 2>> CalculateRegularPolygonVertices(int numberOfVertices, float distanceFromCentre)
{
	// Local variables

	vector<array<float, 2>> outputVector;
	const float pi = 3.14f;
	float angle = 2 * pi / numberOfVertices;

	// Main "CalculateRegularPolygonVertices()"
	cout << "CalculateRegularPolygonVertices() method starting." << endl;
	outputVector.resize(numberOfVertices);
	cout << "Resizing outputVector from 0 to " << outputVector.size() << endl;
	outputVector[0] = { 0, distanceFromCentre };
	for (int i = numberOfVertices - 1; i > 0 ; i--)
	{
		outputVector[i] = {outputVector[0][0] * cos(angle * i) - outputVector[0][1] * sin(angle * i), outputVector[0][1] * cos(angle * i) + outputVector[0][0] * sin(angle * i) };
	}
	
	cout << "Here are all " << numberOfVertices << " calculated vertices clockwise:" << endl;
	for (int i = 0; i < numberOfVertices; i++)
	{
		cout << i << ": x " << outputVector[i][0] << ", y " << outputVector[i][1] << endl;
	}
	cout << "CalculatingRegularPolygonVertices() method finishing." << endl;
	return outputVector;
}

void SavePolygonVerticesToFile(vector<array<float, 2>> inputVertices)
{
	// Local variables

	// Main SavePolygonVerticesToFile()
}

void SavePolygonVerticesToFile(vector<array<float, 2>> inputVertices, string filePath)
{
	// Local variables

	// Main SavePolygonVerticesToFile()
}
