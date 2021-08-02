#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
	z = 1;
}
AddLED::AddLED(ApplicationManager * pApp, GraphicsInfo  g1) : Action(pApp)
{
	z = 0;
	Cx = g1.x1;
	Cy = g1.y1;
}
AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to add LED");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
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
		led* pA = new led(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid area for drawing :( ");
	}
}

void AddLED::Undo()
{
	pManager->Undo(ADD_LED);
}

void AddLED::Redo()
{
	pManager->Redo(ADD_LED);
}