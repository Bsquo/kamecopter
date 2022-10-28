#include "kamekLoader.h"
#include "../include/game/app/App.h"

void loadIntoMCAF();

struct loaderFunctionsEx {
	loaderFunctions base;
};

// These are the addresses for each of these functions in RAM
const loaderFunctionsEx functions_p = {
	{(OSReport_t) 0x80089974,
	(OSFatal_t) 0x8008B7F8,
	(DVDConvertPathToEntrynum_t) 0x80093EFC,
	(DVDFastOpen_t) 0x80094204,
	(DVDReadPrio_t) 0x800947E4,
	(DVDClose_t) 0x80094518,
	(sprintf_t) 0x800BA164,
	(demo_Alloc_t) 0x8011c148,
	(demo_Free_t) 0x8011c294}
};

void unknownVersion()
{
	// can't do much here!
	// we can't output a message on screen without a valid OSFatal addr
	for (;;);
}

void loadIntoMCAF()
{
	// Get the region letter
	u8 region = *(u8 *)(0x80000003);
    
	// Depending on the region, choose the appropiate functions
	// (so that we use the correct addresses)
	const loaderFunctions *funcs = NULL;
    int *heap = NULL;
	switch (region)
	{
		case 'P': funcs = &functions_p.base; break;
	}

	char path[64];
	
	// Load the dynamic module located in the "/kamek" directory in the game's filesystem.
	funcs->sprintf(path, "/kamek/test_%c.bin", region);
	loadKamekBinaryFromDisc(funcs, path);
    
    return;
}

// Main function modified so that it calls "loadIntoMCAF()" to load the Kamek binary module
// right before the main loop

void mainEX(int argc, char* argv[]) {
    CApp::GetInstance()->Start();
	loadIntoMCAF();
    while(true) {
        CApp::GetInstance()->Loop();
    }
}

// We replace the call to the original main() function (in __start) with out custom main()
kmCall(0x800041a0, mainEX);