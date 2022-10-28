#ifndef VANGLE_H
#define VANGLE_H

#include "../include/game/math/VAxis.h"
#include "../include/game/math/VMatrix.h"
#include "../k_stdlib/kamek.h"
#include "../include/types.h"

class CVAxis;     // Forward declaration

class CVAngle {
    private:
        f32 x, y, z;

    public:
        CVAngle();
        CVAngle(f32, f32, f32);
        void operator=(const CVAngle&);
        operator CVAxis() const;
};

#endif // VANGLE_H
