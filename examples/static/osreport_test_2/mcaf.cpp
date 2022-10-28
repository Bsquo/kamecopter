#include "../include/game/scenary/common/ScnRing.h"
#include <kamek.h>

// Moves the contents from the specified register into the variable.
// Thanks to kiwi for this trick!
#define GET_GPR(reg, variable) asm volatile { mr variable, reg; }

void ScoreIncreasePrint() {
	// Move r29 (which contains the pointer to CScenaryRing) to our
	// "scenario" variable
	register CScenaryRing* scenario;
	GET_GPR(r29, scenario);
	
	// Increase score before printing.
	scenario->mCurrentScore++;
	
	// Print
	OSReport("You passed through %d of %d rings!\n", scenario->mCurrentScore, scenario->mMaxScore);
	if (scenario->mCurrentScore == scenario->mMaxScore) {
		OSReport("ALL RINGS PASSED! Thanks for playing! :)\n");
	}
}

// Insert a function call to "ScoreIncreasePrint()" at RAM address 0x80062d5c (PAL)
// This address was chosen because the code around this address is executed only when passing through a ring,
// which means that our function will only run if the helicopter passed through a ring
kmCall(0x80062d5c, &ScoreIncreasePrint);