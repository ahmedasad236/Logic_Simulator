#include "OR2.h"

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	id_comp = UI.ID;
	UI.ID++;
}


void OR2::Operate()
{
	//caclulate the output status as the ORing of the two input pins
	int n1 = GetInputPinStatus(1);
	int n2 = GetInputPinStatus(2);
	int result = n1 + n2;
	m_OutputPin.setStatus(result == 0 ? LOW : HIGH);
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(Output* pOut , bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo , selected);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void OR2::save(ofstream & f)
{
	string s = (getLabel() == "" ? "$" : getLabel());

	f << "OR2" << "   " << id_comp << "   " << s << "   " << GetGraphicsInfo().x1 << "   " << GetGraphicsInfo().y1 << endl;

}

void OR2::load()
{
}
