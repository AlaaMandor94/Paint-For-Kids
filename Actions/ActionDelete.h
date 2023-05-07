#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class ActionDelete : public Action {
	int DeletedID; //ID of the deleted figure (for use in RemoveFig())
	int selectedCount; //Number of selected figures
	CFigure* const* SelectedShapes; 
public:
	ActionDelete(ApplicationManager* pApp);


	virtual void Execute();
};
