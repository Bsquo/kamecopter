#ifndef VTIMERMGR_H
#define VTIMERMGR_H

#include "../include/game/utils/VList.h"
#include "../include/game/utils/VTimer.h"
#include <kamek.h>

class CVTimerMgr {
    protected:
        CVTimerMgr();

    public:
        CVList mTimerGroup;

        static CVTimerMgr* GetInstance();
        virtual ~CVTimerMgr();
        void Release();
        CVTimer& AddTimer(u32, u32);
        CVTimer& GetTimer(u32);
        u32 GetTime(u32);
        void DeleteTimer(u32);
        void Update();
};

#endif // VTIMERMGR_H