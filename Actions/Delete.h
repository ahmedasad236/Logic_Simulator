#ifndef DELETE_H
#define DELETE_H

#include "Action.h"
#include "..\Components\Component.h"
#include "..\GUI\Input.h"

class Delete : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool* selectedComp;
public:
	
	Delete(ApplicationManager*);

	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif // !DELETE_H