#ifndef SCENE_MENU_MULTI_MODE_SELECT_H
#define SCENE_MENU_MULTI_MODE_SELECT_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include <kamek.h>

// Multiplayer map selection scene
class CSceneMenuMultiModeSelect: public CSceneMenuBase {
	private:
		UNK8 field_0x7C[168];

	public:
		CSceneMenuMultiModeSelect();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuMultiModeSelect();
};

#endif // SCENE_MENU_MULTI_MODE_SELECT_H
