#include <kamek.h>
#include "../include/game/system/demo.h"

struct DVDHandle
{
	u32 _unk[12];
	u32 address, length;
	u32 _unk38;
};

struct loaderFunctions;

// These functions will be used to do things like load dynamic modules from the disc.
// See "loadKamekBinary" in "kamekLoader.cpp"
typedef void (*OSReport_t) (const char *str, ...);
typedef void (*OSFatal_t) (u32 *fg, u32 *bg, const char *str, ...);
typedef int (*DVDConvertPathToEntrynum_t) (const char *path);
typedef bool (*DVDFastOpen_t) (int entrynum, DVDHandle *handle);
typedef int (*DVDReadPrio_t) (DVDHandle *handle, void *buffer, int length, int offset, int unk);
typedef bool (*DVDClose_t) (DVDHandle *handle);
typedef int (*sprintf_t) (char *str, const char *format, ...);

// Typedef for demo::Alloc(unsigned long alignment, int, demo::Memory heap)
// and demo::Free(void* ptr)

// These two functions handle allocation and deallocation in the game's code.
// We will be using these in "kamekLoader.cpp" to do things like load dynamic modules into memory
// (see line 159 of "kamekLoader.cpp")

// demo::Memory specifies in what heap we want to allocate our content in.
// It can be either demo::MEM1 or demo::MEM2
typedef void* (*demo_Alloc_t) (size_t size, int align, demo::Memory heap);
typedef void (*demo_Free_t) (void *ptr);


struct loaderFunctions {
	OSReport_t OSReport;
	OSFatal_t OSFatal;
	DVDConvertPathToEntrynum_t DVDConvertPathToEntrynum;
	DVDFastOpen_t DVDFastOpen;
	DVDReadPrio_t DVDReadPrio;
	DVDClose_t DVDClose;
	sprintf_t sprintf;
	demo_Alloc_t kamekAlloc;
	demo_Free_t kamekFree;
};

void loadKamekBinaryFromDisc(const loaderFunctions *funcs, const char *path);

