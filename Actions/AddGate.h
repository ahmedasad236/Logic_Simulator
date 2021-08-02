#pragma once
#include "..\Actions\action.h"
#include "..\ApplicationManager.h"

class AddGate : public Action
{
private:
	Output* OutInterFerance;
	//Two corners of the rectangluar area
public:
	AddGate(ApplicationManager* pApp);
	virtual ~AddGate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};