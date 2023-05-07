#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionAddTriangle.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionChngBGCol.h"
#include "Actions\ActionChngDRCol.h"
#include "Actions\ActionChngFillColor.h"
#include "Actions\ActionDelete.h"
#include "Actions/ToPlayAction.h"
#include <string>
#include <string.h>
#include <iostream>
	

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	FigCount = 0;
	flag = 0;

	//initialise selectedCount to 0
	selectedCount = 0;
	selectedfigure = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		SelectedFigures[i] = NULL;
	}
}
void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
		
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			newAct = new ActionAddEllipse(this);
			break;


		case DRAW_TRI:
			newAct = new ActionAddTriangle(this);
			break;

		case DRAW_HEX:
			newAct = new ActionAddHexagon(this);
			break;

		case DRAW_SLCT:
			newAct = new ActionSelect(this);
			break;

		case DRAW_DELETE:
			newAct = new ActionDelete(this);
			break;

		case CHNG_DRAW_CLR:
			newAct = new ActionChngDRCol(this);
			break;

		case CHNG_BK_CLR:
			newAct = new ActionChngBGCol(this);
			break;

		case CHNG_FILL_CLR:
			newAct = new ActionChngFillColor(this);
			break;

		case TO_PLAY:
			newAct = new ToPlayAction(this);
			flag = 0;
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;

		default:		//for selection by double click
			newAct = new ActionSelect(this);
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount ){
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount);
		FigCount++;
		
	}
	
}
///////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->isInside(x, y))
			return FigList[i];

	}
	return NULL;


}

int ApplicationManager::getFigCount()const {
	return FigCount;
}

CFigure* ApplicationManager::getFigList(int i) const
{
	return FigList[i];
}

CFigure* ApplicationManager::getRandomFigure()
{
	if (FigCount)
	{
		srand(time(NULL));
		return FigList[rand() % FigCount];
	}
	return nullptr;
}



void ApplicationManager::unselectAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
}

int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}
////////////////////////////////////////////////////////////////////////////////////

CFigure* const* ApplicationManager::GetSelectedFigures() const {
	return SelectedFigures;
}

void ApplicationManager::RemoveFig(int ID) {
	for (int i = ID; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
		FigList[i]->SetID(i);
	}

	FigCount--;
	FigList[FigCount] = NULL;
}

void ApplicationManager::EmptySelectedArray() {
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigures[i] = NULL;
	}
	selectedCount = 0;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		if (!FigList[i]->isShapeHidden())
		{
			FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
		}

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
void ApplicationManager::changeFillColor(color Fclr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngFillClr(Fclr);
		}
	}
}

void ApplicationManager::AddSelected(CFigure* sf) {

	SelectedFigures[selectedCount] = sf;
	selectedCount++;
}

void ApplicationManager::RemoveSelected(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigures[i] == sf) {
			SelectedFigures[i] = SelectedFigures[selectedCount - 1];
			SelectedFigures[selectedCount - 1] = NULL;
			selectedCount--;
		}
	}
}

void ApplicationManager::displayAllFigures()
{
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->displayShape();
	}
}