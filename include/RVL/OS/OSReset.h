#ifndef RVL_OS_H
#define RVL_OS_H

#include <kamek.h>

#ifdef __cplusplus
extern "C" {
#endif

void OSShutdownSystem();
void OSRestart(u32);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // RVL_OS_H