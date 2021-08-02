#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Components\Component.h"
#include "AllActions.h"
#include <stack>
#include <vector>
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount; //Actual number of Components

	int actionCount; // Number of actions

	int delCount; //Number of deleted components

	int selectedCount; // Number of selected components

	int copiedCount;	//Number of copied components

	bool multiSelectVar; // Multiple Selection 

	int lastDeletedCount; // Last number of deleted components

	int deletedConnectionCount; // DeletedConnections count

	Component* Copiedlist[MaxCompCount];  //List of all Copied components

	Component* CompList[MaxCompCount]; //List of all Components (Array of pointers)

	Component* DeletedList[MaxCompCount]; //List of all deleted components

	Component* SelectedComponents[MaxCompCount]; // List of all selected components

	Component* DeletedConnection[50][3]; // Deleted Connections after Undo

	Output* OutputInterface; //pointer to the Output Clase Interface

	Input* InputInterface; //pointer to the Input Clase Interface

	stack<ActionType> ActionList; // A stack including all the actions done

	stack<ActionType> UndoList; // A stack including all undos made

	vector<Component*> thisLevel;

public:
	bool cut; // Cut boolean variable

	bool invalidEdit; // Determine whether edit is invalid or not

	bool MultipleDelete; // Determine whether the user has deleted a single component or many

	ApplicationManager(); // Constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();

	Input* GetInput();

	ActionType getTheLastActionDone(); // Get the last action made

	ActionType getTheLastUndo(); // Get the last undo made

	Component* getTheLastComponent(); // Get the last component in the list

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void AddToDeletedList(Component* pComp); // Add a component to the deleted list

	void AddToActionList(ActionType ActType); // Add a new action

	void RemoveFromActionList(); // Remove the last action from the action list

	int getActionListSize(); // Get the number of actions made

	void AddToUndoList(ActionType ActType); // Add a new undo 

	void RemoveFromUndoList(); // Remove the last undo

	int getUndoListSize(); // Get the number of undos made

	void DeleteFromCompList(Component* pComp); // Delete a component from the component list

	void DeleteFromDeletedList(Component* pComp); // Delete a component from the deleted list

	void DeleteConnections(Component *Comp); // Delete Connections of the Component Comp

	void DeleteCompWithConnections(Component* Comp = NULL); // Delete a component with its connections

	Component* getTheLastDeletedComponent(); // Get the last deleted component in the list

	void incrementLastDeletedCount(); // lastDeletedCount++

	void setLastDeletedCount(int l);

	void setOtherSelectedToFalse(Component* pComp); // Set all components to be unselected except for the one passed as an argument

	Component* getSelectedComponent(); // Get the selected component

	Component* getTheComponentConnectedTo(Connection* c); // Get the component connected to the passed connection

	void setSelectedCount(int s); // set selected components count

	int getSelectedCount();

	int getDeletedCount();

	void Unselect(); // Unselects all the components

	Component* getLastDeletedComponent(); // Get the last deleted component

	void DeleteComponentLabel(Component* Comp); // Delete a component's label

	void save(ofstream& f); // Save

	void DeleteConnectionLabel(Component* Comp); // Delete a connection's label

	int getlastDeletedCount();

	void DrawComponentLabel(Component* Comp, string word); // Draw a component's label which is word

	void DrawConnectionLabel(Component* Comp, string word); // Draw a connection's label on the drawing area

	void makeSelectedComponent(int x, int y); // Select or Unselect a component

	Component* getTheComponentClickedOn(); // Get the component clicked on

	void Undo(ActionType AType); // Undo drawing a component

	void Redo(ActionType AType); // Redo drawing a component

	void NewConnection(Connection* Conn);

	void RedoConnection();

	void AddToCopiedList(Component* pComp); // Add a component to the copied list

	void PasteCutComponent(GraphicsInfo G);

	void PasteFromCopiedList(GraphicsInfo g1);

	int setSwitches(); // Add switches

	void makeNewComponent(Component*); // Add a new component

	void makeCopyOfSelectedComponents(); // Add selected component to the copied list

	void OrganizeComponents(); // Organize

	string makeOutputForOneCase(string str); // For truth table

	void ExcuteSelectedSwitch(); // Execute the selected switch

	void setLeds(); // Add leds

	string CreateTruthTable(int switchNum = 0 , string str = "" ); // Create the Truth Table

	bool isValidCircuit(); // Circuit Validation

	bool organizeLevel();

	void deleteAll();

	Component* getComponentByID(int ID);

	~ApplicationManager();
};
#endif