#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#include "softwaretimer.h"
#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define HOLD_DELAY 2000
//int isButton_pressed(int *btn_flag);
//void getKeyInput();
////////////////////////////////////// BUTTON_1 FOR SELECT MODE ///////////////////////////////
int isButton1_pressed();
void getKeyInput1();
//void subKeyProcess();
////////////////////////////////////// BUTTON_2 FOR MODIFY TIMING ///////////////////////////////
int isButton2_pressed();
void getKeyInput2();
////////////////////////////////////// BUTTON_3 FOR SET VALUE //////////////////////////////////
int isButton3_pressed();
void getKeyInput3();


#endif /* INC_BUTTON_H_ */
