#include <kamek.h>
#include "../include/game/app/App.h"
#include "../include/game/system/demo.h"
#include "../include/game/managers/ActorMgr.h"
#include "../include/game/managers/VAreaMgr.h"

int callDebugInfoFunctions() {
	// If the "HideInfo" option is disabled (so that the HUD is visible)
	if (CApp::GetInstance()->mFlags.Check(HIDE_INFO) == false) {
		// And the "DebugInfo" option is enabled
		if (CApp::GetInstance()->mFlags.Check(DEBUG_INFO) == true) {
			demo::Report(0x15e, 0x19e, "System (64MB) = %d%% free", demo::GetAvailableHeapRate(demo::MEM1, 0));
			demo::Report(0x15e, 0x1ae, "User   (18MB) = %d%% free", demo::GetAvailableHeapRate(demo::MEM2, 0));
			demo::Report(0x10, 0x1ae, "FPS = %d  COLL = %d : %d", CApp::GetInstance()->mFPS, 
			CVActorMgr::GetInstance()->COLL, CVAreaMgr::GetInstance()->field_0x3C.GetSize());
		}
	}
	return 1;
}

// callDebugInfoFunctions() will be called when CSceneGame::RenderLocal (which renders the gameplay scene)
// is done executing.
// We overwrite the "return 1" from the original function with our call to callDebugInfoFunctions(),
// and return 1 from there instead.
kmCall(0x800194b8, &callDebugInfoFunctions);