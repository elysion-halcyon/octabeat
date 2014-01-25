#include "Timer.h"
#include <amlib.h>
#include "bool.h"


//コンストラクタ
void Timer_ctor(Timer* this){
    this->systemFreq = 199986000;
    this->fps = 60;
}

bool Timer_start(Timer* this, int fps){
    this->fps = fps;
    this->startTime = AG4REG.SYSMNTR;
    this->prevSYSMNTR = this->startTime;
    this->overflow = 0;
    this->count = 0;
    return TRUE;
}

int Timer_run(Timer* this){
    long long int count = AG4REG.SYSMNTR;
    if(count - this->prevSYSMNTR < 0) this->overflow++;
    this->prevSYSMNTR = count;
    count += this->overflow * 4294967296;
    count -= this->startTime;
    count = (count/((float)this->systemFreq/this->fps));

    if(count != this->count){
        unsigned int ret = count - this->count;
        this->count = count;
        return ret;
    }
    return 0;
}