#include "Copy.h"

Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{

}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	//Print Action Message
	pOut->PrintMsg("Select a component to Copy");

}

void Copy::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Component* Comp = pManager->getTheComponentClickedOn();
	//new
	if (Comp == NULL)
	{
		pOut->PrintMsg("Invalid Selection");
		return;
	}
	pManager->cut = false;
	pManager->AddToCopiedList(Comp);
	pOut->ClearStatusBar();

}

void Copy::Undo()
{
}

void Copy::Redo()
{
}

Copy::~Copy()
{
}
