#ifndef DEMO_H
#define DEMO_H

#include "../include/RVL/GX/GXFrameBuf.h"

namespace demo {
    enum Memory {
		MEM1,		// System
		MEM2		// User
	};
    
	void* Alloc(size_t size, int align, demo::Memory heap);
    void Free(void*);
    void BeforeRender();
    void DoneRender(unsigned long, int, int);
    void Report(int, int, const char*, ...);
    void InitDemoLib(const _GXRenderModeObj*);
	unsigned int GetAvailableHeapRate(int, unsigned long*);
}

#endif // DEMO_H
