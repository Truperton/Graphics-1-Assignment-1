#include "Menus.h"

int Menus::MainMenu()
{
    int outputState = 0;

    cout << "[_____________] Main Menu [_____________]" << endl
        << "    options:" << endl
        << "    1 ) Default Polygon" << endl
        << "    2 ) Custom Regular Polygon" << endl
        << "   -1 ) quit" << endl << endl
        << "Enter your choice: ";

    cin >> outputState;

    return outputState;
}

RegularPolygonStruct Menus::CustomRegularPolygonMenu()
{
    RegularPolygonStruct outputStruct;
    cout << "Name for the shape: ";
    cin >> outputStruct.filePath;
    cout << "Number of vertices: ";
    cin >> outputStruct.numberOfVertices;
    cout << "Radius from centre: ";
    cin >> outputStruct.distanceFromCentre;
    return outputStruct;
}
