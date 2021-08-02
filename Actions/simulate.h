#ifndef _SIMULATE
#define _SIMULATE
#include "Action.h"
class simulate : public Action
{
public:
	simulate(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	void Redo();
	void Undo();
	~simulate();
};
#endif
