#include "ActionDelete.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

void ActionDelete::Execute() {
	//Get a Pointer to the GUI 
	GUI* pGUI = pManager->GetGUI();

	//Initialise local SelectedFigs and selectedCount 
	SelectedShapes = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();
	

	//Check if a figure is selected
	if (SelectedShapes[0] == NULL)
		pGUI->PrintMessage("Select figure first");
	else {
		for (int i = 0; i < selectedCount; i++) {
			
			DeletedID = SelectedShapes[i]->GetID();

			
			pManager->RemoveFig(DeletedID);
			delete SelectedShapes[i];
		}

		pManager->EmptySelectedArray();
		pGUI->ClearDrawArea();  
		pGUI->PrintMessage("Figure(s) Deleted");
	}
}
