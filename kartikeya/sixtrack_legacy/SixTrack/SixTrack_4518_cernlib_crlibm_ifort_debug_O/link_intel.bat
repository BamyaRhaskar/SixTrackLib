call "C:\Program Files\Intel\ComposerXE-2011\bin\compilervars.bat" ia32 VS2005

ifort /MT /exe:SixTrack_4518_cernlib_crlibm_ifort_debug_O ^
 sixve.obj sixvefox.obj track.obj dabnews.obj lielib.obj myboinc.obj ^
 ericc.o atan.o atan_fast.o exp.o logsix.o exp_fast.o ^
 log_fast.o addition_scs.o multiplication_scs.o zero_scs.o ^
 double2scs.o scs2double.o division_scs.o sine.o cosine.o ^
 tan.o trigo_fast.o rem_pio2.o log10.o csh_fast.o ^
 disable_xp.o enable_xp.o dtoa_c.o dtoaf.o round_near.o ^
 C:\boinc_280813\win_build\Build\win32\Release\libboincapi_staticcrt.lib ^
 C:\boinc_280813\win_build\Build\win32\Release\libboinc_staticcrt.lib ^
 C:\boinc_260813\zip\boinc_zip.lib ^
 "C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\Lib\User32.lib" ^
 "C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\Lib\AdvAPI32.Lib" ^
 /link /VERBOSE:LIB
