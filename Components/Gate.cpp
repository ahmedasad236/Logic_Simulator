#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	ChoosedInput = new bool[r_Inputs];
	newLevel = 0;
	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++) {
		m_InputPins[i].setComponent(this);
		ChoosedInput[i] = 0;
	}
}

bool Gate::ClickedHere(int x, int y)
{
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);
}

bool Gate::canConnectToOutPin()
{
	return m_OutputPin.canConnectToAdditionalWire();
}

OutputPin* Gate::getOutputPin()
{
	return &m_OutputPin;
}

InputPin* Gate::GetInputPinNum(int x)
{
	if (!ChoosedInput[x - 1])
	{
		ChoosedInput[x - 1] = 1;
		return &m_InputPins[x - 1];
	}
	return NULL;
}
void Gate::freeInputPin(int x)
{
	ChoosedInput[x - 1] = 0;
}
InputPin* Gate::getTheFirstUnUsedInputPin(int &NUM)
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (!ChoosedInput[i])
		{
			NUM = i + 1;
			ChoosedInput[i] = 1;
			return &m_InputPins[i];
		}
	}
	NUM = -1;
	return NULL;
}

void Gate::freeInputPin()
{
	ChoosedInput--;
}




void Gate::getCoordinates(int& x, int& y)
{
	x = m_GfxInfo.x1 + UI.AND2_Width / 2;
	y = m_GfxInfo.y1 + UI.AND2_Height / 2;
}

void Gate::setAllNewLevels()
{
	m_OutputPin.setNewLevel();
}

bool Gate::ValidComponent()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (!m_InputPins[i].alreadySet)
			return 0;
	}
	return 1;
}
bool Gate::ValidConnection()
{
	if (m_OutputPin.valid())
	{
		for (int i = 0; i < m_Inputs; i++)
		{
			if (!ChoosedInput[i])
				return false;
		}
		return true;
	}
	return false;
}
bool Gate::ConnectedTo(Connection* Conn)
{
	return m_OutputPin.ConnectedTo(Conn);
}
void Gate::decrementFanOut()
{
	m_OutputPin.decrementFanOut();
}
void Gate::setAllStatus()
{
	m_OutputPin.setConnectionsStatus();
}

