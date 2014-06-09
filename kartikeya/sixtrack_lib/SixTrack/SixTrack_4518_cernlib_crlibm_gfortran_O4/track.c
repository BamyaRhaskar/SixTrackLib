#include<stdio.h>

extern int thin6d_map_horizontal_dipole_(double *coord, double *argf, double *argi)
{
double xp = coord[2],yp = coord[3];
double LengthElementTiltCos = argf[0], LengthElementTiltSin = argf[1];
double RatioPtoPj = coord[4];

coord[2] = xp + LengthElementTiltCos * RatioPtoPj;
coord[3] = yp + LengthElementTiltSin * RatioPtoPj;

return 1;
}

extern int thin6d_map_normal_quadrupole_(double *coord, double *argf, double *argi)
{
}