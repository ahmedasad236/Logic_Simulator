#ifndef _COMPONENT_H
#define _COMPONENT_H
#include <fstream>

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	GraphicsInfo LabelGfx; // Label parameters
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool mSelected;
	bool SelectedComp[100];
	int id_comp;

public:
	bool isSelected;

	bool isDeleted;

	void setLabel(string l); // setter for component label

	string getLabel(); // getter for component label

	void setLabelGraphics(GraphicsInfo L); // setter for component label graphics

	GraphicsInfo GetLabelGraphics(); // getter for component label graphics

	bool newLevel;

	Component(const GraphicsInfo& r_GfxInfo, bool select = 0);

	virtual void Operate() = 0;	//Calculates the output according to the inputs

	virtual void Draw(Output* pOut, bool mSelected) = 0;	//for each component to Draw itself

	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1

	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.

	bool IsSelected() const;

	int GetID();

	void SetID(int s);

	virtual bool ClickedHere(int x, int y) = 0;

	GraphicsInfo Component::GetGraphicsInfo() const;

	void SetGraphicsInfo(GraphicsInfo g1);

	virtual void save(ofstream &f);

	virtual void load() = 0;

	//bool* get_selectedcomp();

	Component();

	virtual void setAllNewLevels();

	//Destructor must be virtual
	virtual bool ValidComponent();

	virtual void setAllStatus();

	virtual ~Component();
};

#endif
