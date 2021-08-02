#include "AddANDgate3.h"
#include "..\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
	z = 1;

}
AddANDgate3::AddANDgate3(ApplicationManager * pApp, GraphicsInfo  g1) : Action(pApp)
{
	z = 0;
	Cx = g1.x1;
	Cy = g1.y1;
}

AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddANDgate3::Execute()
{
	//Get Center point of the Gate
	if (z != 0) {
		ReadActionParameters();
	}
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND3 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Output* pOut = pManager->GetOutput();
	if (validArea(GInfo)) {
		AND3* pA = new AND3(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid area for drawing :( ");
	}
}

void AddANDgate3::Undo()
{
	pManager->Undo(ADD_AND_GATE_3);
}

void AddANDgate3::Redo()
{
	pManager->Redo(ADD_AND_GATE_3);
}

