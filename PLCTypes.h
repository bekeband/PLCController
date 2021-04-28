#ifndef PLCTypes_h
#define PLCTypes_h

#ifndef NULL
#define NULL (void*)0
#endif //NULL

#define TYPE_UBOOL 0
#define TYPE_UENUM 1
#define TYPE_U8 2
#define TYPE_S8 3
#define TYPE_U16 4
#define TYPE_S16 5
#define TYPE_U32 6
#define TYPE_S32 7
#define TYPE_F16 8
#define TYPE_F32 9
#define TYPE_UDATE 10
#define TYPE_CHAR24 11

typedef unsigned char ubool;
typedef unsigned char uenum;
typedef unsigned char u8;
typedef unsigned char s8;
typedef	unsigned short u16;
typedef signed short s16;
typedef	unsigned long u32;
typedef signed long s32;
typedef	signed short f16;
typedef signed long f32;
typedef unsigned long udate;
typedef struct _char24
{
    char value[24];
} char24;

typedef	char* string;

typedef union _union32 {
    u32 val32;

    struct {
        u16 ls16;
        u16 ms16;
    } val16;

    u8 val8[4];
} union32;


#endif