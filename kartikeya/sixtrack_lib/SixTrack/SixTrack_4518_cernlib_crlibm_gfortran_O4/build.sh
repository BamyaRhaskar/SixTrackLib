gcc -c trackAPI.c
gfortran -c  track.f
gfortran  -m32 -o SixTrack_4518_cernlib_crlibm_gfortran_O4 track.o sixve.o sixvefox.o dabnews.o lielib.o trackAPI.o -lgraflib -lgrafX11 -lpacklib crlibm/crlibm.a
./SixTrack_4518_cernlib_crlibm_gfortran_O4
python read_fortbin.py

