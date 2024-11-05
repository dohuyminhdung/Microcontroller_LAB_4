#include "softwaretimer.h"
//void setFlag(int *timerFlag,int set){
//	*timerFlag = set;
//}
//void setTimer(int *timer,int time){
//	*timer = time / TICK;
//}
//void timerRun(int *timer, int *timerFlag){
//	if(*timer > 0){
//		--(*timer);
//		if(*timer <= 0) *timerFlag = 1;
//	}
//}
//int isTimerFlag(int *timerFlag){
//	if(*timerFlag){
//		*timerFlag = 0;
//		return 1;
//	}
//	return 0;
//}

////////////////////// RED-AMBER-GREEN PROCESS /////////////////////////
int timeCD = 0;
int flagCD = 0;
void setFlagCD(int set){
	flagCD = set;
}
void setTimerCD(int time){
	timeCD = time / TICK;
}
void timerRunCD(){
	if(timeCD > 0){
		--timeCD;
		if(timeCD <= 0) flagCD = 1;
	}
}
int isTimerFlagCD(){
	if(flagCD == 1){
		flagCD = 0;
		return 1;
	}
	return 0;
}
////////////////////// 7 SEGMENT LED PROCESS ///////////////////////////
int timeSeg = 0;
int flagSeg = 0;
void setFlagSeg(int set){
	flagSeg = set;
}
void setTimerSeg(int time){
	timeSeg = time / TICK;
}
void timerRunSeg(){
	if(timeSeg > 0){
		--timeSeg;
		if(timeSeg <= 0) flagSeg = 1;
	}
}
int isTimerFlagSeg(){
	if(flagSeg == 1){
		flagSeg = 0;
		return 1;
	}
	return 0;
}





















