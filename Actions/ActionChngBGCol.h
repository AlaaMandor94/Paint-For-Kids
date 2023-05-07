#ifndef ACTION_ADD_Chng_BG_Col_H
#define ACTION_ADD_Chng_BG_Col_H

#include "Action.h"

//Add ellipse Action class
class ActionChngBGCol : public Action
{
public:
	ActionChngBGCol(ApplicationManager* pApp);

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif