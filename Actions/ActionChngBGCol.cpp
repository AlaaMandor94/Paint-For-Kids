#include "ActionChngBGCol.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChngBGCol::ActionChngBGCol(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionChngBGCol::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo TriGfxInfo;
	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	TriGfxInfo.FillClr = pGUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read data from the user
	pGUI->CreateColorToolBar();
	pGUI->PrintMessage("Click at the color you want");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->ClearStatusBar();

	//2.1- Identify the required color of the BG

	UI.BkGrndColor = pGUI->pWind->GetColor(P1.x, P1.y);
	pGUI->ClearDrawArea();
	pGUI->ClearColorArea();
	//pGUI->ClearStatusBar();





	
}
