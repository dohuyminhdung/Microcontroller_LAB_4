#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_
#include "main.h"
#define TICK 10

//void setFlag(int *timerFlag,int set);
//void setTimer(int *timer,int time);
//void timerRun(int *timer, int *timerFlag);
//int isTimerFlag(int *timerFlag);
////////////////////// RED-AMBER-GREEN PROCESS /////////////////////////
void setFlagCD(int set);
void setTimerCD(int time);
void timerRunCD();
int isTimerFlagCD();
////////////////////// 7 SEGMENT LED PROCESS ///////////////////////////

void setFlagSeg(int set);
void setTimerSeg(int time);
void timerRunSeg();
int isTimerFlagSeg();
#endif /* INC_SOFTWARETIMER_H_ */
