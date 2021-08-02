#pragma once

#include "..\Components\Gate.h"
class NOT : public Gate
{
public:
	NOT(const GraphicsInfo& r_Gfxinfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut, bool isselected);
	virtual int GetOutPinStatus();	//returns status of output pin
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n 
	InputPin* getTheFirstUnUsedInputPin(int &NUM);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	InputPin* GetInputPinNum(int x);
	virtual void save(ofstream &f);
	void freeInputPin(int num);
	virtual void load();
};


