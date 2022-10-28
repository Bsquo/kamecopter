#ifndef VSOUNDMGR_H
#define VSOUNDMGR_H

#include "../k_stdlib/kamek.h"
#include "../include/types.h"

class CVSoundMgr {
    protected:
        static CVSoundMgr* pInstance;
        CVSoundMgr();
    public:
        static CVSoundMgr* GetInstance();
        void Init();
        void InitArchive(char*);
        void SetOutPutMode(int);
        void Update();
        virtual ~CVSoundMgr();
};

#endif // VSOUNDMGR_H