#include "ActionAddCircle.h"
#include "..\Figures\CCircle.h"
#include <math.h>
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo ElpsGfxInfo;
	ElpsGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElpsGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	ElpsGfxInfo.FillClr = pGUI->getCrntFillColor();
	ElpsGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read ellipse data from the user

	pGUI->PrintMessage("New Circle: Click at center point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Circle: Click at point at the circumference");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	

	//2.2- Identify the bottom right corner of the square
	int radius;
	radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2))

	//2.2- Calculate ellipse side legnth
	//The ellipse side length would be the longer distance between the two points coordinates
	//int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a ellipse with the parameters read from the user
	CCircle* R = new CCircle(topLeft, radius, ElpsGfxInfo);

	//Step 4 - Add the ellipse to the list of figures
	pManager->AddFigure(E);
}
