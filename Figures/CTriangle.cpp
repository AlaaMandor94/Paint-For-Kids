#include "CTriangle.h"

CTriangle::CTriangle(Point v1, Point v2, Point v3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo){
	P1 = v1;
	P2 = v2;
	P3 = v3;
	figureName = "SQUARE";
}


void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);		 
	
}

bool CTriangle::isInside(int x, int y)
{

	/* Calculate area of triangle ABC */
	float A = 0.5 * abs(P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y)); //a,b,c

	/* Calculate area of triangle PBC */
	float A1 = 0.5 * abs(x * (P2.y - P3.y) + P2.x * (P3.y - y) + P3.x * (y - P2.y)); //x,a,b
	/* Calculate area of triangle PAC */
	float A2 = 0.5 * abs(P1.x * (y - P3.y) + x * (P3.y - P1.y) + P3.x * (P1.y - y)); //x,a,c
	/* Calculate area of triangle PAB */
	float A3 = 0.5 * abs(P1.x * (P2.y - y) + P2.x * (y - P1.y) + x * (P1.y - P2.y)); //x,b,c

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}
