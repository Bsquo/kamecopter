# Kamecopter

This repository contains examples of custom code created for Radio Helicopter (also known as MiniCopter: Adventure Flight or プチコプターWii アドベンチャーフライト) (Wii) using [Kamek](https://github.com/Treeki/Kamek).</br>
Currently, this is meant for the European version of the game.

## Prerequisites
* CodeWarrior Special Edition, see the [Kamek README](https://github.com/Treeki/Kamek) to see how to install it. Once obtained, create a new directory called **`cw`** at the root of the project and place the **.EXE**, **.DLL** and **license.dat** files in there.

* Kamek Linker binary (Kamek.exe and Kamek.dll.config). You can compile this from the Kamek source code in the `Kamek` directory (see the [Kamek README](https://github.com/Treeki/Kamek)). If you don't want to compile it yourself, you can also download the binaries from [Kamek's releases page](https://github.com/Treeki/Kamek/releases).

## symbols_EUR.txt
In each example, you will see a file called **symbols_EUR.txt**. This file contains the RAM addresses of some functions and data from the game, alongside their mangled name.

If calling an original function from the game, we need to add the function mangled name and address to this file. For example, if I want to call ```CApp::GetInstance()```, we have to write ``GetInstance__4CAppFv=0x80011680`` in the file, where **GetInstance__4CAppFv** is the mangled name of the function and **0x80011680** is its address in RAM.

This file must be specified in ``build.dat`` in the Kamek linker options like this: ``-externals=symbols_EUR.txt``

## Building our custom code
Inside each example directory, you will find a file named `build.bat`. Execute it to build the custom code for that example.

The output will normally be either a DOL executable, a Riivolution XML file, a TXT containing a Gecko cheat code, or a Kamek binary module (.bin). See each example for more information.

## Repo structure
	├── cw: This is where the CodeWarrior files have to be placed.
	├── examples
	│   ├── dynamic: Example of custom code meant to be loaded dynamically at runtime from the game's filesystem using a loader
	│   ├── static: Examples of custom code that can be loaded by, for example, injecting it to an original DOL executable.
    ├── include: Contains many header files for data 
    structures in the game. Taken stright from the decomp.
    ├── k_stdlib: Kamek standard library
	├── Kamek: Kamek linker source code. The binary goes in /bin/Debug/