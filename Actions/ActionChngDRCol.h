#ifndef ACTION_ADD_Chng_DR_Col_H
#define ACTION_ADD_Chng_DR_Col_H

#include "Action.h"

//Add ellipse Action class
class ActionChngDRCol : public Action
{
public:
	ActionChngDRCol(ApplicationManager* pApp);

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif