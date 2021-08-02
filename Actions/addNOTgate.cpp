#include "AddNOTgate.h"
#include "..\ApplicationManager.h"

AddNOTgate::AddNOTgate(ApplicationManager* pApp) :Action(pApp)
{
	z = 1;
}
AddNOTgate::AddNOTgate(ApplicationManager * pApp, GraphicsInfo  g1) : Action(pApp)
{
	z = 0;
	Cx = g1.x1;
	Cy = g1.y1;
}
AddNOTgate::~AddNOTgate(void)
{

}

void AddNOTgate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("NOT Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNOTgate::Execute()
{
	//Get Center point of the Gate
	if (z != 0) {
		ReadActionParameters();
	}
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Output* pOut = pManager->GetOutput();
	if (validArea(GInfo)) {
		NOT* pA = new NOT(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid area for drawing :( ");
	}
}

void AddNOTgate::Undo()
{
	pManager->Undo(ADD_INV);
}

void AddNOTgate::Redo()
{
	pManager->Redo(ADD_INV);
}


