#ifndef CHexagon_H
#define CHexagon_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
public:
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool isInside(int x, int y);
};

#endif