#ifndef SCENE_MENU_MISSIONSELECT_H
#define SCENE_MENU_MISSIONSELECT_H

#include "../include/game/scene/Menu/SceneMenuBase.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

// Not to be confused with the "eRoom" enum. This one uses different identifiers for each map.
enum eArea {
	AREA_KIDS_ROOM,
	AREA_HOTEL,
	AREA_HOSPITAL,
	AREA_COMPANY,
	AREA_BGSHOP,
	AREA_JAPAN
};

// Not to be confused with the "eScenary" enum. This one uses different identifiers for each mission displayed in the menu.
enum eMission {
	OPTION_MISSION_1,
	OPTION_MISSION_2,
	OPTION_MISSION_3,
	OPTION_MISSION_4,
	OPTION_MISSION_5,
	OPTION_TREASURE,
	OPTION_FREEFLIGHT = 0xFF		// Unused
};

// Mission selection scene
class CSceneMenuMissionSelect: public CSceneMenuBase {
	private:
		UNK32 field_0x00;
		UNK32 field_0x04;
		eArea mArea;
		UNK8 field_0x88[248];
		eMission mMission;
		UNK8 field_0x184[108];

	public:
		CSceneMenuMissionSelect();
		virtual bool StartLocal();
		virtual bool CalcLocal();
		virtual void RenderLocal();
		virtual void CalcLocalPause();
		virtual void RenderLocalPause();
		virtual void EndLocal();
		virtual ~CSceneMenuMissionSelect();
};

#endif // SCENE_MENU_MISSIONSELECT_H
