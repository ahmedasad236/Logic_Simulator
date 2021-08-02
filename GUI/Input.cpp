//#include "Input.h"
#include "Output.h"
#include<iostream>

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
	UI.addedGates = 0;
	UI.firstGates = 0;
}
void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
string Input::GetSrting(Output* pOut, string str)
{
	//(4) ==> we won't use cin here (expection)
	//we will find the function in CMUgraphics (may be windowinput.cpp)
	//all of us must read all files.h in CMU to know the function we have and call it if needed ==> very important

	///pOut->ClearStatusBar();
	char pressedButton = '\0';
	keytype kt;
	string word = str;
	while (true)
	{
		kt = pWind->WaitKeyPress(pressedButton);
		switch (kt)
		{
		case ASCII:
			printf("ASCII\n");
			if ((int)pressedButton == 13)
			{
				return word;
			}
			else if (pressedButton == '\b')
			{
				int size = word.size();
				word = size >= 1 ? word.substr(0, word.size() - 1) : word;
			}
			else
			{
				word += pressedButton;
			}
			break;
		case ESCAPE:
			printf("ESCAPE\n");
			return str;
			break;
		case NO_KEYPRESS:
			printf("iam here\n");
			break;
		case FUNCTION:
			printf("FUNCTION\n");
			break;
		case ARROW:
			printf("ARROW\n");
			break;
		default:
			break;
		}
		pOut->PrintMsg(word);
	}

	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	return word;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	pWind->removeLastAction();
	pWind->WaitMouseClick(UI.x_Coord, UI.y_Coord);	//Get the coordinates of the user click
   	cout << UI.x_Coord << " " << UI.y_Coord << endl;
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (UI.y_Coord >= 0 && UI.y_Coord < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			cout << UI.x_Coord << endl;
			int ClickedItemOrder = (UI.x_Coord - ((UI.width - ITM_DSN_COUNT * UI.ToolItemWidth) / 2)) / UI.ToolItemWidth;
			cout << ClickedItemOrder << endl;
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_ADD_GATE:
				return ADD_GATE;
			case ITM_SIMULATE:
				return SIMULATE;
			case ITM_TOOLSI:
				return ADD_TOOLS;
			case ITM_VALIDATE:
				return VALIDATE;
			case ITM_LOADI:
				return LOAD;
			case ITM_SAVEI:
				return SAVE;
			case ITM_EXITI:
				return EXIT;
			default:
				return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (UI.y_Coord >= UI.ToolBarHeight && UI.y_Coord < UI.height - UI.StatusBarHeight - UI.ToolBarHeight)
		{
			if (UI.addedTools) {
				if (UI.x_Coord >= 0 && UI.x_Coord <= UI.miniToolItemWidth)
				{
					int ClickedItemOrder = (UI.y_Coord - ((UI.height - ITM_L_TOOL_CNT * UI.miniToolItemWidth) / 2)) / UI.miniToolItemHeight;
					cout << ClickedItemOrder << endl;
					switch (ClickedItemOrder)
					{
					case ITM_LABEL:
						return ADD_Label;
					case ITM_UNDO:
						return UNDO;
					case ITM_REDO:
						return REDO;
					case ITM_DELETE:
						return DEL;
					case ITM_WIRE:
						return ADD_CONNECTION;
					default:
						return INVALID_AREA;
					}
				}
				else if (UI.x_Coord >= UI.width - UI.miniToolItemWidth && UI.x_Coord <= UI.width)
				{
					int ClickedItemOrder = (UI.y_Coord - ((UI.height - ITM_R_TOOL_CNT * UI.miniToolItemWidth) / 2)) / UI.miniToolItemHeight;
					cout << ClickedItemOrder << endl;
					switch (ClickedItemOrder)
					{
					case ITM_EDIT_CONNECTION:
						return EDIT_CONNECTION;
					case ITM_COPY:
						return COPY;
					case ITM_CUT:
						return CUT;
					case ITM_PASTE:
						return PASTE;
					default:
						return INVALID_AREA;
					}
				}
				else
				{
					char c = 'a';
					if (pWind->GetKeyPress(c) == ASCII && c == ' ')
					{
						return MULTISELECT;
					}
					return SELECT;
				}
			}
			else
			{
				if (UI.x_Coord >= UI.miniToolItemWidth && UI.x_Coord <= UI.width - UI.miniToolItemWidth)
				{
					char c = 'a';
					if (pWind->GetKeyPress(c) == ASCII && c == ' ')
						return MULTISELECT;
					return SELECT;
				}
				else
				{
					return INVALID_AREA;
				}
			}
		}
		if (UI.y_Coord >= UI.height - UI.StatusBarHeight - UI.ToolBarHeight && UI.y_Coord < UI.height - UI.StatusBarHeight)
		{
			if (UI.addedGates)
			{
				if (UI.firstGates)
				{
					int ClickedItemOrder = (UI.x_Coord - ((UI.width - ITM_CNT_TOOL_BAR1 * UI.ToolItemWidth) / 2)) / UI.ToolItemWidth;
					switch (ClickedItemOrder)
					{
					case ITM_BUFF:
						return ADD_Buff;
					case ITM_INV:
						return ADD_INV;
					case ITM_AND2:
						return ADD_AND_GATE_2;//AND gate item in menu
					case ITM_OR2:
						return ADD_OR_GATE_2;//OR gate item in menu
					case ITM_NAND2:
						return ADD_NAND_GATE_2;
					case ITM_NOR2:
						return ADD_NOR_GATE_2;
					case ITM_XOR2:
						return ADD_XOR_GATE_2;
					case ITM_SCROLL:
						return ITM_SCROLL_1;
					default:
						return DSN_TOOL;
					}
				}
				else
				{
					int ClickedItemOrder = (UI.x_Coord - ((UI.width - ITM_CNT_TOOL_BAR2 * UI.ToolItemWidth) / 2)) / UI.ToolItemWidth;
					cout << ClickedItemOrder << endl;
					switch (ClickedItemOrder)
					{
					case ITM_AND3:
						return ADD_AND_GATE_3;
					case ITM_NOR3:
						return ADD_NOR_GATE_3;
					case ITM_XOR3:
						return ADD_XOR_GATE_3;//AND gate item in menu
					case ITM_SWITCH:
						return ADD_Switch;//OR gate item in menu
					case ITM_LED:
						return ADD_LED;
					case ITM_XNOR2:
						return ADD_XNOR_GATE_2;
					case ITM_SCROLL2:
						return ITM_SCROLL_2;
					default:
						return DSN_TOOL;
					}
				}
			}
			else
			{
				return DSN_MODE;
			}
		}
		else
		{
			return STATUS_BAR;
		}
	}
	else
	{
		if (UI.y_Coord >= 0 && UI.y_Coord <= UI.ToolBarHeight)
		{
			int ClickedItemOrder = (UI.x_Coord - ((UI.width - ITM_SIM_CNT * UI.ToolItemWidth) / 2)) / UI.ToolItemWidth;
			switch (ClickedItemOrder)
			{
			case ITM_SIM:
				return SIMULATE;
				break;
			case ITM_TRUTH:
				return Create_TruthTable;
				break;
			case ITM_TOOLS:
				return ADD_TOOLS;
				break;
			case ITM_VALIDATE_SIM:
				return VALIDATE;
				break;
			case ITM_SAVE_SIM:
				return SAVE;
				break;
			case ITM_LOAD_SIM:
				return LOAD;
				break;
			case ITM_EXIT_SIM:
				return DSN_MODE;
			}
		}

		else if (UI.y_Coord > UI.ToolBarHeight && UI.y_Coord < UI.height - UI.StatusBarHeight - UI.ToolBarHeight)
		{
			return SELECT;
		}
	}
}
void Input::waitForEscapePress()
{
	char c;
	while (pWind->GetKeyPress(c) != ESCAPE) {}
	return;
}
Input::~Input()
{

}


/*
 1- getString ==> fareed
 2- sim mode ==> after finishing sim toolbar
*/