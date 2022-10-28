#ifndef VMATH_H
#define VMATH_H

#include "../include/game/math/VVector.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

namespace CVMath {
    f32 CalcLength(CVVector, CVVector);
    CVVector CalcSurfaceNormal(CVVector, CVVector, CVVector);
    CVVector CalcSurfaceCollPos(CVVector, CVVector, CVVector, CVVector);
    bool CheckPolyInside3D(CVVector, CVVector, CVVector, CVVector);
}

#endif // VMATH_H
