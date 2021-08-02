#include "ApplicationManager.h"
#include "AllActions.h"
#include <stack>
ApplicationManager::ApplicationManager()
{
	UI.addedGates = 0;
	UI.firstGates = 0;
	UI.addedTools = 0;
	CompCount = 0;
	delCount = 0;
	actionCount = 0;
	selectedCount = 0;
	copiedCount = 0;
	multiSelectVar = 0;
	MultipleDelete = 0;
	deletedConnectionCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		DeletedList[i] = NULL;
		SelectedComponents[i] = NULL;
		Copiedlist[i] = NULL;
	}
	for (int i = 0; i < 50; i++)
	{
		DeletedConnection[i][0] = NULL;
		DeletedConnection[i][1] = NULL;
		DeletedConnection[i][2] = NULL;
	}
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	if (pComp != NULL) {
		CompList[CompCount] = pComp;
		CompCount++;
	}
	Unselect();
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_Buff:
		AddToActionList(ADD_Buff);
		pAct = new AddBUFFER(this);
		break;
	case ADD_INV:
		AddToActionList(ADD_INV);
		pAct = new AddNOTgate(this);
		break;
	case ADD_AND_GATE_2:
		AddToActionList(ADD_AND_GATE_2);
		pAct = new AddANDgate2(this);
		break;
	case ADD_OR_GATE_2:
		AddToActionList(ADD_OR_GATE_2);
		pAct = new AddORgate2(this);
		break;
	case ADD_NAND_GATE_2:
		AddToActionList(ADD_NAND_GATE_2);
		pAct = new AddNANDgate2(this);
		break;
	case ADD_NOR_GATE_2:
		AddToActionList(ADD_NOR_GATE_2);
		pAct = new AddNORgate2(this);
		break;
	case ADD_XNOR_GATE_2:
		AddToActionList(ADD_XNOR_GATE_2);
		pAct = new AddXNORgate2(this);
		break;
	case ADD_XOR_GATE_2:
		AddToActionList(ADD_XOR_GATE_2);
		pAct = new AddXORgate2(this);
		break;
	case ADD_AND_GATE_3:
		AddToActionList(ADD_AND_GATE_3);
		pAct = new AddANDgate3(this);
		break;
	case ADD_NOR_GATE_3:
		AddToActionList(ADD_NOR_GATE_3);
		pAct = new AddNORgate3(this);
		break;
	case ADD_XOR_GATE_3:
		AddToActionList(ADD_XOR_GATE_3);
		pAct = new AddXORgate3(this);
		break;
	case ADD_Switch:
		AddToActionList(ADD_Switch);
		pAct = new AddSWITCH(this);
		break;
	case ADD_LED:
		AddToActionList(ADD_LED);
		pAct = new AddLED(this);
		break;
	case ADD_CONNECTION:
		AddToActionList(ADD_CONNECTION);
		pAct = new AddConnection(this);
		break;
	case ADD_Label:
		pAct = new Label(this);
		break;
	case EDIT_CONNECTION:
		//AddToActionList(EDIT_CONNECTION);
		pAct = new Edit(this);
		break;
	case ITM_SCROLL_1:
		UI.firstGates = 0;
		UI.addedGates = 1;
		OutputInterface->CreateGatesToolBar(UI.firstGates);
		break;
	case ITM_SCROLL_2:
		UI.firstGates = 1;
		UI.addedGates = 1;
		OutputInterface->CreateGatesToolBar(UI.firstGates);
		break;
	case UNDO:
		pAct = new undo(this);
		break;
	case REDO:
		pAct = new redo(this);
		break;
	case ADD_GATE:
		pAct = new AddGate(this);
		break;
	case Create_TruthTable:
		pAct = new TruthTable(this);
		break;
	case Change_Switch:
		break;
	case DEL:
		AddToActionList(DEL);
		lastDeletedCount = 0;
		pAct = new Delete(this);
		break;
	case SELECT:
		multiSelectVar = 0;
		pAct = new Select(this);
		break;
	case VALIDATE:
		pAct = new Validate(this);
		break;
	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case SAVE:
		pAct = new SaveFile(this);
		break;
	case LOAD:
		pAct = new Load(this);
		break;
	case PASTE:
		AddToActionList(PASTE);
		pAct = new Paste(this);
		break;
	case EXIT:
		pAct = new Exit(this);
		break;
	case SIMULATE:
		pAct = new simulate(this);
		break;
	case MULTISELECT:
		multiSelectVar = 1;
		pAct = new Select(this);
		break;
	case DSN_MODE:
		UI.AppMode = DESIGN;
		UI.addedGates = 1;
		UI.firstGates = 1;
		OutputInterface->CreateDesignToolBar();
		OutputInterface->CreateToolsToolBar();
		OutputInterface->CreateGatesToolBar(UI.firstGates);
		break;
	case ADD_TOOLS:
		UI.addedTools = 1;
		OutputInterface->CreateToolsToolBar();
	}
	if (pAct != NULL)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++) {
		if (UI.AppMode == DESIGN)
			CompList[i]->Draw(OutputInterface, CompList[i]->isSelected);
		else
		{
			if (dynamic_cast<SWITCH*> (CompList[i]) != NULL)
				CompList[i]->Draw(OutputInterface, (bool)CompList[i]->GetOutPinStatus());
			else if (dynamic_cast<led*>(CompList[i]) != NULL)
				CompList[i]->Draw(OutputInterface, (bool)CompList[i]->GetInputPinStatus(0));
			else if (dynamic_cast<Connection*>(CompList[i]) != NULL)
				CompList[i]->Draw(OutputInterface, (bool)CompList[i]->GetOutPinStatus());
			else
				CompList[i]->Draw(OutputInterface, 0);
		}
	}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

ActionType ApplicationManager::getTheLastActionDone()
{
	return ActionList.top();
}

ActionType ApplicationManager::getTheLastUndo()
{
	return UndoList.top();
}

Component* ApplicationManager::getTheLastComponent()
{
	return CompList[CompCount - 1];
}


void ApplicationManager::makeSelectedComponent(int x, int y)
{
	/*if (!multiSelectVar)
	{
		selectedCount = 0;
		for (int i = 0; i < CompCount; i++) CompList[i]->isSelected = 0;
	}*/
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->ClickedHere(x, y))
		{
			if (!multiSelectVar)
				setOtherSelectedToFalse(CompList[i]);
			if (CompList[i]->isSelected == true && UI.AppMode == DESIGN)
			{
				CompList[i]->isSelected = false;
				SelectedComponents[selectedCount--] = NULL;
				return;
			}
			else
			{
				CompList[i]->isSelected = true;
				SelectedComponents[selectedCount++] = CompList[i];
				return;
			}
		}
	}
}

void ApplicationManager::ExcuteSelectedSwitch()
{
	Component* pSwitch = dynamic_cast<SWITCH*>(getSelectedComponent());
	if (pSwitch != NULL)
	{
		pSwitch->Operate();
		Action* pAct = new simulate(this);
		pAct->Execute();
		delete pAct;
	}
}

////////////////////////////////////////////////////////////////////

Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::getTheComponentClickedOn()
{
	selectedCount = 0;
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->isSelected = 0;
	}
	Action* pAct;
	InputInterface->GetUserAction();
	pAct = new Select(this);
	pAct->Execute();
	UpdateInterface();
	delete pAct;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->isSelected)
			return CompList[i];
	}
	return NULL;
}

void ApplicationManager::Undo(ActionType AType)
{
	if (ActionList.size() >= 1)
	{
		Component* Comp = getTheLastComponent();
		AddToUndoList(AType);
		if (AType == ADD_CONNECTION)
		{
			if (dynamic_cast<Connection*>(Comp) != NULL)
				NewConnection((Connection*)Comp);
		}
		DeleteCompWithConnections(Comp);
		RemoveFromActionList();
	}
}

void ApplicationManager::Redo(ActionType AType)
{
	if (UndoList.size() >= 1)
	{
		Component* Comp = getTheLastDeletedComponent();
		if (AType == ADD_CONNECTION)
		{
			Connection* Conn = (Connection*)DeletedConnection[deletedConnectionCount - 1][0];
			Action* pAct = new AddConnection(this, DeletedConnection[deletedConnectionCount - 1][1], DeletedConnection[deletedConnectionCount - 1][2], Conn->getNumOfInputPin());
			pAct->Execute();
			int count = delCount;
			delete pAct;

			for (int i = 0; i < count; i++)
			{
				if (DeletedList[i] == Comp)
				{
					DeletedList[i] = DeletedList[delCount];
					DeletedList[delCount] = NULL;
					delCount--;
				}
			}
			Component* temp = getTheLastDeletedComponent();
			RedoConnection();
		}
		else
		{
			DeleteFromDeletedList(Comp);
		}
		if (dynamic_cast<Connection*>(Comp) == NULL)
			DrawComponentLabel(Comp, Comp->getLabel());
		else
			DrawConnectionLabel(Comp, Comp->getLabel());
		AddToActionList(AType);
		RemoveFromUndoList();
	}
}

void ApplicationManager::NewConnection(Connection* Conn)
{
	DeletedConnection[deletedConnectionCount][0] = Conn;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* G = dynamic_cast<Gate*>(CompList[i]);
		if (G != NULL && G->getOutputPin()->ConnectedTo((Connection*)DeletedConnection[deletedConnectionCount][0]))
		{
			DeletedConnection[deletedConnectionCount][1] = G;
			break;
		}
	}
	Connection* C = (Connection*)DeletedConnection[deletedConnectionCount][0];
	DeletedConnection[deletedConnectionCount][2] = Conn->getDestPin()->getComponent();
	deletedConnectionCount++;
}

void ApplicationManager::RedoConnection()
{
	DeletedConnection[deletedConnectionCount - 1][0] = NULL;
	DeletedConnection[deletedConnectionCount - 1][1] = NULL;
	DeletedConnection[deletedConnectionCount - 1][2] = NULL;
	deletedConnectionCount--;
}

void ApplicationManager::AddToCopiedList(Component* pComp)
{
	Copiedlist[copiedCount++] = pComp;
}

void ApplicationManager::PasteFromCopiedList(GraphicsInfo g1)
{
	if (Copiedlist[0] != NULL) {
		if (!cut)
		{
			for (int i = 0; i < 1; i++)
			{
				makeNewComponent(Copiedlist[copiedCount - 1]);
			}
		}
		else
		{
			makeNewComponent(Copiedlist[copiedCount - 1]);
			AddToDeletedList(Copiedlist[copiedCount - 1]);
			DeleteFromCompList(Copiedlist[copiedCount - 1]);
			cut = false;
		}
	}
	else {
		OutputInterface->PrintMsg("Make Copy or Cut Actions first");
		return;
	}
}

void ApplicationManager::PasteCutComponent(GraphicsInfo G)
{
	AddToDeletedList(Copiedlist[copiedCount - 1]);
	DeleteFromCompList(Copiedlist[copiedCount - 1]);
	Copiedlist[copiedCount - 1]->SetGraphicsInfo(G);
	AddComponent(Copiedlist[copiedCount - 1]);
	cut = false;
}
int ApplicationManager::getlastDeletedCount()
{
	return lastDeletedCount;
}
void ApplicationManager::incrementLastDeletedCount()
{
	lastDeletedCount++;
}
void ApplicationManager::setLastDeletedCount(int l)
{
	lastDeletedCount = l;
}
Component* ApplicationManager::getSelectedComponent()
{
	for (int i = 0; i < CompCount; i++)
		if (CompList[i]->isSelected)
			return CompList[i];

	return nullptr;
}

Component* ApplicationManager::getTheComponentConnectedTo(Connection* c)
{
	for (int i = 0; i < CompCount; i++) {

		Gate* temp = dynamic_cast<Gate*>(CompList[i]);
		if (temp != NULL && temp->ConnectedTo(c)) {

			return CompList[i];
		}
	}
	return NULL;
}

void ApplicationManager::AddToDeletedList(Component* pComp)
{
	DeletedList[delCount++] = pComp;
}

void ApplicationManager::AddToActionList(ActionType ActType)
{
	ActionList.push(ActType);
	actionCount++;
}

void ApplicationManager::RemoveFromActionList()
{
	ActionList.pop();
	actionCount--;
}

int ApplicationManager::getActionListSize()
{
	return ActionList.size();
}

void ApplicationManager::AddToUndoList(ActionType ActType)
{
	UndoList.push(ActType);
}

void ApplicationManager::RemoveFromUndoList()
{
	UndoList.pop();
}

int ApplicationManager::getUndoListSize()
{
	return UndoList.size();
}
void ApplicationManager::DeleteFromCompList(Component* pComp)
{
	
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == pComp)
		{
			GraphicsInfo r_GfxInfo = CompList[i]->GetGraphicsInfo();
			Connection* comp = dynamic_cast<Connection*> (CompList[i]);
			DeleteComponentLabel(CompList[i]);
			CompList[i]->isDeleted = 1;
			CompList[i] = CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;
			if (comp == NULL)
			{
				OutputInterface->DrawRectangle(r_GfxInfo);
			}
			else
			{
				OutputInterface->DrawConnection(r_GfxInfo, false, color(117, 117, 117));
				Gate* temp = dynamic_cast<Gate*>(comp->getDestPin()->getComponent());
				if (temp != NULL)
				{
					temp->freeInputPin(comp->getNumOfInputPin());
				}

				for (int j = 0; j < CompCount; j++)
				{
					Gate* temp2 = dynamic_cast<Gate*> (CompList[j]);
					if (temp2 != NULL)
					{
						if (temp2->ConnectedTo(comp))
						{
							temp2->decrementFanOut();
						}
					}
				}
			}
			return;
		}
	}
}

void ApplicationManager::DeleteFromDeletedList(Component* pComp)
{
	int count = delCount;

	for (int i = 0; i < count; i++)
	{
		if (DeletedList[i] == pComp)
		{
			AddComponent(DeletedList[i]);
			DeletedList[i] = DeletedList[delCount - 1];
			DeletedList[delCount - 1] = NULL;
			delCount--;
		}
	}
}

void ApplicationManager::DeleteConnections(Component* Comp)
{

	vector<Component*> deletedConnections;
	for (int i = 0; i < CompCount; i++)
	{
		Connection* Conn = dynamic_cast<Connection*>(CompList[i]);
		if (Conn != NULL)
		{
			if (Conn->getDestPin()->getComponent() == Comp)
			{
				deletedConnections.push_back(CompList[i]);
			}
			Gate* temp = dynamic_cast<Gate*>(Comp);
			if (temp != NULL && temp->ConnectedTo(Conn))
			{
				deletedConnections.push_back(CompList[i]);
			}
		}
	}
	for (int i = 0 ; i < deletedConnections.size() ; i++)
	{
		AddToActionList(DEL);
		DeleteCompWithConnections(deletedConnections[i]);
	}
}

void ApplicationManager::DeleteCompWithConnections(Component* Comp)
{
	lastDeletedCount = 0;
	MultipleDelete = false;
	if (Comp != NULL)
	{
		MultipleDelete = true;
		this->DeleteConnections(Comp);
		AddToDeletedList(Comp);
		DeleteFromCompList(Comp);
		lastDeletedCount++;
		return;
	}

	int n = selectedCount;
	if (n > 1)
		MultipleDelete = true;
	RemoveFromActionList();
	for (int i = 0; i < n; i++)
	{
		AddToActionList(DEL);
		this->DeleteConnections(SelectedComponents[i]);
		AddToDeletedList(SelectedComponents[i]);
		DeleteFromCompList(SelectedComponents[i]);
		lastDeletedCount++;
	}
}

void ApplicationManager::DeleteConnectionLabel(Component* Comp)
{
	GraphicsInfo LabelGfx = Comp->GetLabelGraphics();
	OutputInterface->DrawRectangle(LabelGfx);
}

void ApplicationManager::save(ofstream& f)
{

	f << CompCount << endl;
	for (int i = 0; i < CompCount; i++) {
		if(dynamic_cast<Gate *>(CompList[i]) != NULL){
			CompList[i]->save(f);
		}
	}
	f << "CONNECTIONS\n";
	for (int i = 0; i < CompCount; i++)
	{
		Connection* Conn = dynamic_cast<Connection*> (CompList[i]);
		if (Conn != NULL)
		{
			Conn->save(f, this->getTheComponentConnectedTo(Conn));
		}
	}

}
Component* ApplicationManager::getTheLastDeletedComponent()
{
	return DeletedList[delCount - 1];
}

void ApplicationManager::setOtherSelectedToFalse(Component* pComp)
{
	selectedCount = 0;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != pComp)
			CompList[i]->isSelected = false;
	}
}

Component* ApplicationManager::getLastDeletedComponent()
{
	return DeletedList[delCount - 1];
}

void ApplicationManager::setSelectedCount(int s)
{
	selectedCount = s;
}

int ApplicationManager::getSelectedCount()
{
	return selectedCount;
}

int ApplicationManager::getDeletedCount()
{
	return delCount;
}
void ApplicationManager::Unselect()
{
	selectedCount = 0;
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->isSelected = false;
		SelectedComponents[i] = NULL;
	}
}
int ApplicationManager::setSwitches()
{
	thisLevel.clear();
	for (int i = 0; i < CompCount; i++)
	{
		Component* temp = dynamic_cast<SWITCH*> (CompList[i]);
		if (temp != NULL)
		{
			thisLevel.push_back(temp);
		}
	}
	return thisLevel.size();
}
void ApplicationManager::makeNewComponent(Component* C) 
{
	Action* pAct = NULL;
	if (dynamic_cast<AND2*> (C) != NULL)
	{
		pAct = new AddANDgate2(this);
	}
	else if (dynamic_cast<buffer*> (C) != NULL)
	{
		pAct = new AddBUFFER(this);
	}
	else if (dynamic_cast<NOT*> (C) != NULL)
	{
		pAct = new AddNOTgate(this);
	}
	else if (dynamic_cast<OR2*> (C) != NULL)
	{
		pAct = new AddORgate2(this);
	}
	else if (dynamic_cast<NAND2*> (C) != NULL)
	{
		pAct = new AddNANDgate2(this);
	}
	else if (dynamic_cast<NOR2*> (C) != NULL)
	{
		pAct = new AddNORgate2(this);
	}
	else if (dynamic_cast<XNOR2*> (C) != NULL)
	{
		pAct = new AddXNORgate2(this);
	}
	else if (dynamic_cast<XOR2*> (C) != NULL)
	{
		pAct = new AddXORgate2(this);
	}
	else if (dynamic_cast<AND3*> (C) != NULL)
	{
		pAct = new AddANDgate3(this);
	}
	else if (dynamic_cast<NOR3*> (C) != NULL)
	{
		pAct = new AddNORgate3(this);
	}
	else if (dynamic_cast<XOR3*> (C) != NULL)
	{
		pAct = new AddXORgate3(this);
	}
	else if (dynamic_cast<SWITCH*> (C) != NULL)
	{
		pAct = new AddSWITCH(this);
	}
	else if (dynamic_cast<led*> (C) != NULL)
	{
		pAct = new AddLED(this);
	}
	if (pAct != NULL) {
		pAct->Execute();
		CompList[CompCount - 1]->setLabel(Copiedlist[copiedCount - 1]->getLabel());
		DrawComponentLabel(CompList[CompCount - 1], Copiedlist[copiedCount - 1]->getLabel());
	}
	delete pAct;


} 
void ApplicationManager::makeCopyOfSelectedComponents()
{
	copiedCount = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->isSelected)
		{
			AddToCopiedList(CompList[i]);
		}
	}
}
void ApplicationManager::OrganizeComponents()
{
	setSwitches();
	bool Organized = 0;
	while (!Organized)
	{
		Organized = organizeLevel();
	}
}
string ApplicationManager::makeOutputForOneCase(string str)
{
	setSwitches();
	int n = thisLevel.size();
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		if (str[i] == '1') temp = 1;
		if (thisLevel[i]->GetOutPinStatus() != temp)
		{
			thisLevel[i]->Operate();
		}
		printf("%d ", thisLevel[i]->GetOutPinStatus());
	}
	str += "|";
	OrganizeComponents();
	setLeds();
	for (auto i : thisLevel)
	{
		if (i->GetInputPinStatus(0)) str += "1";
		else str += "0";
		printf("%d ", i->GetInputPinStatus(0));
	}
	printf("\n");
	setSwitches();
	return str;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::setLeds()
{
	thisLevel.clear();
	for (int i = 0; i < CompCount; i++)
	{
		Component* temp = dynamic_cast<led*> (CompList[i]);
		if (temp != NULL)
		{
			thisLevel.push_back(temp);
		}
	}
}

// take setSwitches and createTruthTable from your code makeOutPutforOneCase
string ApplicationManager::CreateTruthTable(int switchNum , string str  )
{
	setSwitches();
	if (switchNum == thisLevel.size())
	{
		string temp = makeOutputForOneCase(str);
		return temp;
	}
	return CreateTruthTable(switchNum + 1, str + "0") + "\n" + CreateTruthTable(switchNum + 1, str + "1");
}
bool ApplicationManager::isValidCircuit()
{
	bool isSwitch = 0, isLed = 0;

	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<SWITCH*>(CompList[i]) != NULL) isSwitch = 1;
		else if (dynamic_cast<led*>(CompList[i]) != NULL) isLed = 1;
		Gate* temp = dynamic_cast<Gate*> (CompList[i]);
		if (temp != NULL && !temp->ValidConnection())
			return 0;
	}
	if(isSwitch && isLed)
		return 1;

	return 0;
}
bool ApplicationManager::organizeLevel()
{
	for (int i = 0; i < CompCount; i++)	CompList[i]->newLevel = 0;
	for (auto i : thisLevel)
	{
		i->setAllNewLevels();
		i->setAllStatus();
	}
	thisLevel.clear();
	bool allLed = 1;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->newLevel )
		{
			if (CompList[i]->ValidComponent())
			{
				CompList[i]->Operate();
				thisLevel.push_back(CompList[i]);
			}
			if (dynamic_cast<led*>(CompList[i]) == NULL)
			{
				allLed = 0;
			}
		}
	}
	return allLed;
}
void ApplicationManager::DeleteComponentLabel(Component* Comp)
{
	GraphicsInfo LabelGfx = Comp->GetLabelGraphics();
	OutputInterface->DrawRectangle(LabelGfx);
}

void ApplicationManager::DrawComponentLabel(Component* Comp, string word)
{
	GraphicsInfo LabelGfx;
	Comp->setLabel(word);
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	float x, y;
	float Cx = (Comp->GetGraphicsInfo().x1 + Comp->GetGraphicsInfo().x2) / 2.0;
	float Cy = Comp->GetGraphicsInfo().y2;
	if (word.size() <= 7) {
		x = Cx - (Len / 2.0) + ((Len / 7.0) * (7 - word.size()) / 2.4);
		y = (Cy - (1.36 * Wdth));
		Gate* GateSwitch = dynamic_cast<Gate*>(Comp);
		if (GateSwitch != NULL)
			if (dynamic_cast<SWITCH*>(GateSwitch) != NULL)
				y = (Cy - 1.3 * Wdth);
	}
	else
	{
		x = Cx - Len / 2.0 - (((Len / 7.0) * (word.size() - 7)) / 1.8);
		y = (Cy - (1.36 * Wdth));
		Gate* GateSwitch = dynamic_cast<Gate*>(Comp);
		if (GateSwitch != NULL)
			if (dynamic_cast<SWITCH*>(GateSwitch) != NULL)
				y = (Cy - 1.3 * Wdth);
	}
	LabelGfx.x1 = x;
	LabelGfx.x2 = x + (word.size() * (Len / 5.0));
	LabelGfx.y1 = Comp->GetGraphicsInfo().y1;
	LabelGfx.y2 = y;
	Comp->setLabelGraphics(LabelGfx);
	OutputInterface->printMsgOnDrawingArea(word, x, y);
	Unselect();
}
void ApplicationManager::DrawConnectionLabel(Component* Comp, string word)
{
	GraphicsInfo LabelGfx;
	float Gx1 = Comp->GetGraphicsInfo().x1;
	float Gx2 = Comp->GetGraphicsInfo().x2;
	float Gy1 = Comp->GetGraphicsInfo().y1;
	float Gy2 = Comp->GetGraphicsInfo().y2;
	Comp->setLabel(word);
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	float x, y;
	float Cx = (Gx1 + Gx2) / 2.0;
	float Cy;
	if (Gx1 < Gx2)
		Cy = Gy1 < Gy2 ? Gy1 : Gy2;
	else
		Cy = Gy2;
	if (word.size() <= 7) {
		x = Cx - (Len / 2.0) + ((Len / 7.0) * (7 - word.size()) / 2.4);
		if (Gx1 < Gx2)
			y = Cy - 17;
		else
			y = Cy - 6;
	}
	else
	{
		x = Cx - Len / 2.0 - (((Len / 7) * (word.size() - 7)) / 1.8);
		if (Gx1 < Gx2)
			y = Cy - 18;
		else
			y = Cy - 5;
	}
	LabelGfx.x1 = x;
	LabelGfx.x2 = x + (word.size() * (Len / 5.0));
	LabelGfx.y1 = y;
	LabelGfx.y2 = y + 20;
	Comp->setLabelGraphics(LabelGfx);
	OutputInterface->printMsgOnDrawingArea(word, x, y);
	Unselect();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::deleteAll()
{
	OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;
}

Component* ApplicationManager::getComponentByID(int ID)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetID() == ID)
			return CompList[i];
	}
	return NULL;
}

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
	}
	for (int i = 0; i < delCount; i++)
	{
		delete DeletedList[i];
	}
	delete OutputInterface;
	delete InputInterface;
}