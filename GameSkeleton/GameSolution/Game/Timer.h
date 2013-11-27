#pragma once
 #include <windows.h>


typedef struct {
     LARGE_INTEGER start;
     LARGE_INTEGER stop;
 } stopWatch;
 
 class CStopWatch {
	 private:
		 stopWatch timer;
		 LARGE_INTEGER frequency;
		 double LIToSecs( LARGE_INTEGER & L) ;
		 LARGE_INTEGER lastInterval;
	 public:
		 CStopWatch() ;
		 void Start( ) ;
		 float Stop( ) ;
		 float Interval( ) ;
		 double getElapsedTime() ;
 };