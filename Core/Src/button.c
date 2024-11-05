#include "button.h"
//int isButton_pressed(int *btn_flag){
//	if(*btn_flag){
//		*btn_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//void getKeyInput(){}
////////////////////////////////////// BUTTON_1 FOR SELECT MODE ///////////////////////////////
int reg0 = NORMAL_STATE;
int reg1 = NORMAL_STATE;
int reg2 = NORMAL_STATE;
int reg3 = NORMAL_STATE;
int timerForPress = 2000;
int btn_flag1 = 0;
int isButton1_pressed(){
	if(btn_flag1 == 1){
		btn_flag1 = 0;
		return 1;
	}
	return 0;
}
void getKeyInput1(){
	reg0 = reg1;
	reg1 = reg2;
	reg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	if(reg0 == reg1 && reg1 == reg2){
		if(reg2 != reg3){
			reg3 = reg2;//for check the condition if user hold button
			if(reg3 == PRESSED_STATE){
				timerForPress = HOLD_DELAY / TICK;
				btn_flag1 = 1;
			}
		}
		else{
			--timerForPress;
			if(timerForPress == 0){
				timerForPress = HOLD_DELAY / TICK;
				if(reg3 == PRESSED_STATE)
					btn_flag1 = 1;
			}
		}
	}
}
////////////////////////////////////// BUTTON_2 FOR MODIFY TIMING ///////////////////////////////
#define TIMER_HOLD 100
int btn2_reg0 = NORMAL_STATE;
int btn2_reg1 = NORMAL_STATE;
int btn2_reg2 = NORMAL_STATE;
int btn2_reg3 = NORMAL_STATE;
int timerForPress2 = 50;
int btn_flag2 = 0;
int isButton2_pressed(){
	if(btn_flag2){
		btn_flag2 = 0;
		return 1;
	}
	return 0;
}
void getKeyInput2(){
	btn2_reg0 = btn2_reg1;
	btn2_reg1 = btn2_reg2;
	btn2_reg2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
	if(btn2_reg0 == btn2_reg1 && btn2_reg1 == btn2_reg2){
		if(btn2_reg2 != btn2_reg3){
			btn2_reg3 = btn2_reg2;
			if(btn2_reg3 == PRESSED_STATE){
				timerForPress2 = HOLD_DELAY / TICK;
				btn_flag2 = 1;
			}
		}
		else{
			--timerForPress2;
			if(timerForPress2 <= 0){
				timerForPress2 = TIMER_HOLD / TICK;
				if(btn2_reg3 == PRESSED_STATE)
					btn_flag2 = 1;
			}
		}
	}
}
////////////////////////////////////// BUTTON_3 FOR SET VALUE //////////////////////////////////
int btn3_reg0 = NORMAL_STATE;
int btn3_reg1 = NORMAL_STATE;
int btn3_reg2 = NORMAL_STATE;
int btn3_reg3 = NORMAL_STATE;
int timerForPress3 = 200;
int btn_flag3 = 0;
int isButton3_pressed(){
	if(btn_flag3){
		btn_flag3 = 0;
		return 1;
	}
	return 0;
}
void getKeyInput3(){
	btn3_reg0 = btn3_reg1;
	btn3_reg1 = btn3_reg2;
	btn3_reg2 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
	if(btn3_reg0 == btn3_reg1 && btn3_reg1 == btn3_reg2){
		if(btn3_reg2 != btn3_reg3){
			btn3_reg3 = btn3_reg2;
			if(btn3_reg3 == PRESSED_STATE){
				timerForPress3 = HOLD_DELAY / TICK;
				btn_flag3 = 1;
			}
		}
		else{
			--timerForPress3;
			if(timerForPress3 <= 0){
				timerForPress3 = HOLD_DELAY / TICK;
				if(btn3_reg3 == PRESSED_STATE)
					btn_flag3 = 1;
			}
		}
	}
}


