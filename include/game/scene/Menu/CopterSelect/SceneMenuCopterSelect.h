#ifndef SCENE_MENU_COPTERSELECT_H
#define SCENE_MENU_COPTERSELECT_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include "../include/game/scene/Menu/ItemList/MenuItemList.h"
#include "../include/game/save/PossessionItemList.h"
#include <kamek.h>

// Helicopter selection scene
class CSceneMenuCopterSelect: public CSceneMenuBase {
	private:
		CMenuItemList mMenuItemList;
		UNK32 field_0x1678;
		UNK32 field_0x167C;
		UNK32 field_0x1680;
		UNK32 field_0x1684;
		UNK32 field_0x1688;
		UNK32 field_0x168C;
		UNK32 field_0x1690;
		UNK32 field_0x1694;
		CPossessionItemList mItemList;
		UNK8 field_0x1E00[472];

	public:
		CSceneMenuCopterSelect();
		bool StartLocal();
		bool CalcLocal();
		void RenderLocal();
		void CalcLocalPause();
		void RenderLocalPause();
		void EndLocal();
		~CSceneMenuCopterSelect();
};

#endif // SCENE_MENU_COPTERSELECT_H
