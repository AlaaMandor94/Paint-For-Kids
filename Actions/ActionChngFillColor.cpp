#include "ActionChngFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChngFillColor::ActionChngFillColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionChngFillColor::Execute()
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

	pGUI->CreateColorToolBar();
	pGUI->PrintMessage("Change fill color: pick on any color");
	//Read point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->ClearStatusBar();
	color Fclr = pGUI->pWind->GetColor(P1.x, P1.y);

	pManager->changeFillColor(Fclr);
	pGUI->PrintMessage("Color changed successfully");
	pGUI->setCrntFillColor(Fclr);
	pGUI->ClearColorArea();
	//UI.FillColor = Fclr;




	
}
