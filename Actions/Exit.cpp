#include "Exit.h"
#include "..\ApplicationManager.h"
Exit::Exit(ApplicationManager * pApp): Action(pApp)
{

}

void Exit::ReadActionParameters()
{
}

void Exit::Execute()
{
	string s;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Do you want to save ?");
	Input* pIn = pManager->GetInput();
	s=pIn->GetSrting(pOut);
	if (s == "y") {
		file.open("Circuit.txt");
		file.clear();
		pManager->save(file);
		file << "-1\n";
		pOut->PrintMsg("SAVED");
		exit(0);

	}
	else {
		exit(0);
	}
}

void Exit::Undo()
{
}

void Exit::Redo()
{
}

Exit::~Exit()
{
	file.close();

}
