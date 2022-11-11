#ifndef NW4R_UT_COLOR_H
#define NW4R_UT_COLOR_H

#include <kamek.h>

namespace nw4r {
    namespace ut {
        struct Color {
            u32 color;
            
            Color(u32);
            const nw4r::ut::Color& operator=(u32);
            u32& ToU32ref();
            ~Color();
        };
    }
}

#endif // NW4R_UT_COLOR_H
