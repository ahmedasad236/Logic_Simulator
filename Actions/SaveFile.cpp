#include "SaveFile.h"

SaveFile::SaveFile(ApplicationManager * pApp):Action(pApp)
{
}

void SaveFile::ReadActionParameters()
{
}

void SaveFile::Execute()
{
	file.open("Circuit.txt");
	file.clear();
	pManager->save(file);
	file << "-1\n";
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("SAVED");

}

void SaveFile::Undo()
{
}

void SaveFile::Redo()
{
}

SaveFile::~SaveFile()
{
	file.close();

}
