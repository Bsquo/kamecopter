#include <kamek.h>

int test()
{
	OSReport("STARTED CSCENEGAME - bool CSceneGame::StartLocal()\n");
	return 0;
}

// This function will be printed after CSceneGame::StartLocal() (the initializing function for the gameplay scene) is finished executing
// We don't put a call here because we're overwriting a "blr" instruction (a call would create a "bl" instruction, instead of just a "b")
// Instead, we return from our custom test() function, so that after it's executed,
// it still returns a number much like how "CSceneGame::StartLocal()" would
kmBranch(0x800158A8, &test);