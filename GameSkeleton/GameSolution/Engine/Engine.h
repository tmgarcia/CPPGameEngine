#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "ExportHeader.h"
//#include "Core.h"



namespace Engine
{
	ENGINE_SHARED void Log( Severity severity, const char* message, const char * logFile, int logLine);
	ENGINE_SHARED void shutDown();
	// your stuff goes here...
	// use ENGINE_SHARED to indicate a function or class that you want to export
	ENGINE_SHARED void Init();
	
}

#endif // _ENGINE_H_