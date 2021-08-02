#pragma once
#include "Action.h"
#include <fstream>
class Exit: public Action
{
private:
	ofstream file;


public:

	Exit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	~Exit();
};

