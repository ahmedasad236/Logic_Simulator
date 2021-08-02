#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)

	static const int	width = 1000, height = 600,	//Window width and height
		wx = 200, wy = 0,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 100,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 100,		//Width of each item in toolbar menu
		miniToolItemWidth = 50,
		miniToolItemHeight = 50;
	bool addedGates;
	bool addedTools;
	bool firstGates;
	int ID = 1;
	int x_Coord, y_Coord;
	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color

	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	AND2_Width = 50,		//AND2 Gate Image default width
		AND2_Height = 50;		//AND2 Gate Image default height
}UI;	//create a single global object UI
#endif