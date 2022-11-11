#ifndef VPOSLOG_H
#define VPOSLOG_H

#include "../include/game/math/VVector.h"
#include "../k_stdlib/kamek.h"
#include "../include/<kamek.h>

class CPosLog {
    private:
        CVVector mPrevPos[20];      // Log of the previous position of the helicopter
        CVVector mPrevYaw[20];      // Log of the previous yaw angles of the helicopter
        u32 mCount;

    public:
        CPosLog();
        void Update(CVActor*, int);
        void GetLog(u32, CVVector*, CVVector*);
        void ShiftForward();
        void ShiftBack();
};

#endif // VPOSLOG_H
