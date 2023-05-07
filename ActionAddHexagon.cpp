#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo HexGfxInfo;
	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	HexGfxInfo.FillClr = pGUI->getCrntFillColor();
	HexGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read ellipse data from the user

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Hexagon: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Identify the bottom right corner of the square
	Point bottomright;
	bottomright.x = P1.x > P2.x ? P1.x : P2.x;
	bottomright.y = P1.y > P2.y ? P1.y : P2.y;

	//2.2- Calculate ellipse side length
	//The ellipse side length would be the longer distance between the two points coordinates
	//int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* E = new CHexagon(topLeft, bottomright, HexGfxInfo);

	//Step 4 - Add the Hexagon to the list of figures
	pManager->AddFigure(E);
}
