#include "select.h"

Select::Select(ApplicationManager* pApp, Component** list, bool * selected , int c) :Action(pApp)
{
	compList = list;
	selectedComponents = selected;
	compCount = c;
}


void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* In = pManager->GetInput();

	In->GetPointClicked(x1, y1);

}

void Select::Execute()
{
	ReadActionParameters();
	for (int i = 0; i < compCount; i++)
		selectedComponents[i] = 0;
	for (int i = 0; i < compCount; i++) {
		if (compList[i]->ClickedHere(x1 , y1))
		{
			selectedComponents[i] = 1;
			return;
		}
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

