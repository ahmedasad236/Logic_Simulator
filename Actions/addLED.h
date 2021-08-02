#ifndef __ADD_LED__
#define __ADD_LED__

#include "action.h"
#include "..\Components\led.h"

class AddLED : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int z;
public:
	AddLED(ApplicationManager* pApp);
	AddLED(ApplicationManager* pApp,GraphicsInfo g1);

	virtual ~AddLED(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif