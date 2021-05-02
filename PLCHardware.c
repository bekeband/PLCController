#include "PLCHardware.h"

s_PLCCommand PLCStack[PLC_STACK_SIZE];
int PLC_STACK_POINTER = 0;

s_PLCProgram PLCProgram[PLC_PRG_SIZE];
int PLC_PRG_POINTER = 0;

s_PLCMemory PLCMemory;
p_PLCMemory pPLCMemory = &PLCMemory;

p_PLCProgram pPLCProgram = &PLCProgram;

int isStartProgram;

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

void clearPLCMemory(int isRetentArea) {
	if (isRetentArea) {
		memset(pPLCMemory, 0, sizeof(s_PLCMemory));
	}
	else {
		memset(pPLCMemory, 0, sizeof(s_PLCMemory) - RETENT_MEMORY_BYTES);
	}
}

void clearPLCProgramMemory(int isFunctions) {
	PLC_PRG_POINTER = 0;
	memset(pPLCProgram, NOP_CODE, sizeof(PLCProgram));
}

int loadPLCProgram() {
	PLC_PRG_POINTER = 0;
	return 0;
}

int getInputs() {

}

int setOutputs() {

}

int processNextCommand() {
	return 0;
}

int runPLCProgram() {
	int isRunResult = 1;
	while((isStartProgram) && (isRunResult))
	{
		isRunResult = processNextCommand();
	}

	return 0;
}
