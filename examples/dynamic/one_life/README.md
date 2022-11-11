# One Life Mod

This contains the source code of the "One Life" mod.

If the string `one_life    1` is present under the `Scenary` category in a mission's script file (found in /PCopter/Scenary/MAP_NAME/Mission_X.txt), then this mode will be enabled.

Your helicopter will only have one life, and getting hit will immediatly restart the mission. This was done to mimic the old games in the Petit Copter series, where getting hit once would break the helicopter and force you to restart from the beginning.

This module will be compiled as a dynamic module, called **test_P.bin** by default. This file can be loaded with the loader dynamically, whenever we want, by calling **loadKamekBinaryFromDisc()** (see line 48 of /examples/dynamic/loader/mcaf.cpp)</br>
Place **test_P.bin** in the */kamek* directory in the root of the disc's filesystem.