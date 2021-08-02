#pragma once
#include "Action.h"
#include "..\GUI\Input.h"
#include "..\GUI\Input.h"
#include "..\Components\Component.h"
#include "..\ApplicationManager.h"
using namespace std;
class Label : public Action
{
private:
	Output* pOut;
	Input* pIn;
public:
	Label(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	~Label();
};

