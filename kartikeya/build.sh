cd sixtrack_lib/SixTrack/SixTrack_4518_cernlib_crlibm_gfortran_O4
gcc -c SixTrackLib.c
gfortran -c  track1.f
gfortran  -m32 -o SixTrack_4518_cernlib_crlibm_gfortran_O4 track1.o SixTrackLib.o sixve.o sixvefox.o dabnews.o lielib.o  -lgraflib -lgrafX11 -lpacklib crlibm/crlibm.a
./SixTrack_4518_cernlib_crlibm_gfortran_O4
python read_fortbin.py
