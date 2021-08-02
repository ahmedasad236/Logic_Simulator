#include "Cut.h"

Cut::Cut(ApplicationManager* pApp) : Action(pApp)
{

}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	//Print Action Message
	pOut->PrintMsg("Select a component to Cut");

}

void Cut::Execute()
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
	pManager->cut = true;
	pManager->AddToCopiedList(Comp);
	pOut->ClearStatusBar();

}

void Cut::Undo()
{
}

void Cut::Redo()
{
}

Cut::~Cut()
{
}
