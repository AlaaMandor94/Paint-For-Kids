#ifndef CTriangle_H
#define CTriangle_H

#include "CFigure.h"

class CTriangle : public CFigure
{
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool isInside(int x, int y);
};

#endif