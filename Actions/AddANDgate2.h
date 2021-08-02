#ifndef _ADD_AND_GATE_2_H
#define _ADD_AND_GATE_2_H

#include "action.h"
#include "..\Components\AND2.h"

class AddANDgate2 :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int z;
public:
	AddANDgate2(ApplicationManager *pApp);
	AddANDgate2(ApplicationManager *pApp, GraphicsInfo g1);

	virtual ~AddANDgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif