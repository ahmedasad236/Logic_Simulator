#include "simulate.h"
#include "../ApplicationManager.h"

simulate::simulate(ApplicationManager* pApp):Action(pApp)
{
}

void simulate::ReadActionParameters()
{
}

void simulate::Execute()
{
	if (pManager->isValidCircuit()) 
	{
		UI.AppMode = SIMULATION;
		pManager->OrganizeComponents();
		pManager->GetOutput()->CreateSimulationToolBar();
	}
	else
	{
		pManager->GetOutput()->PrintMsg("Invalid circuit :-( ");
	}
}

void simulate::Redo()
{
}

void simulate::Undo()
{
}

simulate::~simulate()
{
}
