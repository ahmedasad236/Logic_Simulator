#pragma once

#include "..\Components\Gate.h"
#include "../Defs.H"
#include "../GUI/Input.h"

class XNOR2 : public Gate
{
public:
	XNOR2(const GraphicsInfo& r_Gfxinfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XNOR2 gate
	virtual void Draw(Output* pOut, bool isselected);	//Draws 2-input gate
	virtual int GetOutPinStatus();	//returns status of output pin
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n 

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void save(ofstream &f);
	virtual void load();


};


