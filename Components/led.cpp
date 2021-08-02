#include "led.h"

led::led(const GraphicsInfo& r_GfxInfo, int r_FanOut):Gate(1 , r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}

void led::Draw(Output* pOut , bool selected)
{
	pOut->DrawLED(m_GfxInfo , selected);
}

void led::Operate()
{
}


int led::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();
}

int led::getTheNumOfInputPin(InputPin* IP)
{
	return (IP == &m_InputPins[0]) ? 3 : -1;
}

void led::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

int led::GetOutPinStatus()
{
	return -1;
}

bool led::ValidConnection()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (!ChoosedInput[i])
			return false;
	}
	return true;
}

void led::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "LED" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void led::load()
{
}
