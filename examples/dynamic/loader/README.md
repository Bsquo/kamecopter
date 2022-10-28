# Loader

This contains code for the loader. The loader is a small piece of code that is "injected" into the DOL whose purpose is to load dynamic Kamek binary modules (basically, our custom code) from the game's filesystem.

An example of a dynamic module is located in /examples/dynamic/debuginfo_singleplayer.

In this example, the module from `debuginfo_singleplayer` (called **test_P.bin** by default) will be loaded from the main function, before the game enters the main loop.</br>
To do so, we created a custom main function that calls **loadintoMCAF()**, which calls **loadKamekBinaryFromDisc()** to load *test_P.bin* from the */kamek* directory inside the game's filesystem.