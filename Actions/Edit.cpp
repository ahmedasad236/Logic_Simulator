#include "Edit.h"
#include "..\AllActions.h"
Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	invalid = false;
	pAct = NULL;
}

void Edit::ReadActionParameters()
{
	pOut->PrintMsg("Select a connection to edit");
	Component* SelectedComponent = pManager->getTheComponentClickedOn();
	Conn = dynamic_cast<Connection*>(SelectedComponent);
	if (Conn == NULL)
	{
		pOut->PrintMsg("Invalid Selection");
		invalid = true;
		return;
	}
	pOut->PrintMsg("Do you want to edit the connection's destination pin or source pin? (S for Src pin, D for dest pin and B for both)");
	string ans = pIn->GetSrting(pOut);
	if (tolower(ans[0]) == 's')
	{
		pAct = new AddConnection(pManager, SelectedComponent , true , Conn->getNumOfInputPin());
	}
	else if (tolower(ans[0]) == 'd')
	{	
		//error solved
		pAct = new AddConnection(pManager, SelectedComponent , false, Conn->getNumOfInputPin());
	}
	else if (tolower(ans[0]) == 'b')
	{
		pAct = new AddConnection(pManager);
	}
	else
	{
		pOut->PrintMsg("Wrong Answer! Please try again.");
		invalid = 1;
	}
}

void Edit::Execute()
{
	ReadActionParameters();
	if (!invalid)
	{
		pAct->Execute();
	}
}

void Edit::Undo()
{
}

void Edit::Redo()
{
}

Edit::~Edit()
{
	if(pAct != NULL)
		delete pAct;
}
