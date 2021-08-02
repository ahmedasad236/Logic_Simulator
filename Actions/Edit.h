#pragma once
#include "Action.h"
#include "..\GUI\Input.h"
#include "..\GUI\Input.h"
#include "..\ApplicationManager.h"
#include "..\Actions\Label.h"
using namespace std;
class Edit : public Action
{
private:
	Output* pOut;
	Input* pIn;
	Action* pAct;
	bool invalid;
	Connection* Conn;
public:
	Edit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	~Edit();
};

