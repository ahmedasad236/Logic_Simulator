#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	bool *ChoosedInput;
public:
	Gate(int r_Inputs, int r_FanOut);
	bool ClickedHere(int x, int y);
	bool canConnectToOutPin();
	virtual OutputPin *getOutputPin();
	virtual InputPin* GetInputPinNum(int x);
	virtual void freeInputPin(int x);
	virtual InputPin* getTheFirstUnUsedInputPin(int &NUM);
	virtual void freeInputPin();
	virtual void getCoordinates(int& x, int& y);
	virtual void setAllNewLevels();
	virtual bool ValidComponent();
	virtual bool ValidConnection();
	virtual bool ConnectedTo(Connection* Conn);
	virtual void decrementFanOut();
	virtual void setAllStatus();
};

#endif
