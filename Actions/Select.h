#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
class Select : public Action
{

private:
	int x1, y1;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~Select();
};


