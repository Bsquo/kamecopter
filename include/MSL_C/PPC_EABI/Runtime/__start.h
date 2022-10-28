// Credits to the Xenoblade and Melee decomps
// https://github.com/CelestialAmber/xenoblade/blob/main/include/MSL_C/PPC_EABI/Runtime/__start.h
// https://github.com/doldecomp/melee/blob/master/src/dolphin/os/init/__start.h

#include "../include/RVL/db/db.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

#define PAD3_BUTTON_ADDR        0x800030E4
#define OS_RESET_RESTART        0
#define FALSE                   0
#define TRUE                    1
#define EXCEPTIONMASK_ADDR      0x80000044
#define BOOTINFO2_ADDR          0x800000F4
#define OS_BI2_DEBUGFLAG_OFFSET 0xC
#define ARENAHI_ADDR            0x80000034
#define DEBUGFLAG_ADDR          0x800030E8
#define DVD_DEVICECODE_ADDR     0x800030E6
#define MEM1ARENA_END_ADDR      0x80003110

extern void InitMetroTRK();

u16 Pad3Button: PAD3_BUTTON_ADDR;
static u8 Debug_BBA = 0;

extern void memset(void*, int, int);
extern int main(int argc, char* argv[]);
extern void exit(int);
extern void __init_user();
extern void InitMetroTRK_BBA();
extern void OSInit();
extern void OSResetSystem(BOOL reset, u32 resetCode, BOOL forceMenu);
extern void __init_hardware();

__declspec(section ".init") extern void __check_pad3();
__declspec(section ".init") extern void __set_debug_bba();
__declspec(section ".init") extern u8 __get_debug_bba();
__declspec(section ".init") extern void __start();
__declspec(section ".init") extern void __init_registers();
__declspec(section ".init") extern void __init_data();

__declspec(section ".init") extern char _stack_addr[];
__declspec(section ".init") extern char _SDA_BASE_[];
__declspec(section ".init") extern char _SDA2_BASE_[];

typedef struct __rom_copy_info {
	char* rom;
	char* addr;
	unsigned int size;
} __rom_copy_info;

__declspec(section ".init") extern __rom_copy_info _rom_copy_info[];

typedef struct __bss_init_info {
	char* addr;
	unsigned int size;
} __bss_init_info;

__declspec(section ".init") extern __bss_init_info _bss_init_info[];
