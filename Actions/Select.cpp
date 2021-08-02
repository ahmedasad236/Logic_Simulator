#include "select.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}


void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* In = pManager->GetInput();
	x1 = UI.x_Coord;
	y1 = UI.y_Coord;
	
}

void Select::Execute()
{
	ReadActionParameters();
	pManager->makeSelectedComponent(x1 , y1);
	if(UI.AppMode == SIMULATION)
	{
		pManager->ExcuteSelectedSwitch();
	}
}

void Select::Undo()
{
}

void Select::Redo()
{
}

Select::~Select()
{
}

