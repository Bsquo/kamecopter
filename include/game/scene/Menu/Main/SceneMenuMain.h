#ifndef SCENE_MENU_MAIN_H
#define SCENE_MENU_MAIN_H

#include "../include/game/scene/VScene.h"

// Debug Menu (Main) scene
class CSceneMenuMain: public CVScene {
	private:
		s32 mOption;
		s32 mMap;
		s32 mMission;

    public:
		CSceneMenuMain();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuMain();
};

#endif // SCENE_MENU_MAIN_H
