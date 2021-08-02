#include "Validate.h"

Validate::Validate(ApplicationManager* pApp) : Action(pApp)
{
}

Validate::~Validate(void)
{
}

void Validate::ReadActionParameters()
{
}

void Validate::Execute()
{
	if (!pManager->isValidCircuit())
	{
		pManager->GetOutput()->PrintMsg("Invalid circuit :(");
	}
	else
	{
		pManager->GetOutput()->PrintMsg("Valid Circuit :-) ");
	}
}
void Validate::Undo(){}
void Validate::Redo(){}
