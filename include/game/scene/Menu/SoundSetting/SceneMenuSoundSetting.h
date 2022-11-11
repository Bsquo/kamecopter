#ifndef SCENE_MENU_SOUND_SETTING_H
#define SCENE_MENU_SOUND_SETTING_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include "../include/game/PCopter_constants.h"
#include <kamek.h>

// Sound settings scene
class CSceneMenuSoundSetting: public CSceneMenuBase {
	private:
		UNK8 field_0x7C[160];
		SoundOutPutMode mSoundOutPutMode;
		UNK32 field_0x120;

	public:
		CSceneMenuSoundSetting();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuSoundSetting();
};

#endif // SCENE_MENU_SOUND_SETTING_H
