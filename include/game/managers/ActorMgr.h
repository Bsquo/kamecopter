#ifndef VACTOR_MGR_H
#define VACTOR_MGR_H

#include "../include/game/utils/VList.h"
#include "../include/game/actor/VActor.h"
#include "../include/game/utils/VFilePath.h"
#include <kamek.h>

class CVActorMgr {
    protected:
        CVActorMgr();

    public:
        CVList mActorGroup;
        s32 COLL;               // The "COLL" parameter seen when the debug info display is enabled in multiplayer.
        UNK32 field_0x14;

        static CVActorMgr* GetInstance();
        virtual ~CVActorMgr();
        void Release();
        void AddActor(CVActor*, CVFilePath, int);
        u32 GetActorNum(int);
        s32 GetActorIndex(CVActor*, int);
        const CVActor& GetActor(int, int);
        const CVActor& GetStart(int);
        const CVActor& GetNext(CVActor*, int);
        void Move();
        void UpdateCollVtx(int);
        void UpdateArea();
};

#endif // VACTOR_MGR_H