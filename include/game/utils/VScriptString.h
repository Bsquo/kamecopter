#ifndef VSCRIPTSTRING_H
#define VSCRIPTSTRING_H

#include "../include/game/utils/VListBase.h"
#include "../include/game/utils/VString.h"
#include <kamek.h>

class CVScriptString: public CVListBase {
    public:
        CVString mString;

        CVScriptString();
        ~CVScriptString();
};

#endif // VSCRIPTSTRING_H
