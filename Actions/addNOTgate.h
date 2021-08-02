#pragma once
#include "..\Actions\Action.h"
#include "..\Components\NOT.h" //edit it

class AddNOTgate :public Action
{
private:
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int z;
public:
	AddNOTgate(ApplicationManager* pApp);
	AddNOTgate(ApplicationManager* pApp, GraphicsInfo g1);

	virtual ~AddNOTgate(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};
