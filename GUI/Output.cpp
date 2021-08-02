#include "Output.h"
#include <iostream>
Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = color(117, 117, 117);

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");
	ClearDrawingArea();

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}
const int Design_Bar_X = (UI.width - (ITM_DSN_COUNT * UI.ToolItemWidth)) / 2; // Design toolbar x
const int gate1_x1 = (UI.width - ITM_CNT_TOOL_BAR1 * UI.ToolItemWidth) / 2; // Gate1 x
const int gate1_x2 = (UI.width - ITM_CNT_TOOL_BAR2 * UI.ToolItemWidth) / 2; // Gate1 x
//const int tools_x = (UI.width - (ITM_TOOL_CNT * UI.ToolItemWidth)) / 2; // tools x
const int Design_Bar_Y = UI.ToolBarHeight; // toolbarheight
const int height = UI.height - UI.ToolBarHeight - UI.StatusBarHeight;
const int tools_y1 = (UI.height - (ITM_L_TOOL_CNT * UI.miniToolItemHeight)) / 2;
const int tools_y2 = (UI.height - (ITM_R_TOOL_CNT * UI.miniToolItemHeight)) / 2;
const int error = 14;
//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
buttonstate Output::getLeftButtonState(int& x, int& y)
{
	return pWind->GetButtonState(LEFT_BUTTON, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void Output::printMsgOnDrawingArea(string msg, int xi, int yi)
{
	ClearStatusBar();
	//ClearDrawingArea();
	//pWind->SetFont(50, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetFont(16, BOLD | ITALICIZED, BY_NAME, "Arial");
	//pWind->SetPen(UI.MsgColor);
	pWind->SetPen(BLACK);
	pWind->DrawString(xi, yi, msg);
}
void Output::DeleteDesignToolBar() const
{
	GraphicsInfo temp;
	temp.x1 = 0;
	temp.y1 = 0;
	temp.x2 = UI.width;
	temp.y2 = UI.ToolBarHeight;
	this->DrawRectangle(temp);
}

void Output::DeleteToolsToolBar() const
{
	GraphicsInfo Left;
	Left.x1 = 0;
	Left.y1 = UI.height - tools_y1;
	Left.x2 = UI.miniToolItemWidth + 5;
	Left.y2 = UI.height - tools_y1 - UI.AND2_Height * 5 - 5;
	this->DrawRectangle(Left);

	GraphicsInfo Right;
	Right.x1 = UI.width - UI.miniToolItemWidth - error - 5;
	Right.y1 = UI.height - tools_y1;
	Right.x2 = UI.width;
	Right.y2 = UI.height - tools_y1 - UI.AND2_Height * 5 - 5;
	this->DrawRectangle(Right);
}

//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::makeTruthTableWindow(int num)
{
	
}
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(color(117, 117, 117));
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item

	//TODO: Prepare image for each menu item and add it to the list
	//(1) //images ==> not easy you have to make some photos yourself(if you didn't find it in google)

	//Draw menu item one image at a time
	/*for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);
		*/string MenuItemImages[ITM_DSN_COUNT];
		if (!UI.addedGates)
			MenuItemImages[ITM_ADD_GATE] = "images\\Menu\\add-icon-260nw-571594759.jpg";
		else
			MenuItemImages[ITM_ADD_GATE] = "images\\Menu\\exitSimulation (2).jpg";
		MenuItemImages[ITM_SIMULATE] = "images\\Menu\\download22.jpg";
		MenuItemImages[ITM_TOOLSI] = "images\\Menu\\download (1).jpg";
		MenuItemImages[ITM_VALIDATE] = "images\\Menu\\validation.jpg";
		MenuItemImages[ITM_LOADI] = "images\\Menu\\download (2).jpg";
		MenuItemImages[ITM_SAVEI] = "images\\Menu\\import-512.jpg";
		MenuItemImages[ITM_EXITI] = "images\\Menu\\images.jpg";
		int y1 = 50;

		for (int i = 0; i < ITM_DSN_COUNT; i++)
		{
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + Design_Bar_X, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			y1 += 70;
		}
		//Draw a line under the toolbar
		pWind->SetPen(BLACK, 5);
		pWind->DrawLine(150, 0, 850, 0);
		//pWind->DrawLine(Design_Bar_X, UI.ToolBarHeight, UI.width-150, UI.ToolBarHeight);
		pWind->SetPen(BLACK, 5);

		pWind->DrawLine(Design_Bar_X, UI.ToolBarHeight, Design_Bar_X, 0);
		pWind->SetPen(BLACK, 5);
		pWind->DrawLine(850, UI.ToolBarHeight, 850, 0);

		pWind->SetPen(BLACK, 5);
		pWind->DrawLine(150, 100, 850, 100);


}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	//DeleteDesignToolBar();
	DeleteToolsToolBar();
	DeleteGatesToolBar();
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\download22.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\exitSimulation (3).jpg";
	MenuItemImages[ITM_TOOLS] = "images\\Menu\\download (1).jpg";
	MenuItemImages[ITM_VALIDATE_SIM] = "images\\Menu\\validation.jpg";
	MenuItemImages[ITM_LOAD_SIM] = "images\\Menu\\download (2).jpg";
	MenuItemImages[ITM_SAVE_SIM] = "images\\Menu\\import-512.jpg";
	MenuItemImages[ITM_EXIT_SIM] = "images\\Menu\\exitSimulation (1).jpg";
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + Design_Bar_X, 0, UI.ToolItemWidth, UI.ToolBarHeight);
}
void Output::DeleteGatesToolBar() const
{
	GraphicsInfo temp;
	temp.x1 = 0;
	temp.y1 = UI.height - UI.StatusBarHeight - UI.ToolBarHeight;
	temp.x2 = UI.width;
	temp.y2 = UI.height - UI.StatusBarHeight;
	this->DrawRectangle(temp);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
void Output::CreateGatesToolBar(bool selected) const
{
	UI.AppMode = DESIGN;	//Design Mode
	DeleteGatesToolBar();
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	if (selected)
	{
		string MenuItemImages[ITM_CNT_TOOL_BAR1];
		MenuItemImages[ITM_BUFF] = "images\\Gates\\active\\buffer.jpg";
		MenuItemImages[ITM_INV] = "images\\Gates\\active\\not.jpg";
		MenuItemImages[ITM_AND2] = "images\\Gates\\and.jpg";
		MenuItemImages[ITM_OR2] = "images\\Gates\\active\\or.jpg";
		MenuItemImages[ITM_NAND2] = "images\\Gates\\active\\nand.jpg";
		MenuItemImages[ITM_NOR2] = "images\\Gates\\active\\nor.jpg";
		MenuItemImages[ITM_XOR2] = "images\\Gates\\active\\xor.jpg";
		MenuItemImages[ITM_SCROLL] = "images\\Gates\\active\\aaa.jpg";

		//TODO: Prepare image for each menu item and add it to the list

		//Draw menu item one image at a time
		for (int i = 0; i < ITM_CNT_TOOL_BAR1; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + gate1_x1, height, UI.ToolItemWidth, UI.ToolBarHeight);
	}

	else
	{
		string Gates2[ITM_CNT_TOOL_BAR2];
		Gates2[ITM_XNOR2] = "images\\Gates\\active\\xnor.jpg";
		Gates2[ITM_AND3] = "images\\Gates\\active\\and3.jpg";
		Gates2[ITM_NOR3] = "images\\Gates\\active\\nor3.jpg";
		Gates2[ITM_XOR3] = "images\\Gates\\active\\xor3.jpg";
		Gates2[ITM_SWITCH] = "images\\Gates\\active\\switch.jpg";
		Gates2[ITM_LED] = "images\\Gates\\active\\led.jpg";
		Gates2[ITM_SCROLL2] = "images\\Gates\\active\\SCrolll.jpg";
		//TODO: Prepare image for each menu item and add it to the list

		//Draw menu item one image at a time
		for (int i = 0; i < ITM_CNT_TOOL_BAR2; i++) {
			pWind->DrawImage(Gates2[i], i * UI.ToolItemWidth + gate1_x2, height, UI.ToolItemWidth, UI.ToolBarHeight);
		}

	}
}
void Output::CreateToolsToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode
	string MenuItemImages1[ITM_L_TOOL_CNT];
	string MenuItemImages2[ITM_R_TOOL_CNT];
	MenuItemImages1[ITM_LABEL] = "images\\Gates\\download (3).jpg";
	MenuItemImages1[ITM_UNDO] = "images\\Gates\\Undo.jpg";
	MenuItemImages1[ITM_REDO] = "images\\Gates\\redo.jpg";
	MenuItemImages1[ITM_DELETE] = "images\\Gates\\download (4).jpg";
	MenuItemImages1[ITM_WIRE] = "images\\Gates\\images (1).jpg";
	MenuItemImages2[ITM_EDIT_CONNECTION] = "images\\Menu\\edit.jpg";
	MenuItemImages2[ITM_COPY] = "images\\Gates\\toolbar\\active\\copy.jpg";
	MenuItemImages2[ITM_CUT] = "images\\Gates\\toolbar\\active\\cut.jpg";
	MenuItemImages2[ITM_PASTE] = "images\\Gates\\toolbar\\active\\paste.jpg";
	for (int i = 0; i < ITM_L_TOOL_CNT; i++) {
		pWind->DrawImage(MenuItemImages1[i], 0, tools_y1 + i * UI.miniToolItemHeight, UI.miniToolItemWidth, UI.miniToolItemHeight);
		//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
		pWind->SetPen(BLACK, 4);
		pWind->DrawLine(0, tools_y1 + i * UI.miniToolItemHeight, UI.miniToolItemWidth, i * UI.miniToolItemHeight + tools_y1);
	}
	for (int i = 0; i < ITM_R_TOOL_CNT; i++) {
		pWind->DrawImage(MenuItemImages2[i], UI.width - UI.miniToolItemWidth - error, tools_y2 + i * UI.miniToolItemHeight, UI.miniToolItemWidth, UI.miniToolItemHeight);
		pWind->SetPen(BLACK, 4);
		pWind->DrawLine(UI.width - UI.miniToolItemWidth - error, tools_y2 + i * UI.miniToolItemHeight, UI.width, i * UI.miniToolItemHeight + tools_y2);
	}
}
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{


	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\andhighlight.jpg";
	else
		GateImage = "Images\\Gates\\and2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\or.jpg";
	else
		GateImage = "Images\\Gates\\or.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\nand.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\nand.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\not.jpg";

	else
		GateImage = "Images\\Gates\\components\\active\\not.jpg";

	//Draw INV Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by INV Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\xor.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\xor.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{


	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\xnor.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\xnor.jpg";
	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\nor.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\nor.jpg";
	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{

	string GateImage;
	if (UI.AppMode == DESIGN) {
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\components\\highlighted\\switch_off.jpg";
		else
			GateImage = "Images\\Gates\\components\\active\\switch_off.jpg";
	}
	if (UI.AppMode == SIMULATION) {
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\components\\active\\switch_onn.jpg";
		else
			GateImage = "Images\\Gates\\components\\active\\switch_off.jpg";
	}

	//Draw SWITCH Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by SWITCH Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (UI.AppMode == DESIGN) {
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\components\\highlighted\\led_off.jpg";
		else
			GateImage = "Images\\Gates\\components\\active\\led_off.jpg";
	}
	if (UI.AppMode == SIMULATION) {
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\components\\active\\led_on.jpg";
		else
			GateImage = "Images\\Gates\\components\\active\\led_off.jpg";
	}


	//Draw LED Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\and3.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\and3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\nor3.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\nor3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\xor3.jpg";
	else
		GateImage = "Images\\Gates\\components\\active\\xor3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\components\\highlighted\\buffer.jpg";
	else
		GateImage = "Images\\Gates\\buffer.jpg";

	//Draw BUFFER Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by BUFFER Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
//TODO: Add similar functions to draw all components

//TODO: Add similar functions to draw all components


//(2) ==> search for images and the code is nearly the same as above
// a selected image is the same photo with a highlight

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected, const color& colPen) const
{
	pWind->SetPen(colPen, 2);
	//if (r_GfxInfo.x1 == r_GfxInfo.x2)
		//pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	if (r_GfxInfo.x1 > r_GfxInfo.x2)
	{
		int avgPixels = (r_GfxInfo.x1 - r_GfxInfo.x2) / 2;
		int addedArea = 10;
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2 + addedArea);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2 + addedArea, r_GfxInfo.x2 - addedArea, r_GfxInfo.y2 + addedArea);
		pWind->DrawLine(r_GfxInfo.x2 - addedArea, r_GfxInfo.y2 + addedArea, r_GfxInfo.x2 - addedArea, r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x2 - addedArea, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	else
	{
		int avgPixels = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2;
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + avgPixels, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x1 + avgPixels, r_GfxInfo.y1, r_GfxInfo.x1 + avgPixels, r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x1 + avgPixels, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
}
void Output::DrawRectangle(int x1, int y1, int x2, int y2) const
{
	pWind->SetPen(color(117, 117, 117), 1);
	pWind->SetBrush(color(117, 117, 117));
	pWind->DrawRectangle(x1, y1, x2, y2);
}
void Output::DrawRectangle(GraphicsInfo GIinfo) const
{
	pWind->SetPen(color(117, 117, 117), 1);
	pWind->SetBrush(color(117, 117, 117));
	pWind->DrawRectangle(GIinfo.x1, GIinfo.y1, GIinfo.x2, GIinfo.y2);
}
void Output::makeTruthTableOnWindows(string str)
{
	
	int numOfInput = str.find("|");
	int numOfOutput = str.find("\n") - numOfInput;
	int n = str.size();
	int x_pos = 0;
	int y_pos = 0;
	int first_x_pos = 0;
	int y_step = 20, x_step = 20;
	pWind->DrawRectangle(0 , 0, UI.width , UI.height);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '\n')
		{
			x_pos = first_x_pos;
			y_pos += y_step;
		}
		else if(str[i] == '|')
		{
			pWind->SetPen(BLACK);
			pWind->SetBrush(BLACK);
			pWind->DrawLine(x_pos + x_step - 5, 0, x_pos + x_step - 5, UI.height );
		}
		else
		{
			x_pos += x_step;
			string temp = "";
			temp += str[i];
			pWind->DrawString(x_pos, y_pos, temp);
		}
		if (y_pos + y_step >= UI.height - UI.StatusBarHeight)
		{
			x_pos += 20 * (numOfInput + numOfOutput);
			first_x_pos += 20 * (numOfInput + numOfOutput);
			y_pos = 0;
		}
	}
}
void Output::updateAllDrawingArea()
{
	pWind->SetPen(WHITE);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->SetPen(color(117, 117, 117));
	pWind->SetBrush(color(117, 117, 117));
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	ClearDrawingArea();
	CreateSimulationToolBar();
	CreateStatusBar();
}
Output::~Output()
{
	delete pWind;
}

/*
 1- create sim bar // fareed and asaad
 2- draw connection
 3- drawing gates // lotfy and hamdy
 4- create design toolbar // lotfy and hamdy
*/