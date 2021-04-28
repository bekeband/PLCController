#include "PLCHardware.h"

s_PLCMemory PLCMemory;
p_PLCMemory pPLCMemory = &PLCMemory;

s_PLCCommand PLCStack[PLC_STACK_SIZE];
int PLC_STACK_POINTER = 0;

void PushStack(s_PLCCommand PLCCommand) {
	PLCStack[PLC_STACK_POINTER] = PLCCommand;
	if ((PLC_STACK_POINTER++) >= PLC_STACK_SIZE) {
		/*@TODO Must be run to error. */
	};
}

s_PLCCommand PopStack() {
	if ((PLC_STACK_POINTER--) < 0) {
		/*@TODO Must be run to error. */
	};
	return PLCStack[PLC_STACK_POINTER];
}

