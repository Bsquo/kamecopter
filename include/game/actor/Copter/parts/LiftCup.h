#ifndef LIFT_CUP_H
#define LIFT_CUP_H

#include "../k_stdlib/kamek.h"
#include "../include/game/utils/VFilePath.h"
#include "../include/game/actor/ActScn/ActMovable.h"
#include "../include/game/gfx/VModel.h"
#include "../include/types.h"

class CLiftCup {
    public:
        s32 mIsActive;                      // Sets whether or not the suction cup should be able to lift up objects
        CVActor* pHelicopter;               // Helicopter attached to the suction cup
        CVModel* pModel;                    // Suction cup model
        CActMovable* pActor;                // Actor being lifted by suction cup
        CVVector mActorPos;                 // Position of actor being lifted
        f32 lift_dist;                      // 吸着距離(m) (Distance between suction cup and actor in meters)
        u32 mStrongDropBlinkingTime;        // Time in frames of the actor blinking when it's dropped to the floor strongly

        CLiftCup();
        bool Init(CVFilePath, CVActor*);
        void Calc();
        CVActor* SearchActor(int);
        UNK32 LiftActor(CVActor*);
        UNK32 PutActor(CVVector, CVVector, int);
        void ForcePut();
};

#endif // LIFT_CUP_H
