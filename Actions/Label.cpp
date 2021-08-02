#include "Label.h"
#include "..\AllActions.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void Label::ReadActionParameters()
{
}

void Label::Execute()
{
	if (pManager->getSelectedCount() > 1) {
		pOut->PrintMsg("Cant label multiple components at once");
		return;
	}
	string word;
	pOut->PrintMsg("Select a Component or a connection to name/edit:");
	Component* ComponentClickedOn = pManager->getTheComponentClickedOn();
	Component* Comp = dynamic_cast<Gate*>(ComponentClickedOn);
	if (Comp != NULL)
	{
		if (Comp->getLabel() == "")
		{
			pOut->PrintMsg("Enter Component Name:");
		}
		else
		{
			pOut->PrintMsg(Comp->getLabel());
		}
		word = pIn->GetSrting(pOut, Comp->getLabel());
		pManager->DeleteComponentLabel(Comp);
		pManager->DrawComponentLabel(Comp, word);
		return;
	}
	Comp = dynamic_cast<Connection*>(ComponentClickedOn);
	if (Comp != NULL)
	{
		if (Comp->getLabel() == "")
		{
			pOut->PrintMsg("Enter Connection Name:");
		}
		else
		{
			pOut->PrintMsg(Comp->getLabel());
		}
		word = pIn->GetSrting(pOut, Comp->getLabel());
		pManager->DeleteConnectionLabel(Comp);
		Comp->setLabel(word);
		pManager->DrawConnectionLabel(Comp, word);
		return;
	}
	pOut->PrintMsg("Invalid Selection!");
}

void Label::Undo()
{
}

void Label::Redo()
{
}

Label::~Label()
{
}
