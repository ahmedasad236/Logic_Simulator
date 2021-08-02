#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}


void NOR3::Operate()
{
	//caclulate the output status as the ORing of the two input pins
	int n1 = GetInputPinStatus(1);
	int n2 = GetInputPinStatus(2);
	int n3 = GetInputPinStatus(3);
	bool result = !(n1 + n2 + n3);

	m_OutputPin.setStatus(result == 0 ? LOW : HIGH);
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut , bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo ,selected);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR3::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "NOR3" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void NOR3::load()
{
}
