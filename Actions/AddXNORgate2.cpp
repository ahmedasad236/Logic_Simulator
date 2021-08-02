#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"
AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) :Action(pApp)
{
	z = 1;
}
AddXNORgate2::AddXNORgate2(ApplicationManager * pApp, GraphicsInfo  g1) : Action(pApp)
{
	z = 0;
	Cx = g1.x1;
	Cy = g1.y1;
}
AddXNORgate2::~AddXNORgate2(void)
{
}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate2::Execute()
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
		XNOR2* pA = new XNOR2(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid area for drawing :( ");
	}
}

void AddXNORgate2::Undo()
{
	pManager->Undo(ADD_XNOR_GATE_2);
}

void AddXNORgate2::Redo()
{
	pManager->Redo(ADD_XNOR_GATE_2);
}

