#include<stdio.h>
#include<math.h>

extern int thin6d_map_beambeam_1_(double *coord, double *argf, double argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];

double OnePoweredToMinus38 = argf[25];
double PhysicalLengthOfBlock = argf[33];
int SwitchToLinearCoupling = (int)argf[34];
double ClosedOrbitBeamX = argf[35], ClosedOrbitBeamY = argf[36], ClosedOrbitBeamSigma = argf[37], ClosedOrbitBeamPx = argf[38], ClosedOrbitBeamPy = argf[39], ClosedOrbitBeamDelta = argf[40];
double HorBeamBeamSeparation = argf[9], VerBeamBeamSeparation = argf[10];
double SquareOfSigmaN = argf[41];
double BeamOffsetX = argf[42], BeamOffsetY = argf[43], BeamOffsetSigma = argf[44], BeamOffsetPx = argf[45], BeamOffsetPy = argf[46], BeamOffsetDelta = argf[47];
double bbcu11 = argf[48], bbcu12 = argf[49];

double crkvebj, cikvebj, rho2bj, tkbj, cccc;

if( SwitchToLinearCoupling == 0 )
{
crkvebj = ( x - ClosedOrbitBeamX ) + HorBeamBeamSeparation;
cikvebj = ( y - ClosedOrbitBeamY ) + VerBeamBeamSeparation;
}
else
{
crkvebj = (( x - ClosedOrbitBeamX ) + HorBeamBeamSeparation ) * bbcu11 + (( y - ClosedOrbitBeamY ) + VerBeamBeamSeparation ) * bbcu12;
cikvebj = (( y - ClosedOrbitBeamY ) + VerBeamBeamSeparation ) * bbcu11 + (( x - ClosedOrbitBeamX ) + HorBeamBeamSeparation ) * bbcu12;
}

rho2bj = crkvebj*crkvebj + cikvebj*cikvebj;
if( rho2bj <= OnePoweredToMinus38 ) return 1;

tkbj = rho2bj / ( 2.0 * SquareOfSigmaN );
if( SwitchToLinearCoupling == 0 )
{
coord[2] = xp + RatioPtoPj * ((( PhysicalLengthOfBlock * crkvebj ) / rho2bj ) * ( 1.0 - exp_rn( -1.0 * tkbj )) - BeamOffsetPx );
coord[3] = yp + RatioPtoPj * ((( PhysicalLengthOfBlock * cikvebj ) / rho2bj ) * ( 1.0 - exp_rn( -1.0 * tkbj )) - BeamOffsetPy );
}
else
{
cccc = ((( PhysicalLengthOfBlock * crkvebj ) / rho2bj ) * ( 1.0 - exp_rn( -1.0 * tkbj )) - BeamOffsetPx ) * bbcu11 - ((( PhysicalLengthOfBlock * cikvebj ) / rho2bj ) * ( 1.0 - exp_rn( -1.0 * tkbj )) - BeamOffsetPy ) * bbcu12;

coord[2] = xp + RatioPtoPj * cccc;
cccc = ((( PhysicalLengthOfBlock * crkvebj ) / rho2bj ) * ( 1.0 - exp_rn( -1.0 * tkbj )) - BeamOffsetPx ) * bbcu12 - ((( PhysicalLengthOfBlock * cikvebj ) / rho2bj ) * ( 1.0 - exp_rn( -1.0 * tkbj )) - BeamOffsetPy ) * bbcu11;

coord[3] = yp + RatioPtoPj * cccc;
}

return 1;
}

extern int thin6d_map_beambeam_2_ibtyp_0_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];

double OnePoweredToMinus38 = argf[25];
double PhysicalLengthOfBlock = argf[33];
int SwitchToLinearCoupling = (int)argf[34];
double ClosedOrbitBeamX = argf[35], ClosedOrbitBeamY = argf[36], ClosedOrbitBeamSigma = argf[37], ClosedOrbitBeamPx = argf[38], ClosedOrbitBeamPy = argf[39], ClosedOrbitBeamDelta = argf[40];
double HorBeamBeamSeparation = argf[9], VerBeamBeamSeparation = argf[10];
double SquareOfSigmaN = argf[41];
double BeamOffsetX = argf[42], BeamOffsetY = argf[43], BeamOffsetSigma = argf[44], BeamOffsetPx = argf[45], BeamOffsetPy = argf[46], BeamOffsetDelta = argf[47];
double bbcu11 = argf[48], bbcu12 = argf[49];
double SigmaNqX = argf[50], SigmaNqY = argf[51];

double crkvebj, cikvebj, rho2bj, tkbj, cccc, r2bj, rbj, rkbj, xrbj, zrbj, xbbj, zbbj;

r2bj = 2.0 * ( SquareOfSigmaNX - SquareOfSigmaNY );
rbj = sqrt(r2bj);

rkbj = ( PhysicalLengthOfBlock * SquareRootOfPi ) / rbj;

if( SwitchToLinearCoupling == 0 )
{
crkvebj = ( x - ClosedOrbitBeamX ) + HorBeamBeamSeparation;
cikvebj = ( y - ClosedOrbitBeamY ) + VerBeamBeamSeparation;
}
else
{
crkvebj = (( x - ClosedOrbitBeamX ) + HorBeamBeamSeparation ) * bbcu11 + (( y - ClosedOrbitBeamY ) + VerBeamBeamSeparation ) * bbcu12;
cikvebj = (( y - ClosedOrbitBeamY ) + VerBeamBeamSeparation ) * bbcu11 + (( x - ClosedOrbitBeamX ) + HorBeamBeamSeparation ) * bbcu12;
}

xrbj = abs(crkvebj) / rbj;
zrbj = abs(cikvebj) / rbj;

errf( &xrbj, &arbj, &crxbj, &crzbj );

tkbj = ( crkvebj*crkvebj / SquareOfSigmaNX + cikvebj*cikvebj / SquareOfSigmaNY ) * 0.5;

xbbj = SigmaNqY * xrbj;
zbbj = SigmaNqX * zrbj;

errf( &xbbj, &zbbj, &cbxbj, &cbzbj );

if( SwitchToLinearCoupling == 0 )
{
coord[2] = xp + RatioPtoPj * (( rkbj * ( crzbj - exp_rn( -1.0 * tkbj ) * cbzbj )) *sign( 1.0, crkvebj ) - BeamOffsetPx );
coord[3] = yp + RatioPtoPj * (( rkbj * ( crxbj - exp_rn( -1.0 * tkbj ) * cbxbj )) *sign( 1.0, cikvebj ) - BeamOffsetPy );
}
else
{
cccc = (( rkbj * crzbj - exp_rn( -1.0 * tkbj ) * cbzbj )) * sign( 1.0, crkvebj ) - BeamOffsetPx ) * bbcu11 - (( rkbj * ( crkxbj - exp_rn(-1.0 * tkbj ) * cbxbj )) * sign( 1.0, cikvebj ) - BeamOffsetPy ) * bbcu12;
coord[2] = xp + RatioPtoPj * cccc;

cccc = (( rkbj * crzbj - exp_rn( -1.0 * tkbj ) * cbzbj )) * sign( 1.0, crkvebj ) - BeamOffsetPx ) * bbcu12 - (( rkbj * ( crkxbj - exp_rn(-1.0 * tkbj ) * cbxbj )) * sign( 1.0, cikvebj ) - BeamOffsetPy ) * bbcu11;
coord[3] = yp + RatioPtoPj * cccc;
}

return 1;
}