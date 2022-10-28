@echo off
SETLOCAL EnableDelayedExpansion

:: Compile CPP
echo "Compiling cpps..."
..\..\..\cw\mwcceppc -I- -i ../../../k_stdlib -Cpp_exceptions off -enum int -RTTI off -once -O4,s -use_lmw_stmw on -fp fmadd -rostr -sdata 0 -sdata2 0 -c -o debuginfo_singleplayer.o debuginfo_singleplayer.cpp

:: Link
:: Because our custom code in debuginfo_singleplayer.cpp will be loaded dynamically by the loader 
:: we specify the "-dynamic" option
:: Don't forget to specify a name for the module by using the "-output-kamek" option!
:: In our case, the name will be "test_P.bin" (see line 50 of /examples/dynamic/loader/mcaf.cpp)

:: This should output a valid Kamek binary module. If you open it in an hex editor,
:: it should have the string "Kamek" at the beginning of the file.
echo Linking...

..\..\..\Kamek\bin\Debug\Kamek debuginfo_singleplayer.o -dynamic -externals=symbols_EUR.txt -output-kamek=test_P.bin
del *.o >NUL
ENDLOCAL