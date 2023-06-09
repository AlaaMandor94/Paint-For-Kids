#include "ActionSelect.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <math.h>

ActionSelect::ActionSelect(ApplicationManager * pApp):Action(pApp)
{}

void ActionSelect::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Click at any point");	
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	CFigure* r = pManager->GetFigure(P1.x, P1.y);

	if (r)
	{
		r->SetSelected(!r->IsSelected());
		if (r->IsSelected())
		{
			pManager->AddSelected(r);
		}
		else
		{
			pManager->RemoveSelected(r);
		}
	}
}

