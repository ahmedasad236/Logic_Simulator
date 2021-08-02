#include "TruthTable.h"

TruthTable::TruthTable(ApplicationManager *pApp) : Action(pApp)
{
}

TruthTable::~TruthTable()
{
}

void TruthTable::ReadActionParameters()
{
}
void TruthTable::Execute()
{
	string truthString = pManager->CreateTruthTable();
	printf("%s", truthString);
	pManager->GetOutput()->makeTruthTableOnWindows(truthString);
	pManager->GetOutput()->PrintMsg("press ESCAPE to exit the truth table :)");
	pManager->GetInput()->waitForEscapePress();
	pManager->GetOutput()->updateAllDrawingArea();
}

void TruthTable::Undo()
{
}

void TruthTable::Redo()
{
}
