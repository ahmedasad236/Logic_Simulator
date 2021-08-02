#include "Delete.h"
#include "..\ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{

}

Delete::~Delete(void)
{

}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Select a gate to delete it");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Delete::Execute()
{
	pManager->DeleteCompWithConnections();
}

void Delete::Undo()
{
	if (!pManager->MultipleDelete)
	{
		pManager->AddToUndoList(DEL);
		Component* Comp = pManager->getTheLastDeletedComponent();
		pManager->DeleteFromDeletedList(Comp);
		pManager->RemoveFromActionList();
	}
	else
	{
		int del = pManager->getlastDeletedCount();
		for (int i = 0; i < del; i++)
		{
			pManager->AddToUndoList(DEL);
			Component* Comp = pManager->getTheLastDeletedComponent();
			pManager->DeleteFromDeletedList(Comp);
			pManager->RemoveFromActionList();
		}
	}
}

void Delete::Redo()
{
	if (!pManager->MultipleDelete)
	{
		pManager->AddToActionList(DEL);
		pManager->DeleteCompWithConnections(pManager->getTheLastComponent());
		pManager->RemoveFromUndoList();
	}
	else
	{
		int n = pManager->getlastDeletedCount();
		for (int i = 0; i < n; i++)
		{
			pManager->AddToActionList(DEL);
			pManager->DeleteCompWithConnections(pManager->getTheLastComponent());
			pManager->RemoveFromUndoList();
		}
		for (int i = 0; i < n - 1; i++)
			pManager->incrementLastDeletedCount();
	}
}
