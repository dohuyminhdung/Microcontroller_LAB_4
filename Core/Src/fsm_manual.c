#include "fsm_manual.h"
void fsm_manualRun(){
	switch(state){
	case RED_MAN:
		if(isTimerFlagCD()){
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
			setTimerCD(BLINK_TIME);
		}
		if(isTimerFlagSeg()){
			setTimerSeg(LED_CYCLE);
			displaySegProcess(RED_TIMER, 2);
		}
		if(isButton1_pressed()){
			state = AMBER_MAN;
			setTraffic1(1, 0, 1);
			setTraffic2(1, 0, 1);
			setTimerCD(BLINK_TIME);
		}
		if(isButton2_pressed()){
			if(++RED_TIMER >= 100) RED_TIMER = 5;
		}
		if(isButton3_pressed()){
			buffer1[RED] = RED_TIMER;
		}
		break;
	case AMBER_MAN:
		if(isTimerFlagCD()){
			HAL_GPIO_TogglePin(AMBER1_GPIO_Port, AMBER1_Pin);
			HAL_GPIO_TogglePin(AMBER2_GPIO_Port, AMBER2_Pin);
			setTimerCD(BLINK_TIME);
		}
		if(isTimerFlagSeg()){
			setTimerSeg(LED_CYCLE);
			displaySegProcess(AMBER_TIMER, 3);
		}
		if(isButton1_pressed()){
			state = GREEN_MAN;
			setTraffic1(1, 1, 0);
			setTraffic2(1, 1, 0);
			setTimerCD(BLINK_TIME);
		}
		if(isButton2_pressed()){
			if(++AMBER_TIMER >= 6) AMBER_TIMER = 1;
		}
		if(isButton3_pressed()){
			buffer1[AMBER] = AMBER_TIMER;
		}
		break;
	case GREEN_MAN:
		if(isTimerFlagCD()){
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
			setTimerCD(BLINK_TIME);
		}
		if(isTimerFlagSeg()){
			setTimerSeg(LED_CYCLE);
			displaySegProcess(GREEN_TIMER, 4);
		}
		if(isButton1_pressed()){
			setBuffer2();
			state = INIT;
		}
		if(isButton2_pressed()){
			if(++GREEN_TIMER >= 94) GREEN_TIMER = 3;
		}
		if(isButton3_pressed()){
			buffer1[GREEN] = GREEN_TIMER;
		}
		break;
	default: break;
	}
}

