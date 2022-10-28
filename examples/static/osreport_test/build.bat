@echo off
SETLOCAL EnableDelayedExpansion

:: Compile CPP
echo "Compiling cpps..."
..\..\..\cw\mwcceppc -I- -i ../../../k_stdlib -Cpp_exceptions off -enum int -RTTI off -once -O4,s -use_lmw_stmw on -fp fmadd -rostr -sdata 0 -sdata2 0 -c -o mcaf.o mcaf.cpp

:: Link
:: Our custom code will be located at RAM address 0x800044C0 (the start of gTRKInterruptVectorTable).
:: We chose this address because it contains enough free space for our code.
:: -input-dol: This is our original, unmodified DOL executable
:: -output-dol: This DOL will contain out custom code
:: -output-riiv: Output XML for use with Riivolution
:: -output-gecko: Output TXT with our custom code turned into a Gecko cheat code
echo Linking...

..\..\..\Kamek\bin\Debug\Kamek mcaf.o -static=0x800044C0 -externals=symbols_EUR.txt -input-dol=pcwii_eur.dol -output-dol=pcwii_eur_kamek.dol -output-riiv=osreport_test.xml -output-gecko=osreport_test.txt

:: Remove .o files after we're done.
del *.o >NUL
ENDLOCAL