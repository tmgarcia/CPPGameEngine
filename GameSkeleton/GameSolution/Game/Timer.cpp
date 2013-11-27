#include "Timer.h"

 double CStopWatch::LIToSecs( LARGE_INTEGER & L) {
     return ((double)L.QuadPart /(double)frequency.QuadPart) ;
 }
 
 CStopWatch::CStopWatch(){
     timer.start.QuadPart=0;
     timer.stop.QuadPart=0; 
     QueryPerformanceFrequency( &frequency ) ;
	 lastInterval.QuadPart = 0;
 }
 
 void CStopWatch::Start( ) {
     QueryPerformanceCounter(&timer.start) ;
	 QueryPerformanceCounter(&lastInterval);
 }
 
 float CStopWatch::Stop( ) {
     QueryPerformanceCounter(&timer.stop);
	 return (float)getElapsedTime();
 }

  float CStopWatch::Interval( ) {
     LARGE_INTEGER currentTime;
     LARGE_INTEGER time;
	 QueryPerformanceCounter(&currentTime);
     time.QuadPart = currentTime.QuadPart -lastInterval.QuadPart;
	 lastInterval.QuadPart=currentTime.QuadPart;
     return (float)LIToSecs(time) ;
  }
 
 double CStopWatch::getElapsedTime() {
     LARGE_INTEGER time;
     time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
	 
     return LIToSecs(time) ;
 }