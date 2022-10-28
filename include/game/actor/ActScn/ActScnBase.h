#ifndef ACT_SCN_BASE_H
#define ACT_SCN_BASE_H

#include "../include/game/actor/VActor.h"
#include "../include/game/utils/VFlag.h"
#include "../include/game/scenary/ScenaryPos.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

class CActScnBase: public CVActor {
    public:
        CScenaryPos* field_0x3B4;
        CScenaryPos* field_0x3B8;
        CVFlag mFlags;
        s32 field_0x3C4;
        u32 field_0x3C8;
        CVVector field_0x3CC;
        UNK32 field_0x3D8;
        UNK32 field_0x3DC;

        CActScnBase();
        virtual ~CActScnBase();
};

#endif // ACT_SCN_BASE_H
