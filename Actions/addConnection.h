#ifndef _ADD_CONNECTION
#define _ADD_CONNECTION

#include "Action.h"
#include "..\Components\Connection.h"

class AddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate	//Center point of the gate
	int x1, y1, x2, y2;
	int numOfInputPin;
	OutputPin* sourcePin;
	InputPin* distpin;	//Two corners of the rectangluar area
	bool isCrashed;
	//new
	bool ifMainConstructor;
	bool UndoRedo;
public:
	int getNumOfInputPin();
	AddConnection(ApplicationManager* pApp);
	bool ifTheConnectionCrashed();
	virtual ~AddConnection(void);
	AddConnection(ApplicationManager* pApp, Component* C1, Component* C2 , int num);
	//new
	AddConnection(ApplicationManager* pApp, Component* C, bool ifSource, int num);

	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

#endif
