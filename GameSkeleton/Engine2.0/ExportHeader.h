#ifndef EXPORTHEADER_H
#define EXPORTHEADER_H
#ifdef	ENGINE_EXPORTS
#define ENGINE_SHARED __declspec( dllexport )
#include "DebugTools\Logger.h"
#else
#define ENGINE_SHARED __declspec( dllimport )
#include "Logger.h"
#endif

#endif // EXPORTHEADER_H