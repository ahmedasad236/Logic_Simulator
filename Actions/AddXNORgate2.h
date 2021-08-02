#pragma once


#include "..\Actions\action.h"
#include "..\Components\XNOR2.h" //edit

class AddXNORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int z;
public:
	AddXNORgate2(ApplicationManager* pApp);
	AddXNORgate2(ApplicationManager* pApp, GraphicsInfo g1);

	virtual ~AddXNORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


