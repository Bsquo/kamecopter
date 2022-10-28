@echo off
SETLOCAL EnableDelayedExpansion

:: Compile CPP
:: We have to compile both the kamek loader code (kamekLoader.cpp) and our custom code to load out dynamic modules (mcaf.cpp)
echo "Compiling cpps..."

..\..\..\cw\mwcceppc -i . -I- -i ../../../k_stdlib -Cpp_exceptions off -enum int -RTTI off -once -O4,s -use_lmw_stmw on -fp fmadd -rostr -sdata 0 -sdata2 0 -c -o kamekLoader.o kamekLoader.cpp
..\..\..\cw\mwcceppc -i . -I- -i ../../../k_stdlib -Cpp_exceptions off -enum int -RTTI off -once -O4,s -use_lmw_stmw on -fp fmadd -rostr -sdata 0 -sdata2 0 -c -o mcaf.o mcaf.cpp

:: Link
:: Our custom code will be located at RAM address 0x800044C0 (the start of gTRKInterruptVectorTable).
:: We chose this address because it contains enough free space for our code.
:: -input-dol: This is our original, unmodified DOL executable
:: -output-dol: This DOL will contain out custom code
echo Linking...

..\..\..\Kamek\bin\Debug\Kamek kamekLoader.o mcaf.o -static=0x800044c0 -externals=symbols_EUR.txt  -input-dol=pcwii_eur.dol -output-dol=pcwii_eur_kamek.dol
del *.o >NUL
ENDLOCAL