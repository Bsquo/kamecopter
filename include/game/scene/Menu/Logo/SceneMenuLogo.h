#ifndef SCENE_MENU_LOGO_H
#define SCENE_MENU_LOGO_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include "../include/nw4r/lyt/lyt_arcResourceAccessor.h"
#include "../include/nw4r/lyt/lyt_layout.h"
#include <kamek.h>

// Arc System Works logo scene
class CSceneMenuLogo: public CSceneMenuBase {
	public:
        s32 field_0x7C;
        nw4r::lyt::ArcResourceAccessor* pArcResourceAccessor;
        s32 field_0x84;
        nw4r::lyt::Layout* pAllocator;
        nw4r::lyt::Layout* pLayout;
        void* pArchive;
        f32 field_0x94;
        nw4r::lyt::AnimTransform* pAnimTransform;
        s32 field_0x9C;
        s32 field_0xA0;

		CSceneMenuLogo();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuLogo();
};

#endif // SCENE_MENU_LOGO_H
