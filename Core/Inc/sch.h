#ifndef INC_SCH_H_
#define INC_SCH_H_

#include "main.h"
#include<stdint.h>
#include "fsm_auto.h"
#include "fsm_manual.h"
#define isOneShot 0
#define isPeriodic 1
typedef enum{
	NO_TASK_ID,
	CANNOT_DELETE_TASK,
	OUT_OF_RANGE, //schShiftTask ERROR
	TOO_MANY_TASKS,
	WAITING_FOR_SLAVE_TO_ACK,
	WAITING_FOR_START_COMMAND_FROM_MASTER,
	ONE_OR_MORE_SLAVES_DID_NOT_START,
	LOST_SLAVE,
	CAN_BUS_ERROR,
	I2C_WRITE_BYTE_AT24C64
} ERROR_CODE;
typedef struct{
	uint8_t oneshot; //oneshot task or not
	int delay; //Delay (ticks) until the function will (next) be run
	int period; //Interval (ticks) between subsequent runs
	void(*pTask)(void); // Pointer to the task (must be a ’ void ( void ) ’ function )
}sTasks;
#define SCH_MAX_TASKS 40
void sch_Init(void);
void schAddTask( void (*pFunction)(),
				 int delay, int period, uint8_t oneshot);
void schUpdate(void);
void schDispatchTask(void);
void schDelete(uint32_t id);

uint8_t reheapUp(uint8_t pos);
uint8_t reheapDown(uint8_t idx);
uint8_t isTrigger();
void reSchProcess();

#endif /* INC_SCH_H_ */
