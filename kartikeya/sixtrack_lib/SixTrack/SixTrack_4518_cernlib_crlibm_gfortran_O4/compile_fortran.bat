call "C:\Program Files\Intel\ComposerXE-2011\bin\compilervars.bat" ia32 VS2005
ifort /c /arch:IA32 /fp:source /fp:strict /fp:except- /MT /names:lowercase /assume:underscore sixve.f
ifort /c /arch:IA32 /fp:source /fp:strict /fp:except- /MT /names:lowercase /assume:underscore sixvefox.f
ifort /c /arch:IA32 /fp:source /fp:strict /fp:except- /MT /names:lowercase /assume:underscore track.f
ifort /c /arch:IA32 /fp:source /fp:strict /fp:except- /MT /names:lowercase /assume:underscore dabnews.f
ifort /c /arch:IA32 /fp:source /fp:strict /fp:except- /MT /names:lowercase /assume:underscore lielib.f
ifort /c /arch:IA32 /fp:source /fp:strict /fp:except- /MT /names:lowercase /assume:underscore myboinc.f
