#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class TruthTable : public Action
{
private:
public:
	TruthTable(ApplicationManager *pApp);
	~TruthTable();
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo();
};

