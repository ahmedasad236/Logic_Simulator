#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include <fstream>
class Load:public Action
{
private:
	ifstream mRead;
public:
	Load(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Load();

};

