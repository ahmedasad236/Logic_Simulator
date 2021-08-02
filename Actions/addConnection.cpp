#include "addConnection.h"
#include "..\ApplicationManager.h"
#include "..\Components\Gate.h"
#include "..\Components\led.h"
#include "..\Components\SWITCH.h"
int AddConnection::getNumOfInputPin()
{
	return numOfInputPin;
}
AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	sourcePin = NULL;
	distpin = NULL;
	isCrashed = 0;
	ifMainConstructor = 1;
}
bool AddConnection::ifTheConnectionCrashed()
{
	return isCrashed;
}
AddConnection::AddConnection(ApplicationManager* pApp, Component* source, Component* dest , int num):Action(pApp)
{
	ifMainConstructor = 0;
	isCrashed = 0;
	Gate* GSource = dynamic_cast<Gate*>(source);
	Gate* GDest = dynamic_cast<Gate*> (dest);
	if (GSource == NULL)
	{
		isCrashed = 1;
		pManager->GetOutput()->PrintMsg("Wrong Source gate :=) ");
	}
	if (GDest == NULL)
	{
		isCrashed = 1;
		pManager->GetOutput()->PrintMsg("Wrong source gate :=)");
	}
	if (!isCrashed) {
		GSource->getCoordinates(x1, y1);
		GDest->getCoordinates(x2, y2);
		sourcePin = GSource->getOutputPin();
		distpin = GDest->GetInputPinNum(num);
		numOfInputPin = num;
	}
}
//new
AddConnection::AddConnection(ApplicationManager* pApp, Component* C, bool ifSource, int num) :Action(pApp)
{
	ifMainConstructor = 0;
	Output* pOut = pManager->GetOutput();
	isCrashed = 0;
	Connection* pConn = dynamic_cast<Connection*>(C);
	if (pConn != NULL) {
		if (ifSource)
		{
			pOut->PrintMsg("please Select the new Source gate");
			Gate* NSrcGate = dynamic_cast<Gate*>(pManager->getTheComponentClickedOn());
			Gate* NDestGate = dynamic_cast<Gate*>(pConn->getDestPin()->getComponent());
			if (NSrcGate == NULL)
			{
				pOut->PrintMsg("you choosed a wrong new source gate , your action has been ignored");
				isCrashed = 1;
			}
			else if(NSrcGate == NDestGate)
			{
				pOut->PrintMsg("you can't connect a gate to itSelf , your action has been ignored");
				isCrashed = 1;
			}
			else if(dynamic_cast<led*>(NSrcGate) != NULL)
			{
				pOut->PrintMsg("you can't use led as a source gate , your action has been ignored");
				isCrashed = 1;
			}
			else
			{
				pManager->DeleteCompWithConnections(C);
				numOfInputPin = num;
				NSrcGate->getCoordinates(x1, y1);
				NDestGate->getCoordinates(x2, y2);
				sourcePin = NSrcGate->getOutputPin();
				distpin = NDestGate->GetInputPinNum(num);
			}
		}
		else
		{
			pOut->PrintMsg("please Choose your new dist gate");
			Gate* NSrcGate = dynamic_cast<Gate*>(pManager->getTheComponentConnectedTo(pConn));
			Gate* NDstGate = dynamic_cast<Gate*>(pManager->getTheComponentClickedOn());
			if (NDstGate == NULL)
			{
				pOut->PrintMsg("you choosed a wrong new Dest gate , your action has been ignored");
				isCrashed = 1;
			}
			else if (NSrcGate == NDstGate)
			{
				pOut->PrintMsg("you can't connect a gate to itSelf , your action has been ignored");
				isCrashed = 1;
			}
			else if (dynamic_cast<SWITCH*>(NDstGate) != NULL)
			{
				pOut->PrintMsg("you can't use led as a dest gate , your action has been ignored");
				isCrashed = 1;
			}
			else
			{
				pManager->DeleteCompWithConnections(pConn);
				if (NSrcGate != NULL)
				{
					NSrcGate->getCoordinates(x1, y1);
					sourcePin = NSrcGate->getOutputPin();
				}
				if (NDstGate != NULL)
				{
					NDstGate->getCoordinates(x2, y2);
					distpin = NDstGate->getTheFirstUnUsedInputPin(numOfInputPin);
				}
				if (distpin == NULL)
				{
					pOut->PrintMsg("you choosed a wrong distination gate , your action has been ignored");
					isCrashed = 1;
				}
			}
		}
	}
}


AddConnection::~AddConnection(void) {}

void AddConnection::ReadActionParameters()
{
	Gate* temp1 = NULL;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//new
	pOut->PrintMsg("Connection : please select the Source gate");
	temp1 = dynamic_cast<Gate*> (pManager->getTheComponentClickedOn());
	if (temp1 == NULL)
	{
		pOut->PrintMsg("Invalid area your action has been ignored");
		isCrashed = 1;
		return;
	}
	if (dynamic_cast<led*>(temp1) != NULL)
	{
		pOut->PrintMsg("you can't use led as a source pin , your action has been ignored");
		isCrashed = 1;
		return;
	}
	if (!temp1->canConnectToOutPin())
	{
		pOut->PrintMsg("you can't connect to this source pin , this wires are full :)");
		isCrashed = 1;
		return;
	}
	temp1->getCoordinates(x1, y1);
	sourcePin = temp1->getOutputPin();
	Gate* temp2;

	//new
	pOut->PrintMsg("Connection : please select the distination gate");
	temp2 = dynamic_cast<Gate*> (pManager->getTheComponentClickedOn());
	if (temp2 == NULL)
	{
		pOut->PrintMsg("Invalid area your action has been ignored");
		isCrashed = 1;
		return;
	}
	if (dynamic_cast<SWITCH*>(temp2) != NULL)
	{
		pOut->PrintMsg("you can't use switch as a distination pin , your action has been ignored");
		isCrashed = 1;
		return;
	}
	if (temp2 == temp1)
	{
		pOut->PrintMsg("You can't connect to to the same gate , your action has been ignored");
		isCrashed = 1;
		return;
	}
	temp2->getCoordinates(x2, y2);
	distpin = temp2->getTheFirstUnUsedInputPin(numOfInputPin);
	if (distpin == NULL)
	{
		pOut->PrintMsg("you choosed a wrong distination gate , your action has been ignored");
		isCrashed = 1;
		return;
	}
}

void AddConnection::Execute()
{
	if (ifMainConstructor) {
		ReadActionParameters();
	}
	if (isCrashed) return;
	if (distpin == NULL || sourcePin == NULL) return;
	int len = (numOfInputPin == 3) ? 0 : (numOfInputPin == 1) ? HEIGHT_TO_CONNECT : -1 * HEIGHT_TO_CONNECT;
	int Wdth = WIDTH_TO_CONNECT;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = x1 + Wdth;
	GInfo.x2 = x2 - Wdth;
	GInfo.y1 = y1;
	GInfo.y2 = y2 + len;
	Output* pOut = pManager->GetOutput();
	//new
	if (validArea(GInfo)) 
	{
		Connection* pA = new Connection(GInfo, sourcePin, distpin, numOfInputPin);
		pManager->AddComponent(pA);
	}
	else
	{
		pOut->PrintMsg("Invalid area for drawing :( ");
	}
	pOut->ClearStatusBar();
}

void AddConnection::Undo()
{
	pManager->Undo(ADD_CONNECTION);
}

void AddConnection::Redo()
{
	pManager->Redo(ADD_CONNECTION);
}

