
#include "BUFFER.h"

buffer::buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}
void buffer::freeInputPin(int num)
{
	ChoosedInput[0] = 0;
}
void buffer::Operate()
{
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
}


void buffer::Draw(Output* pOut, bool selected)
{
	pOut->DrawBUFF(m_GfxInfo, selected);
}

int buffer::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
InputPin* buffer::GetInputPinNum(int x)
{
	if (!ChoosedInput[0])
	{
		ChoosedInput[0] = 1;
		return &m_InputPins[0];
	}
	return NULL;
}
int buffer::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();
}

InputPin* buffer::getTheFirstUnUsedInputPin(int& NUM)
{
	if (!ChoosedInput[0])
	{
		ChoosedInput[0] = 1;
		NUM = 3;
		return &m_InputPins[0];
	}
	NUM = -1;
	return NULL;
}


void buffer::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}


void buffer::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "BUFFER" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void buffer::load()
{
}
