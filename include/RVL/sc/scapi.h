#ifndef SC_API_H
#define SC_API_H

#include "../k_stdlib/kamek.h"
#include "../include/types.h"

#ifdef __cplusplus
extern "C" {
#endif

u8 SCGetSoundMode();
u8 SCGetAspectRatio();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SC_API_H