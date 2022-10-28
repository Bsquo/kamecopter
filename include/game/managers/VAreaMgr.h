#ifndef VAREA_MGR_H
#define VAREA_MGR_H

#include "../include/game/math/VArea.h"
#include "../include/game/math/VVector.h"
#include "../include/game/utils/VList.h"
#include "../include/types.h"

class CVAreaMgr {
    protected:
        CVAreaMgr();

    public:
		CVArea mArea;
		CVVector mSize;
		CVVector field_0x24;
		s32 coll_div[3];
		CVList field_0x3C;
		CVList field_0x4C;
        UNK8 field_0x5C[0xF9F0];

        static CVAreaMgr* GetInstance();
        virtual ~CVAreaMgr();
};

#endif // VAREA_MGR_H