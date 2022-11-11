#ifndef SCENE_MENU_HOME_H
#define SCENE_MENU_HOME_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include <kamek.h>

// Unused Home scene
class CSceneMenuHome: public CSceneMenuBase {
	private:
		UNK8 field_0x7C[64];

	public:
		CSceneMenuHome();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuHome();
};

#endif // SCENE_MENU_HOME_H
