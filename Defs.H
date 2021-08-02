#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,
	EDIT_CONNECTION,
	ADD_GATE,//Edit Label of a Component, a Connection
	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	MULTISELECT,
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	COPY,
	PASTE,
	MULTIPLE_SELECT,
	CUT,
	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	EXIT_GATE_BAR,
	EXIT,		//Exit the application
	ITM_SCROLL_1,
	ITM_SCROLL_2,
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,
	SIMULATE,
	ADD_TOOLS,	//A click on an empty place in the design tool bar
	VALIDATE,
	PROBE,
	INVALID_AREA
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};
enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum Connected
{
	CON,
	DISCON
};
// ADD GATES
enum FIRST_GATES_TOOL_BAR //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_BUFF,
	ITM_INV,
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,//OR gate item in menu
	ITM_NAND2,
	ITM_NOR2,
	ITM_XOR2,
	ITM_SCROLL,
	ITM_CNT_TOOL_BAR1,
};
enum SECOND_GATES_TOOL_BAR
{
	ITM_XNOR2,
	ITM_AND3,
	ITM_NOR3,
	ITM_XOR3,
	ITM_SWITCH,
	ITM_LED,
	ITM_SCROLL2,//Exit item
	//TODO: Add more items names here

	ITM_CNT_TOOL_BAR2		//no. of design menu items ==> This should be the last line in this enum

};

// First window that shows up

enum InitialDesign //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADD_GATE,		//AND gate item in menu
	ITM_SIMULATE,
	ITM_TOOLSI,
	ITM_VALIDATE,
	ITM_LOADI,
	ITM_SAVEI,
	ITM_EXITI,
	//Exit item
	//TODO: Add more items names here

	ITM_DSN_COUNT		//no. of design menu items ==> This should be the last line in this enum

};
// Left sidebar
enum Side1
{
	ITM_LOAD_SIDE,
	ITM_SAVE_SIDE,
	ITM_EXIT_SIDE,

	ITM_SIDE_CNT
};
// Right sidebar
enum Side2
{
	ITM_SIMULATE_SIDE,
	ITM_ADD_GATE_SIDE,
	ITM_TOOLS_SIDE,
};
// Simulation
enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu

	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,
	ITM_TOOLS,
	ITM_VALIDATE_SIM,
	ITM_LOAD_SIM,
	ITM_SAVE_SIM,
	ITM_EXIT_SIM,
	//TODO:Add more items names here

	ITM_SIM_CNT	//no. of simulation menu items ==> This should be the last line in this enum

};
// Toolbar when you click on tools
enum ToolsLeft
{
	ITM_LABEL,
	ITM_UNDO,
	ITM_REDO,
	ITM_DELETE,
	ITM_WIRE,
	ITM_L_TOOL_CNT,
};
enum ToolsRight
{
	ITM_EDIT_CONNECTION,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_R_TOOL_CNT
};
//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};
enum LEN_WIDTH
{
	HEIGHT_TO_CONNECT = 17,
	WIDTH_TO_CONNECT = 25
};
//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};
struct controlActions
{
	ActionType AType;
	//Component* Comp;
	bool deleted;
};
//bool canConnected[UI.width][UI.height];
#ifndef NULL
#define NULL 0
#endif

#endif
/*
*	    
*/