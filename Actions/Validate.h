#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class Validate : public Action
{
public:
	Validate(ApplicationManager* pApp);
	virtual ~Validate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

