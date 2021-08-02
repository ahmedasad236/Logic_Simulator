#ifndef _ACTION_H
#define _ACTION_H

class ApplicationManager; //forward class declaration
#include "../Defs.H"
#include "../GUI/UI_Info.h"
//Base class for all possible actions (abstract class)
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
public:
	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters()=0;
	
	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo()=0;

	//To redo this action (code depends on action type)
	virtual void Redo()=0;
	bool validArea(GraphicsInfo GInfo) { return (GInfo.x1 > UI.miniToolItemWidth && GInfo.x2 < UI.width - UI.miniToolItemWidth && GInfo.y1 > UI.ToolBarHeight && GInfo.y2 < UI.height - UI.StatusBarHeight - UI.ToolBarHeight); }
};

#endif