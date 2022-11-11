#ifndef SCENE_MENU_MOVIE_H
#define SCENE_MENU_MOVIE_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include <kamek.h>

enum eMovie {
	OPENING,
	ENDING,
	SONIC_POWERED,
	LOGO2			// Unused. https://tcrf.net/MiniCopter:_Adventure_Flight#Unused_Intro_Video
};

// Video play scene
class CSceneMenuMovie: public CSceneMenuBase {
	private:
		eMovie mMovie;
		UNK8 field_0x80[92];

	public:
		CSceneMenuMovie();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuMovie();
};

#endif // SCENE_MENU_MOVIE_H
