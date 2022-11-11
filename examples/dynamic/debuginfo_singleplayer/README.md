# Loader

This contains code to load an unused feature to print some debugging information on single player gameplay, if the [debug flag "DebugInfo" is enabled from the game's debug menu](https://tcrf.net/MiniCopter:_Adventure_Flight/Debugging_Functions).

This module will be compiled as a dynamic module, called **test_P.bin** by default. This file can be loaded with the loader dynamically, whenever we want, by calling **loadKamekBinaryFromDisc()** (see line 48 of /examples/dynamic/loader/mcaf.cpp)</br>
Place **test_P.bin** in the */kamek* directory in the root of the disc's filesystem.