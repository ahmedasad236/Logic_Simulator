#pragma once
#include"Gate.h"
class led : public Gate
{
public:
	led(const GraphicsInfo &r_GfxInfo , int r_FanOut);
	void Draw(Output* pOut , bool selected);
	void Operate();
	int GetInputPinStatus(int n);
	int getTheNumOfInputPin(InputPin* IP);
	void setInputPinStatus(int n , STATUS s);
	int GetOutPinStatus();
	bool ValidConnection();
	virtual void save(ofstream &f);
	virtual void load();
};

