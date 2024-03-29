#pragma once

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <array>
#include "glut.h"

#if _DEBUG
#define DEBUGLOG "[Debug] "
#else
#define DEBUGLOG ""
#endif // _DEBUG

using namespace std;

/// <summary>
/// A vector of arrays containing x and y coordinates of a vertice.
/// </summary>
typedef vector<array<float, 2>> PolygonVertices;

struct TranslationStruct
{
	float x = 0.0f, y = 0.0f, z = 0.0f, rotation = 0.0f, scale = 1.0f;
};

/// <summary>
/// Structure for storing RGBA data that is represented as values ranging from
/// 0 to 1.
/// </summary>
struct RgbaColour
{
	/// <summary>
	/// Value for red ranging from 0 to 1, by default 1.
	/// </summary>
	float red = 1.0f;
	/// <summary>
	/// Value for green ranging from 0 to 1, by default 1.
	/// </summary>
	float green = 1.0f;
	/// <summary>
	/// Value for blue ranging from 0 to 1, by default 1.
	/// </summary>
	float blue = 1.0f;
	/// <summary>
	/// Value for alpha ranging from 0, being transparent, and 1, being opaque,
	/// by default 1.
	/// </summary>
	float alpha = 1.0f;
	/// <summary>
	/// Assigns values for the 3 colour values for an RgbaColour struct.
	/// </summary>
	/// <param name="inputRed">The value for red ranging from 0 to 1.</param>
	/// <param name="inputGreen">The value for green ranging from 0 to 1.</param>
	/// <param name="inputBlue">The value for blue ranging from 0 to 1.</param>
	void AssignColour(float inputRed, float inputGreen, float inputBlue);
	/// <summary>
	/// Assigns values for the 3 colour values and the alpha value for an RgbaColour struct.
	/// </summary>
	/// <param name="inputRed">The value for red ranging from 0 to 1.</param>
	/// <param name="inputGreen">The value for green ranging from 0 to 1.</param>
	/// <param name="inputBlue">The value for blue ranging from 0 to 1.</param>
	/// <param name="inputAlpha">The value for blue ranging from 0 to 1, with 0 being completely transparent and 1 being opaque.</param>
	void AssignColour(float inputRed, float inputGreen, float inputBlue, float inputAlpha);
};

struct PolygonStruct
{
	TranslationStruct translation;
	PolygonVertices vertices;
	RgbaColour colour;
};

class AssignmentOneGlutClass
{
	
};

/// <summary>
/// Calculates the vertices of a regular polygon (e.g. square if 4).
/// </summary>
/// <param name="numberOfVertices">The desired number of vertices(corners/sides).</param>
/// <param name="distanceFromCentre">The desired distance from the centre of the shape(affects size).</param>
/// <returns>A list of vertices for a regular shape.</returns>
PolygonVertices CalculateRegularPolygonVertices(int numberOfVertices, float distanceFromCentre);

/// <summary>
/// Saves inputted vertices to default file 'Default.vertices'.
/// </summary>
/// <param name="inputVertices">The vector of vertices that is to be saved to a file.</param>
void SavePolygonVerticesToFile(PolygonVertices inputVertices);

/// <summary>
/// Saves inputted vertices to a file named by the user with '.vertices' type.
/// </summary>
/// <param name="inputVertices">The input vertices.</param>
/// <param name="filePath">The filepath for the new file being saved which includes the name.</param>
void SavePolygonVerticesToFile(PolygonVertices inputVertices, string filePath);

/// <summary>
/// Loads the default 'Default.vertices' file.
/// </summary>
/// <returns>The vertices to be used for the shape shown.</returns>
PolygonVertices LoadPolygonVerticesFromFile();

/// <summary>
/// Loads the default 'Default.vertices' file.
/// </summary>
/// <param name="filePath">The filepath for the file being loaded which includes the name.</param>
/// <returns>The vertices to be used for the shape shown.</returns>
PolygonVertices LoadPolygonVerticesFromFile(string filePath);