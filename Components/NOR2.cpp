#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo& r_Gfxinfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_Gfxinfo.x1;
	m_GfxInfo.y1 = r_Gfxinfo.y1;
	m_GfxInfo.x2 = r_Gfxinfo.x2;
	m_GfxInfo.y2 = r_Gfxinfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}

void NOR2::Operate()
{
	bool out = 0;
	for (int i = 0; i < m_Inputs; i++) {

		out = out | (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);

	}
	m_OutputPin.setStatus(out ? STATUS::LOW : STATUS::HIGH);


}

void NOR2::Draw(Output* pOut, bool isselected)
{
	pOut->DrawNOR2(m_GfxInfo, isselected);
}

int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR2::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "NOR2" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void NOR2::load()
{
}
