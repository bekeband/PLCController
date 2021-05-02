#ifndef PLCHardware_h
#define PLCHardware_h

#include <stdio.h>
#include <string.h>
#include "PLCTypes.h"

typedef struct {
	u8	value;
}s_counter;

#define INPUTS_BYTES		64
#define INPUTS_BITS			(8 * INPUT_BYTES)
#define OUTPUTS_BYTES		64
#define OUTPUTS_BITS		(8 * OUTPUT_BYTES)

#define MARKERS_BYTES		512
#define MARKERS_BITS		(8 * MARKERS_BYTES)
#define AD_CHANNELS			64
#define DA_CHANNELS			32

#define COUNTERS_NUMBERS	128
#define TIMERS_NUMBERS		128

#define MEMORY_BYTES		2048
#define MEMORY_BITS			(8 * MEMORY_BYTES)
#define RETENT_MEMORY_BYTES	512
#define RETENT_MEMORY_BITS	(8 * RETENT_MEMORY_BYTES)

typedef
struct {
	u8 INPUTS_MIRROR[INPUTS_BYTES];
	u8 OUTPUTS_MIRROR[OUTPUTS_BYTES];
	u8 AD_DATAS_MIRROR[AD_CHANNELS * sizeof(float)];
	u8 DA_DATAS_MIRROR[DA_CHANNELS * sizeof(float)];
	u8 MARKERS_AREA[MARKERS_BYTES];
	u8 PLC_MEMORY[MEMORY_BYTES];
	u8 PLC_RETENT_MEMORY[RETENT_MEMORY_BYTES];
}s_PLCMemory;

typedef s_PLCMemory* p_PLCMemory;

typedef 
struct {
	unsigned char code;
}s_PLCProgram;

typedef s_PLCProgram* p_PLCProgram;

/* Define the PLC memory shift of the PLC memories areas. MAX shift 65535 (unsigned short)*/
#define START				0
#define INPUTS_SHIFT		START
#define OUTPUTS_SHIFT		(START + INPUTS_BYTES)
#define MARKERS_SHIFT		(OUTPUTS_SHIFT + OUTPUTS_BYTES)
#define PLC_MEMORY_SHIFT	(MARKERS_SHIFT + MARKERS_BYTES)
#define PLC_RETENT_MEMORY_SHIFT		(PLC_MEMORY_SHIFT + MEMORY_BYTES)
#define END					(PLC_RETENT_MEMORY_SHIFT + RETENT_MEMORY_BYTES)

#define PLC_PROGRAM_NAME_MAX_LENGTH		22

#define GET_MEMORY_BIT(MEMARRAY, MEMBYTE, BIT) MEMARRAY[MEMBYTE] & (1 << BIT)
#define SET_MEMORY_BIT(MEMARRAY, MEMBYTE, BIT) MEMARRAY[MEMBYTE] |= (1 << BIT)
#define RST_MEMORY_BIT(MEMARRAY, MEMBYTE, BIT) MEMARRAY[MEMBYTE] &= ^(1 << BIT)

#define GET_MEMORY_BYTE(MEMARRAY, MEMBYTE) MEMARRAY[MEMBYTE]
#define SET_MEMORY_BYTE(MEMARRAY, MEMBYTE, DATA) (MEMARRAY[MEMBYTE] = DATA)

#define GET_MEMORY_WORD(MEMARRAY, MEMBYTE) MEMARRAY[MEMBYTE]
#define SET_MEMORY_WORD(MEMARRAY, MEMBYTE, DATA) (MEMARRAY[MEMBYTE] = DATA)

#define NOP_CODE			0
#define LOAD_BYTE			1
#define LOAD_WORD			2
#define LOAD_FLOAT			3

#define PRG_END				100

#define PLC_STACK_SIZE		64

#define PLC_PRG_SIZE		20000

s_PLCMemory PLCMemory;
p_PLCMemory pPLCMemory;

typedef
struct {
	void* address;
	unsigned char type;
}s_PLCCommand;

typedef
struct {
	char name[PLC_PROGRAM_NAME_MAX_LENGTH];
	unsigned int startaddress;
	unsigned int size;
	unsigned int stack_size_req;
}s_PLCProgram_Descriptor;

void PushStack(s_PLCCommand PLCCommand);
s_PLCCommand PopStack();

int runPLCProgram();

#endif