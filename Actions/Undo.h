#pragma once
#include "Action.h"
#include <stack>
#include "..\ApplicationManager.h"
using namespace std;
class undo : public Action
{
private:
	Action* pAct;
public:
	undo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)

	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~undo();
};

/*
* [][][][]
* [][][][][]
*/