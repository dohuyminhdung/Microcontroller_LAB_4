#include "fsm_auto.h"

int automatic = 0;
void trafficSetUp(){
	setBuffer1_Default();
	setTimerCD(1000);
	setFlagSeg(1);
	setBuffer2();
//	state = INIT;
}
void fsm_autoRun(){
	switch(state){
	case INIT:
		if(1){
			automatic = 1;
			state = RED_GREEN;
			CD1 = buffer1[RED];
			CD2 = buffer2[GREEN];
		}
		break;
	case RED_GREEN:
		setTraffic1(0, 1, 1);
		setTraffic2(1, 1, 0);
		if(isTimerFlagCD()){
			--CD1, --CD2;
			setTimerCD(1000);
		}
		if(CD2 <= 0){
			state = RED_AMBER;
			CD2 = buffer2[AMBER];
		}
		break;
	case RED_AMBER:
		setTraffic1(0, 1, 1);
		setTraffic2(1, 0, 1);
		if(isTimerFlagCD()){
			--CD1, --CD2;
			setTimerCD(1000);
		}
		if(CD2 <= 0){
			state = GREEN_RED;
			CD1 = buffer1[GREEN];
			CD2 = buffer2[RED];
		}
		break;
	case GREEN_RED:
		setTraffic1(1, 1, 0);
		setTraffic2(0, 1, 1);
		if(isTimerFlagCD()){
			--CD1, --CD2;
			setTimerCD(1000);
		}
		if(CD1 <= 0){
			state = AMBER_RED;
			CD1 = buffer1[AMBER];
		}
		break;
	case AMBER_RED:
		setTraffic1(1, 0, 1);
		setTraffic2(0, 1, 1);
		if(isTimerFlagCD()){
			--CD1, --CD2;
			setTimerCD(1000);
		}
		if(CD1 <= 0){
			state = RED_GREEN;
			CD1 = buffer1[RED];
			CD2 = buffer2[GREEN];
		}
		break;
	default: break;
	}
	if(automatic == 1){
		if(isButton1_pressed()){
			automatic = 0;
			state = RED_MAN;
			setTraffic1(0, 1, 1);
			setTraffic2(0, 1, 1);
			setTimerCD(BLINK_TIME);

			setTimerSeg(500);
			EN = 0;
		}
	}
	if(automatic == 1 && isTimerFlagSeg()){
		displaySegProcess(CD1, CD2);
		setTimerSeg(LED_CYCLE);
	}
}


