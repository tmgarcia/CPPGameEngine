#ifndef EXPORTHEADER_H
#define EXPORTHEADER_H

#if defined(DECL_DLL_EXPORT_OFF)
#define DECL_DLL_EXPORT
#else
#define DECL_DLL_EXPORT _declspec(dllexport)
#endif

#ifdef	ENGINE_EXPORTS
#define ENGINE_SHARED __declspec( dllexport )
#include "DebugTools\Logger.h"
#else
#define ENGINE_SHARED __declspec( dllimport )
#include "Logger.h"
#endif

//#include "ExportHeader.h"
//
//class DECL_DLL_EXPORT

#endif 