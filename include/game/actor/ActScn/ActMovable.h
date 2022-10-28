#ifndef ACT_MOVABLE_H
#define ACT_MOVABLE_H

#include "../include/game/actor/ActScn/ActScnBase.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

class CActMovable: public CActScnBase {
    public:
        CVActor* field_0x3E0;
        f32 mHeight;

        CActMovable();
        virtual ~CActMovable();
};

#endif // ACT_MOVABLE_H
