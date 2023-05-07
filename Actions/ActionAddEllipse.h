#ifndef ACTION_ADD_Ellipse_H
#define ACTION_ADD_Ellipse_H

#include "Action.h"

//Add ellipse Action class
class ActionAddEllipse : public Action
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	//Add ellipse to the ApplicationManager
	virtual void Execute();

};

#endif