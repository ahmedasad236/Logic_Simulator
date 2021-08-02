#include "NOT.h"

NOT::NOT(const GraphicsInfo& r_Gfxinfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_Gfxinfo.x1;
	m_GfxInfo.y1 = r_Gfxinfo.y1;
	m_GfxInfo.x2 = r_Gfxinfo.x2;
	m_GfxInfo.y2 = r_Gfxinfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}

void NOT::Operate()
{
	m_OutputPin.setStatus(m_InputPins[0].getStatus() == STATUS::LOW ? STATUS::HIGH : STATUS::LOW);

}

void NOT::Draw(Output* pOut, bool isselected)
{
	//passing info to function in output class 
	pOut->DrawINV(m_GfxInfo, isselected);
}

int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

InputPin* NOT::getTheFirstUnUsedInputPin(int &NUM)
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
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
InputPin* NOT::GetInputPinNum(int x)
{
	if (!ChoosedInput[0])
	{
		ChoosedInput[0] = 1;
		return &m_InputPins[0];
	}
	return NULL;
}

void NOT::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "NOT" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}
void NOT::freeInputPin(int num)
{
	ChoosedInput[0] = 0;
}
void NOT::load()
{
}
