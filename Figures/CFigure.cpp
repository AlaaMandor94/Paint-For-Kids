#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	isHidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::SetID(int id)
{
	ID = id;
}

//Gets the figure ID

int CFigure::GetID() const
{
	return ID;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::getFigureName()
{
	return figureName;
}
bool CFigure::isShapeHidden() {
	return isHidden;
}
void CFigure::HideShape() {
	isHidden = true;
}
void CFigure::displayShape() {
	isHidden = false;
}