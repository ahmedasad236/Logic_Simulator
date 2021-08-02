#include "AddGate.h"

AddGate::AddGate(ApplicationManager* pApp):Action(pApp)
{
	OutInterFerance = pApp->GetOutput();
}

AddGate::~AddGate(void)
{
}

void AddGate::ReadActionParameters()
{
}

void AddGate::Execute()
{
	UI.addedGates = !UI.addedGates;
	OutInterFerance->CreateDesignToolBar();
	if (UI.addedGates) {
		UI.firstGates = 1;
		OutInterFerance->CreateGatesToolBar(UI.firstGates);
	}
	else
	{
		OutInterFerance->DeleteGatesToolBar();
	}
}

void AddGate::Undo()
{
}

void AddGate::Redo()
{
}
