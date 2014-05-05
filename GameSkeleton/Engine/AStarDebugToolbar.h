#include <QtGui\qtoolbar.h>

#pragma once
class __declspec(dllexport) AStarDebugToolbar : public QToolBar
{
public:
	public:
	static AStarDebugToolbar& getInstance();
	private:
	static AStarDebugToolbar* theInstance;
	AStarDebugToolbar(){}
	AStarDebugToolbar(const AStarDebugToolbar&);
	AStarDebugToolbar& operator = (const AStarDebugToolbar&);
};