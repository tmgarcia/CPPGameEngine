#include <QtGui\qtoolbar.h>

#pragma once
#include "ExportHeader.h"

class DECL_DLL_EXPORT AStarDebugToolbar : public QToolBar
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