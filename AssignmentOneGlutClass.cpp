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

PolygonVertices CalculateRegularPolygonVertices(int numberOfVertices, float distanceFromCentre)
{
	// Local variables

	PolygonVertices outputVector;
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

void SavePolygonVerticesToFile(PolygonVertices inputVertices)
{
	//Local variables

	ofstream outfile("Default.vertices");
	// Main SavePolygonVerticesToFile()
	cout << "Saving vertices to \"Default.vertices\"" << endl << "Writing to file:" << endl;
	for (array<float, 2> var : inputVertices)
	{
		outfile << var[0] << " " << var[1] << endl;
		cout << "x: " << var[0] << ", y:" << var[1] << endl;
	}
	cout << "Closing \"Default.vertices\"";
	outfile.close();
}

void SavePolygonVerticesToFile(PolygonVertices inputVertices, string filePath)
{
	//Local variables

	ofstream newFile(filePath + ".vertices");
	// Main SavePolygonVerticesToFile()
	cout << "Saving vertices to \"" << filePath << ".vertices\"" << endl << "Writing to file:" << endl;
	for (array<float, 2> var : inputVertices)
	{
		newFile << var[0] << " " << var[1] << endl;
		cout << "x: " << var[0] << ", y:" << var[1] << endl;
	}
	cout << "Closing \"" << filePath << ".vertices\"" << endl;
	newFile.close();
}

PolygonVertices LoadPolygonVerticesFromFile()
{
	// Local variables

	ifstream loadingFile("Default.vertices");
	PolygonVertices outputVertices;
	bool notEmpty = true;
	int i = 0;
	// Main LoadPolygonVerticesFromFile()
	while (notEmpty)
	{
		float tempX, tempY;
		loadingFile >> tempX;
		loadingFile >> tempY;
		if (tempX != -107374176. && tempY != -107374176.)
		{
			outputVertices.resize(outputVertices.size() + 1);
			outputVertices[i][0] = tempX;
			outputVertices[i][1] = tempY;
			cout << outputVertices[i][0] << " " << outputVertices[i][1] << endl;
			tempX = -107374176.;
			tempY = -107374176.;
		}
		else
		{
			notEmpty = false;
		}
		i++;
	}
	return outputVertices;
}

PolygonVertices LoadPolygonVerticesFromFile(string filePath)
{
	// Local variables

	ifstream loadingFile(filePath + ".vertices");
	PolygonVertices outputVertices;
	bool notEmpty = true;
	int i = 0;
	// Main LoadPolygonVerticesFromFile()
	while (notEmpty)
	{
		float tempX, tempY;
		loadingFile >> tempX;
		loadingFile >> tempY;
		if (tempX != -107374176. && tempY != -107374176.)
		{
			outputVertices.resize(outputVertices.size() + 1);
			outputVertices[i][0] = tempX;
			outputVertices[i][1] = tempY;
			cout << outputVertices[i][0] << " " << outputVertices[i][1] << endl;
			tempX = -107374176.;
			tempY = -107374176.;
		}
		else
		{
			notEmpty = false;
		}
		i++;
	}
	return outputVertices;
}
