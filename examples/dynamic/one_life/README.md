# One Life Mod

This contains the source code of the "One Life" mod. A preview of the mod + download can be found [here](https://www.youtube.com/watch?v=ojmsJceJLgo).

Your helicopter will only have one life, and getting hit will immediatly restart the mission. This was done to mimic the old games in the Petit Copter series, where getting hit once would break the helicopter and force you to restart from the beginning.

If the string `one_life    1` is present under the `Scenary` category in a mission's script file (found in /PCopter/Scenary/MAP_NAME/Mission_X.txt), then this mode will be enabled. An example is shown below, for the second mission of the Kids Room map (/PCopter/Scenary/KidsRoom/Mission_2.txt):

```
[Scenary]
{
	:type		"KidsRoom02"
	
	:border_time	120

	:max_point	4000
	:rank_border	5000,8000,11000

	:one_life	1       // Enable mod
}
```

This module will be compiled as a dynamic module, called **test_P.bin** by default. This file can be loaded with the loader dynamically, whenever we want, by calling **loadKamekBinaryFromDisc()** (see line 48 of /examples/dynamic/loader/mcaf.cpp)</br>
Place **test_P.bin** in the */kamek* directory in the root of the disc's filesystem.