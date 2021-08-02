#include "Paste.h"
#include "..\ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

void Paste::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Paste it somewhere valid");
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Paste it somewhere valid");

	pManager->PasteFromCopiedList(GInfo);
}

void Paste::Undo()
{
	pManager->Undo(PASTE);
}

void Paste::Redo()
{
	pManager->Redo(PASTE);
}

Paste::~Paste()
{
}
