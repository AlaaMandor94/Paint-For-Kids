#ifndef ACTION_ADD_Circle_H
#define ACTION_ADD_Circle_H

#include "Action.h"

//Add Circle Action class
class ActionAddCircle : public Action
{
public:
	ActionAddCircle(ApplicationManager* pApp);

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

#endif