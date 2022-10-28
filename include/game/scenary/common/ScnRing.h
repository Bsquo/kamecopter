#ifndef SCENARY_RING_H
#define SCENARY_RING_H

#include "../include/game/scenary/Scenary.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

struct CScenaryRing: public CScenary {
        s32 mMaxScore;
        s32 mCurrentScore;

        CScenaryRing();
        ~CScenaryRing();
        /// ... ///
};

#endif // SCENARY_RING_H
