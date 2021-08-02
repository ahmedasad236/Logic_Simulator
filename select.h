#pragma once
#include "Actions\Action.h"
#include "Action\..\ApplicationManager.h"
class Select : public Action
{

private:
	Component** compList;
	int compCount;
	bool* selectedComponents;
	int x1, y1;
public:
	Select(ApplicationManager* pApp, Component** list, bool* selected , int C);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~Select();
};


