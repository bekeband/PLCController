// PLCController.cpp : Defines the entry point for the application.
//

//#include <stdio.h>

#include "PLCController.h"
#include "PLCHardware.h"
#include "TestOuts.h"


void PrintPLCMemoryAreas() {

	TestPrintf("PLCMemory areas shift address:\n\r");

	TestPrintf("INPUTS = %d , SIZE = %d\n\r", INPUTS_BYTES, sizeof(pPLCMemory->INPUTS_MIRROR));
	TestPrintf("OUTPUTS = %d , SIZE = %d\n\r", OUTPUTS_BYTES, sizeof(pPLCMemory->OUTPUTS_MIRROR));
	TestPrintf("AD_DATAS = %d , SIZE = %d\n\r", AD_CHANNELS, sizeof(pPLCMemory->AD_DATAS_MIRROR));
	TestPrintf("DA_DATAS = %d , SIZE = %d\n\r", DA_CHANNELS, sizeof(pPLCMemory->DA_DATAS_MIRROR));
	TestPrintf("MARKERS = %d , SIZE = %d\n\r", MARKERS_BYTES, sizeof(pPLCMemory->MARKERS_AREA));
	TestPrintf("PLC_MEMORY = %d , SIZE = %d\n\r", MEMORY_BYTES, sizeof(pPLCMemory->PLC_MEMORY));
	TestPrintf("PLC_RETENT_MEMORY = %d , SIZE = %d\n\r", 
		RETENT_MEMORY_BYTES, sizeof(pPLCMemory->PLC_RETENT_MEMORY));
	TestPrintf("PLC_PRG_SIZE = %d byte.\n\r", PLC_PRG_SIZE);
	
}

void PrintPLCMemoryTests() {
	TestPrintf("GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 2); = %d\n\r", 
		GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 2));
}

int main()
{
	TestPrintf("Hello PLCController\n\r");
	TestPrintf("The PLCHardware total memory size is : %d\n\r", sizeof(s_PLCMemory));
	PrintPLCMemoryAreas();
	PLCMemory.INPUTS_MIRROR[10] = 'A';
//	TestPrintf("PLCMEM %d\n\r", PLCMemory.INPUTS_MIRROR[10]);

	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 0));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 1));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 2));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 3));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 4));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 5));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 6));
	TestPrintf("PLCMEM %d\n\r", GET_MEMORY_BIT(PLCMemory.INPUTS_MIRROR, 10, 7));

	return 0;
}
