#ifndef Assert_H
#define Assert_H
//#include "Logger.h"
#pragma warning ( disable : 4127 )
#if ASSERT_ON
#define Assert(expr,...) do { if(!(expr)) { LOG(Severe,#expr##":"##__VA_ARGS__);END_LOG exit(1); } } while(0)
#else
#define ASSERT(a){}
#endif


#endif