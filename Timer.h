#ifndef _TIMER_H_
#define _TIMER_H_

#include "bool.h"

//Timerクラス(もどき)
typedef struct{
	int    //0 - 4294967295
        fps,        //FPS(分母になるので0になってはいけない)
        count;      //経過フレーム
	long long int
        systemFreq, //システムクロック周波数(200M?)
        startTime,  //開始時刻
        prevSYSMNTR,
        overflow;
} Timer;

void Timer_ctor(Timer* this);
bool Timer_start(Timer* this, int fps);
int Timer_run(Timer* this);
//void Timer_finish(Timer* this);
//print時は"%lld"で指定


#endif