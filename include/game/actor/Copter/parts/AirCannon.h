#ifndef AIR_CANNON_H
#define AIR_CANNON_H

#include "../k_stdlib/kamek.h"
#include "../include/game/actor/VActor.h"
#include "../include/game/gfx/VModel.h"
#include "../include/game/math/VVector.h"
#include "../include/game/utils/VList.h"
#include "../include/types.h"

class CAirCannon {
    public:
        u32 mParamFileLoaded;       // 1 if the "Param.txt" file associated with the Air Cannon was loaded correctly
        CVActor* pActor;            // Actor the cannon is attached too. In the final game, only the helicopter is ever attached to the cannon
        CVModel* pModel;
        CVVector mCannonPos;        // Cannon position relative to the actor it's attached to
        CVList mBulletGroup;        // A group of up to 3 air bullets (CAirBullet)
        u32 life;                   // Real symbol
        u32 limit_num;              // Real symbol 
        u32 speed;                  // Real symbol
        u32 power;                  // Real symbol
};

#endif // AIR_CANNON_H
