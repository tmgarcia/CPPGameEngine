#include "AStarDebugToolbar.h"

AStarDebugToolbar* AStarDebugToolbar::theInstance;

AStarDebugToolbar& AStarDebugToolbar::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new AStarDebugToolbar();
	}
	return *theInstance;
}