#include "Connection.h"
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin, InputPin *pDstPin) :Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcPin->ConnectTo(this);
	id_comp = UI.ID;
	UI.ID++;
}

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin , int num):Component(r_GfxInfo)	
{
	numOfInputPin = num;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcPin->ConnectTo(this);
	id_comp = UI.ID;
	UI.ID++;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

int Connection::getNumOfInputPin()
{
	return numOfInputPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut , bool selected)
{
	if (selected)
		pOut->DrawConnection(m_GfxInfo, selected, GREEN);
	else
		pOut->DrawConnection(m_GfxInfo, selected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

bool Connection::ClickedHere(int x, int y)
{
	if (m_GfxInfo.x1 <= m_GfxInfo.x2) {
		int med = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2;
		if ((x >= m_GfxInfo.x1 && x <= med && abs(y - m_GfxInfo.y1) <= 5) || (x >= med && x <= m_GfxInfo.x2 && abs(y - m_GfxInfo.y2) <= 5 || abs(x - med) <= 5 && (y >= min(m_GfxInfo.y1 , m_GfxInfo.y2)) && y <= max(m_GfxInfo.y1, m_GfxInfo.y2)))
		{
			//printf("%d ,%d ,%d", m_GfxInfo.x1, med, m_GfxInfo.x2);
			return true;
		}
		else
		{
			//printf("error%d ,%d ,%d", m_GfxInfo.x1, med, m_GfxInfo.x2);
			return false;
		}
	}
	/*
		________
				|_________
						.	
						|
	   __.				|
	  |_________________|

	*/
	else
	{
		int addedArea = 10;
		int avgPixels = (m_GfxInfo.x1 - m_GfxInfo.x2) / 2;
		if (m_GfxInfo.y1 < m_GfxInfo.y2) {
			return (abs(x - m_GfxInfo.x1) <= 5 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2 + addedArea) || (abs(y - m_GfxInfo.y2 - addedArea) <= 2 && x <= m_GfxInfo.x1 && x >= m_GfxInfo.x2 - addedArea) || (abs(x - m_GfxInfo.x2 + addedArea) <= 2 && y >= m_GfxInfo.y2 && y <= m_GfxInfo.y2 + addedArea) || (abs(y - m_GfxInfo.y2) <= 2 && x >= m_GfxInfo.x2 - addedArea && x <= m_GfxInfo.x2);
		}
		else
		{
			return (abs(x - m_GfxInfo.x1) <= 5 && y >= m_GfxInfo.y2 && y <= m_GfxInfo.y1 + addedArea) || (abs(y - m_GfxInfo.y2 - addedArea) <= 2 && x <= m_GfxInfo.x1 && x >= m_GfxInfo.x2 - addedArea) || (abs(x - m_GfxInfo.x2 + addedArea) <= 2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y1 + addedArea) || (abs(y - m_GfxInfo.y1) <= 2 && x >= m_GfxInfo.x2 - addedArea && x <= m_GfxInfo.x2);
		}
	}
}
void Connection::save(ofstream& f, Component* C)
{
	f << C->GetID() << "   " << getDestPin()->getComponent()->GetID() << "   " << this->numOfInputPin << endl;
}

void Connection::load()
{
}
