#ifndef ACTION_ADD_Chng_Fill_H
#define ACTION_ADD_Chng_Fill_H

#include "Action.h"

//Add ellipse Action class
class ActionChngFillColor : public Action
{
public:
	ActionChngFillColor(ApplicationManager* pApp);

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif