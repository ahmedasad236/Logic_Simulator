#include "Load.h"

Load::Load(ApplicationManager * pApp) : Action(pApp)
{
}

void Load::ReadActionParameters()
{
	mRead.open("Circuit.txt");

	{
		pManager->deleteAll();
		string s;
		Action* pAct = NULL;
		int c;
		int i = 0;
		mRead >> c;
		int fff = c;
		while (mRead >> s, s != "-1" && i < fff) {
			int id;
			string label;
			int x1, y1;
			GraphicsInfo gm;
			if (mRead.eof()) {
				break;
			}
			else if (s == "AND2") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddANDgate2(pManager, gm);
				pManager->AddToActionList(ADD_AND_GATE_2);
			}
			else if (s == "BUFFER") {
				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddBUFFER(pManager, gm);
				pManager->AddToActionList(ADD_Buff);

			}
			else if (s == "NOT") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddNOTgate(pManager, gm);
				pManager->AddToActionList(ADD_INV);

			}
			else if (s == "OR2") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddORgate2(pManager, gm);
				pManager->AddToActionList(ADD_OR_GATE_2);

			}
			else if (s == "NAND2") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddNANDgate2(pManager, gm);
				pManager->AddToActionList(ADD_NAND_GATE_2);
			}
			else if (s == "NOR2") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddNORgate2(pManager, gm);
				pManager->AddToActionList(ADD_NOR_GATE_2);
			}
			else if (s == "XNOR2") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddXNORgate2(pManager, gm);
				pManager->AddToActionList(ADD_XNOR_GATE_2);
			}
			else if (s == "XOR2") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddXORgate2(pManager, gm);
				pManager->AddToActionList(ADD_XOR_GATE_2);
			}
			else if (s == "AND3") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddANDgate3(pManager, gm);
				pManager->AddToActionList(ADD_AND_GATE_3);
			}
			else if (s == "NOR3") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddNORgate3(pManager, gm);
				pManager->AddToActionList(ADD_NOR_GATE_3);
			}
			else if (s == "XOR3") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddXORgate3(pManager, gm);
				pManager->AddToActionList(ADD_XOR_GATE_3);
			}
			else if (s == "SWITCH") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddSWITCH(pManager, gm);
				pManager->AddToActionList(ADD_Switch);

			}
			else if (s == "LED") {

				mRead >> id;
				mRead >> label;
				mRead >> x1 >> y1;

				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				pAct = new AddLED(pManager, gm);
				pManager->AddToActionList(ADD_LED);
			}
			if (s == "CONNECTIONS") {
				while (c - i > 0) {
					int pinnum;
					int id_1, id_2;;
					Component* c1;
					Component* c2;
					mRead >> id_1 >> id_2 >> pinnum;
					c1 = pManager->getComponentByID(id_1);
					c2 = pManager->getComponentByID(id_2);
					pAct = new AddConnection(pManager, c1, c2, pinnum);
					pManager->AddToActionList(ADD_CONNECTION);
					pAct->Execute();

					i++;
				}
			}
			if (dynamic_cast<AddANDgate2*> (pAct) != NULL || dynamic_cast<AddORgate2*> (pAct) != NULL || dynamic_cast<AddBUFFER*> (pAct) != NULL || dynamic_cast<AddNOTgate*> (pAct) != NULL || dynamic_cast<AddNANDgate2*> (pAct) != NULL || dynamic_cast<AddNORgate2*> (pAct) != NULL || dynamic_cast<AddXNORgate2*> (pAct) != NULL || dynamic_cast<AddXORgate2*> (pAct) != NULL || dynamic_cast<AddANDgate3*> (pAct) != NULL || dynamic_cast<AddNORgate3*> (pAct) != NULL || dynamic_cast<AddXORgate3*> (pAct) != NULL || dynamic_cast<AddSWITCH*> (pAct) != NULL || dynamic_cast<AddLED*> (pAct) != NULL || dynamic_cast<AddANDgate2*> (pAct) != NULL) {
				pAct->Execute();
				Component* LastAddedComp = pManager->getTheLastComponent();
				LastAddedComp->SetID(id);
				if (label != "$") {
					LastAddedComp->setLabel(label);
				}
				else {
					LastAddedComp->setLabel(" ");

				}
				if (label != "$")
					pManager->DrawComponentLabel(LastAddedComp, label);
				delete pAct;
				i++;
			}
			else {
				delete pAct;


			}
		}

		//code mlo4 lazama
		/*for (int i = 0; i < CompCount; i++) {
			if (mRead >> s, s != "-1", s != "AND", s != "BUFFER", s != "LED", s != "SWITCH", s != "XOR3", s != "NOR3", s != "AND3", s != "XOR2", s != "XNOR2", s != "NOR2", s != "NAND2", s != "OR2", s != "NOT") {
				int id;
				string label;
				int x1, y1;

				mRead >> id;
				CompList[i]->SetID(id);
				mRead >> label;
				CompList[i]->setLabel(label);
				mRead >> x1 >> y1;
				GraphicsInfo gm;
				gm.x1 = x1;
				gm.x2 = x1 + 50;
				gm.y1 = y1;
				gm.y2 = y1 + 50;
				CompList[i]->SetGraphicsInfo(gm);
			}

		}*/
	}
}

void Load::Execute()
{
	ReadActionParameters();
	pManager->GetOutput()->PrintMsg("Loaded");
}

void Load::Undo()
{
}

void Load::Redo()
{
}

Load::~Load()
{
	mRead.close();

}
