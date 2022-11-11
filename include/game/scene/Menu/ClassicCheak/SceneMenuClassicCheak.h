#ifndef SCENE_MENU_CLASSIC_CHEAK_H
#define SCENE_MENU_CLASSIC_CHEAK_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include <kamek.h>

// "Disconnected Classic Controller" messaage after Strap scene
class CSceneMenuClassicCheak: public CSceneMenuBase {
	private:
		UNK8 field_0x7C[36];

	public:
		CSceneMenuClassicCheak();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuClassicCheak();
};

#endif // SCENE_MENU_CLASSIC_CHEAK_H
