#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	newLevel = 1;
	id_comp = UI.ID;
	UI.ID++;
}

void SWITCH::Draw(Output* pOut , bool selected)
{
	pOut->DrawSWITCH(m_GfxInfo , selected);
}

void SWITCH::Operate()
{
	if (m_OutputPin.getStatus() == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}

int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{
	return;
}

bool SWITCH::ValidConnection()
{
	return m_OutputPin.valid();
}

void SWITCH::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "SWITCH" << "   " << GetID() << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void SWITCH::load()
{
}
