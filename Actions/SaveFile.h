#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include <fstream>
class SaveFile : public Action
{
private:
	ofstream file;
public:
	SaveFile(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~SaveFile();

};

