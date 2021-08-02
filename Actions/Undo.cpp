#include "Undo.h"
#include "..\AllActions.h"
using namespace std;
undo::undo(ApplicationManager* pApp) :Action(pApp)
{
	pAct = NULL;
}

void undo::ReadActionParameters()
{
}

void undo::Execute()
{
	if (pManager->getActionListSize() >= 1)
	{
		ActionType LA = pManager->getTheLastActionDone();
		switch (LA)
		{
		case ADD_Buff:
			pAct = new AddBUFFER(pManager);
			break;
		case ADD_INV:
			pAct = new AddNOTgate(pManager);
			break;
		case ADD_AND_GATE_2:
			pAct = new AddANDgate2(pManager);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(pManager);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(pManager);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(pManager);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(pManager);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(pManager);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(pManager);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(pManager);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(pManager);
			break;
		case ADD_Switch:
			pAct = new AddSWITCH(pManager);
			break;
		case ADD_LED:
			pAct = new AddLED(pManager);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(pManager);
			break;
		case ADD_Label:
			pAct = new Label(pManager);
			break;
		case EDIT_CONNECTION:
			pAct = new Edit(pManager);
			break;
		case PASTE:
			pAct = new Paste(pManager);
			break;
		case DEL:
			pAct = new Delete(pManager);
			break;
		}
		if (pAct != NULL)
		{
			pAct->Undo();
			delete pAct;
			pAct = NULL;
		}
	}
}

void undo::Undo()
{
}

void undo::Redo()
{
}

undo::~undo()
{
}
