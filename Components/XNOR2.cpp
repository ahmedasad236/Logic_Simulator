#include "XNOR2.h"
#include "..\Components\Component.h"
XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}

void XNOR2::Operate()
{
	bool out = 0;
	/*Xoring then reverse the out*/
	for (int i = 0; i < m_Inputs; i++) {
		out = out ^ (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);


	}
	/*if its one so its low (0) and if its zero so its High(1) */
	m_OutputPin.setStatus(out ? STATUS::LOW : STATUS::HIGH);

}

void XNOR2::Draw(Output* pOut, bool isselected)
{
	//calling output class and function draw that made in phase 1
	pOut->DrawXNOR2(m_GfxInfo, isselected);
}

int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XNOR2::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "XNOR2" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void XNOR2::load()
{
}








