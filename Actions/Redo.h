#pragma once
#include "Action.h"
#include "Undo.h"
#include "..\ApplicationManager.h"
#include <stack>
using namespace std;
class redo : public Action
{
private:
	Action* pAct;
public:
	redo(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)


	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	~redo();
};

