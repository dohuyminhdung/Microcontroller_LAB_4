#include "sch.h"
sTasks schTasks[SCH_MAX_TASKS];
uint8_t flag = 0;
uint8_t size = 0;
int minus = 0;
ERROR_CODE Error_code = 0;
void sch_Init(void){
	trafficSetUp();
	schAddTask(timerRunCD, 10, 10, isPeriodic);
	schAddTask(timerRunSeg, 10, 10, isPeriodic);
	schAddTask(getKeyInput1, 10, 20, isPeriodic);
	schAddTask(getKeyInput2, 20, 20, isPeriodic);
	schAddTask(getKeyInput3, 30, 20, isPeriodic);
	schAddTask(fsm_autoRun, 30, 30, isPeriodic);
	schAddTask(fsm_manualRun, 50, 30, isPeriodic);
	minus = schTasks[0].delay;
}
void schAddTask( void (*pFunction)(),
				 int delay, int period, uint8_t oneshot){
	if(size >= SCH_MAX_TASKS){
		Error_code = TOO_MANY_TASKS;
		return;
	}
	schTasks[size].pTask = pFunction;
	schTasks[size].delay = delay / TICK;
	schTasks[size].period = period;
	schTasks[size].oneshot = oneshot;
	reheapUp(size);
	size += 1;
}
void schUpdate(void){
	if(schTasks[0].delay > 0){
		--schTasks[0].delay;
	}
	if(schTasks[0].delay <= 0) flag = 1;
}
void schDispatchTask(void){
	if(isTrigger()){
		(*schTasks[0].pTask)();
		if(minus > 0){//minus > 0
			for(uint8_t i = 1; i < size; ++i){
				schTasks[i].delay -= minus;
			}
		}
		reSchProcess();
		while(schTasks[0].delay <= 0){
			(*schTasks[0].pTask)();
			reSchProcess();
		}
		minus = schTasks[0].delay;
	}
}
void schDelete(uint32_t id){
	if(schTasks[id].pTask == 0 || id >= size){
		Error_code = CANNOT_DELETE_TASK;
		return;
	}
	schTasks[id].pTask = 0x0000;
	schTasks[id].delay = 0;
	schTasks[id].period = 0;
	schTasks[id].oneshot = 0;
	if(id != --size){
		schTasks[id] = schTasks[size];
		reheapDown(id);
	}
}

uint8_t reheapUp(uint8_t pos){
	uint8_t p = (pos-1)/2;
	while(pos > 0 && schTasks[pos].delay < schTasks[p].delay){
		sTasks tmp = schTasks[pos];
		schTasks[pos] = schTasks[p];
		schTasks[p] = tmp;
		pos = p;
		p = (pos-1)/2;
	}
	return pos;
}

uint8_t reheapDown(uint8_t idx){
	uint8_t pos = idx;
	while(pos*2+1 < size){
		uint8_t l = pos*2+1;
		uint8_t r = l+1;
		if(l < size && schTasks[l].delay <= schTasks[pos].delay){
			pos = l;
		}
		if(r < size && schTasks[r].delay <= schTasks[pos].delay){
			pos = r;
		}
		if(pos == idx) break;
		//swap
		sTasks tmp = schTasks[idx];
		schTasks[idx] = schTasks[pos];
		schTasks[pos] = tmp;
		idx = pos;
	}
	return idx;
}

void reSchProcess(){
	if(schTasks[0].oneshot == isPeriodic){
		schTasks[0].delay = schTasks[0].period / TICK;
		reheapDown(0);
	}
	else{ // == isOneShot
		schDelete(0);
	}
}

uint8_t isTrigger(){
	if(flag){
		flag = 0;
		return 1;
	}
	return 0;
}























