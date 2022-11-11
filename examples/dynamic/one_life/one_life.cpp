#include <kamek.h>
#include "../include/game/app/App.h"
#include "../include/game/managers/VLayoutMgr.h"
#include "../include/game/utils/VScript.h"
#include "../include/game/managers/ScenaryMgr.h"

static u32 isModeEnable = false;

// When we restart the mission, we use this variable to determine
// whether we should play the countdown.

// If we get hit, we restart, but don't play the countdown.
// We only play the countdown when entering the mission for the first time
// or when pressing "Retry" on the pause menu.
static bool copterWasHit = false;

static CSceneGame* sceneGame = CApp::GetInstance()->GetSceneGame();

// ============= Parse the Mission_X.txt file to see if we should enable the one life mode =============
// This mode will activate if the "[Scenary]" group on the said TXT file has the following entry:
// one_life = 1


u32 enableModeFromScript() {
	isModeEnable = CScenaryMgr::GetInstance()->mScript.GetParam("Scenary/one_life", 0);
	return 0;
}
kmCall(0x800456b0, enableModeFromScript);
kmCall(0x800456e8, enableModeFromScript);

// ============= Init helicopter's life to 1 =============
void setCopterLifeToOne() {
	if (isModeEnable) {
		sceneGame->pHelicopter->life = 1;				// Current life
		sceneGame->pHelicopter->durability = 1;			// Max life capacity
	}
	
	asm volatile			// We make it "volatile" to prevent the compiler from optimizing out the instruction.
	{
		// Original instruction.
		// Because we're replacing this instruction with our function call,
		// we put the original instruction here at the end so that we don't really lose it,
		// to prevent unintended behaviour.
		or r3, r28, r28
	}
}
kmCall(0x8004773c, &setCopterLifeToOne);


// ============= Make the life graphic invisible. =============
// We do this by setting setting the second argument of "CVLayoutMgr::SetVisible" to false (0)
void makeLifeGraphicInvisible(register CVLayoutMgr* layoutMgr, register char* effectName, register int shouldEnableGraphic) {
	if (isModeEnable) {
		layoutMgr->SetVisible(effectName, false);
	}
	else {
		// Original logic
		layoutMgr->SetVisible(effectName, shouldEnableGraphic);
	}
}
kmCall(0x8001667c, &makeLifeGraphicInvisible);
kmCall(0x80016b60, &makeLifeGraphicInvisible);



// ============= Set "copterWasHit" to false if restarting or leaving the mission =============
void setRestartMissionState() {
	if (isModeEnable) {
		copterWasHit = false;
		sceneGame->SetState(RESTART_MISSION);
	}
	else {
		// Original logic
		sceneGame->SetState(RESTART_MISSION);
	}
}
kmCall(0x80018ff8, &setRestartMissionState);

void seExitMissionState() {
	if (isModeEnable) {
		copterWasHit = false;
		sceneGame->SetState(EXIT_MISSION);
		isModeEnable = false;
	}
	else {
		// Original logic
		sceneGame->SetState(EXIT_MISSION);
	}
}
kmCall(0x80018e88, &seExitMissionState);


// ============= Set "copterWasHit" to true after being hit =============
void setCopterHitState() {
	if (isModeEnable) {
		copterWasHit = true;
		sceneGame->SetState(RESTART_MISSION);	// Don't display the "mission failed" sequence. Restart the mission instead.
	}
	else {
		// Original logic
		sceneGame->SetState(MISSION_FAILED);
	}
}
kmCall(0x80015e54, &setCopterHitState);


// ============= When restarting after getting the helicopter was hit, don't fade in/out =============
// ============= Only fade in/out when restarting the mission =============
void shouldFade() {
	CVLayoutMgr* layoutMgr = CVLayoutMgr::GetInstance();
	
	if (isModeEnable) {
		if (copterWasHit == true) {
			sceneGame->Restart();
			sceneGame->SetState(START_COUNTDOWN);
			return;
		}
	}
	
	// Original logic, executed when copterWasHit == false (i.e. mission has been restarted by the player)
	if (sceneGame->mTimeInCurrentGameplayState < 30) {
		layoutMgr->SetState("FadeWindow", true);
	}
	else if (sceneGame->mTimeInCurrentGameplayState == 30) {
		sceneGame->Restart();
	}
	else if (sceneGame->mTimeInCurrentGameplayState < 60) {
		layoutMgr->SetState("FadeWindow", false);
	}
	else {
		sceneGame->SetState(START_COUNTDOWN);
	}
}
kmCall(0x80018cbc, &shouldFade);
// After running this function, break from the switch statement that previously lead us here
kmWrite32(0x80018cc0, 0x480000ac);


// ============= Determine whether we should play the countdown or not =============
u32 shouldPlayCountdown() {
	if (isModeEnable) {
		if (copterWasHit == true) {
			// Skip the countdown and start the mission
			// The game will leave the countdown state and start the mission
			// if it sees that we've been in the "countdown" state for 243 frames or greater.
			sceneGame->mTimeInCurrentGameplayState = 243;
		}
		copterWasHit = false;
	}
	// The original instruction we're replacing places mTimeInCurrentGameplayState on r3.
	// We return this value so that it gets put on r3 after returning.
	return sceneGame->mTimeInCurrentGameplayState;
}
kmCall(0x80016dd8, &shouldPlayCountdown);