#ifndef __BUF__
#define __BUF__
#include"Gate.h"
class buffer : public Gate
{
public:
	buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	void freeInputPin(int num);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut, bool selected);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	InputPin* GetInputPinNum(int x);
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual InputPin* getTheFirstUnUsedInputPin(int& NUM);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void save(ofstream &f);
	virtual void load();
};
#endif
