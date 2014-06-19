#include<stdio.h>
#include<math.h>
#include"crlibm/crlibm.h"

#define OnePoweredToMinus38               1.0e-38
#define Zero                              0.0
#define Half                              0.5
#define One                               1.0
#define Two                               2.0
#define Three                             3.0
#define Four                              4.0
#define OnePoweredTo1                     1.0e1
#define OnePoweredTo2                     1.0e2
#define OnePoweredTo3                     1.0e3
#define OnePoweredTo4                     1.0e4
#define OnePoweredTo5      	          1.0e5
#define OnePoweredTo6                     1.0e6
#define OnePoweredTo12                    1.0e12
#define OnePoweredTo13                    1.0e13
#define OnePoweredTo15                    1.0e15
#define OnePoweredTo16                    1.0e16

#define TwoPoweredTo3                     2.0e3
#define FourPoweredTo3                    4.0e3

#define OnePoweredToMinus1                1.0e-1
#define OnePoweredToMinus2                1.0e-2
#define OnePoweredToMinus3                1.0e-3
#define OnePoweredToMinus6                1.0e-6
#define OnePoweredToMinus7                1.0e-7
#define OnePoweredToMinus9                1.0e-9
#define OnePoweredToMinus10               1.0e-10
#define OnePoweredToMinus12               1.0e-12
#define OnePoweredToMinus13               1.0e-13
#define OnePoweredToMinus15               1.0e-15
#define OnePoweredToMinus18               1.0e-18
#define OnePoweredToMinus21               1.0e-21
#define OnePoweredToMinus24               1.0e-24
#define OnePoweredToMinus36               1.0e-36

#define SpeedOfLight_mps                  2.99792458e8
#define RestMastOfProton_MeV              938.271998e0 
#define ClassicalRadiusOfElectron_m       2.817940285e-15
#define RestMassofElectron_MeV            0.510998902e0 
#define Pi                                4.0*atan_rn(1.0)

#define make_map_crab_cavity( I, C ) \
int cntcrabcavity##I = 0;   \
      extern int thin6d_map_crab_cavity_##I##_(double *coord, double *argf, double *argi) \
{ \
double x = coord[0], y = coord[1]; \
double xp = coord[2], yp = coord[3]; \
double RatioPtoPj = coord[4];          \
double PathLengthDiff = coord[5];        \
double EnergyOfParticle = coord[6], MomentumOfParticle = coord[7]; \
double RatioDeltaPtoP = coord[8], RatioDeltaPtoP1 = coord[9];   \
double RatioBetaToBetaj = coord[12];    \
double MomentumOfParticle0 = coord[13];   \
                                                    \
double AmplitudeCrabCavity = argf[91], FrequencyCrabCavity = argf[6], PhaseCrabCavity = argf[92];   \
double FirstAdditionalDatum = argf[9];        \
double RestMassOfParticle = argf[17];         \
double EnergyOfReferenceParticle =argf[14], MomentumOfReferenceParticle = argf[13];   \
                    \
AmplitudeCrabCavity = ( FirstAdditionalDatum / MomentumOfParticle ) * OnePoweredTo3;    \
C##p = C##p - AmplitudeCrabCavity * sin_rn(((( PathLengthDiff / SpeedOfLight_mps ) * FrequencyCrabCavity ) * 2.0 ) * Pi + PhaseCrabCavity );  \
\
RatioDeltaPtoP = RatioDeltaPtoP - (((((( AmplitudeCrabCavity * FrequencyCrabCavity) * 2.0 ) * Pi ) / SpeedOfLight_mps ) * C ) * cos_rn(((( PathLengthDiff / SpeedOfLight_mps ) * FrequencyCrabCavity ) * 2.0 ) * Pi + PhaseCrabCavity ) ) * OnePoweredToMinus3;  \
 \
MomentumOfParticle0 = MomentumOfParticle;  \
MomentumOfParticle = RatioDeltaPtoP * MomentumOfReferenceParticle + MomentumOfReferenceParticle;   \
EnergyOfParticle = sqrt( MomentumOfParticle*MomentumOfParticle + RestMassOfParticle*RestMassOfParticle );  \
RatioPtoPj = One / ( One + RatioDeltaPtoP );     \
RatioDeltaPtoP1 = ( RatioDeltaPtoP * OnePoweredTo3 ) * RatioPtoPj;  \
xp = ( MomentumOfParticle0 / MomentumOfParticle ) * xp;   \
yp = ( MomentumOfParticle0 / MomentumOfParticle ) * yp;   \
RatioBetaToBetaj = ( EnergyOfParticle * MomentumOfReferenceParticle ) / ( EnergyOfReferenceParticle * MomentumOfParticle );  \
\
coord[2] = xp;    coord[3] = yp;  \
coord[4] = RatioPtoPj;             \
coord[6] = EnergyOfParticle;  coord[7] = MomentumOfParticle; coord[13] = MomentumOfParticle0;  \
coord[8] = RatioDeltaPtoP;    coord[9] = RatioDeltaPtoP1;   \
coord[12] = RatioBetaToBetaj;      \
\
cntcrabcavity##I++;   \
printf("Crab Cavity##I called %d times\n",cntcrabcavity##I);   \
return 1;   \
}; \

make_map_crab_cavity(1,x);
make_map_crab_cavity(2,y);

extern int thin6d_modify_coords_for_hirata_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];
double PathLengthDiff = coord[5];
double RatioDeltaPtoP = coord[8];
double ModifiedX = coord[25], ModifiedXp = coord[26], ModifiedY = coord[27], ModifiedYp = coord[28], ModifiedSigma = coord[29], ModifiedDelta = coord[30];

double HorBeamBeamSeparation = argf[9], VerBeamBeamSeparation = argf[10];
double ClosedOrbitBeamX = argf[35], ClosedOrbitBeamY = argf[36], ClosedOrbitBeamSigma = argf[37], ClosedOrbitBeamPx = argf[38], ClosedOrbitBeamPy = argf[39], ClosedOrbitBeamDelta = argf[40];
 
ModifiedX = ( x + HorBeamBeamSeparation - ClosedOrbitBeamX ) * OnePoweredToMinus3;
ModifiedXp = ( xp / RatioPtoPj - ClosedOrbitBeamPx ) * OnePoweredToMinus3;
ModifiedY = ( y + VerBeamBeamSeparation - ClosedOrbitBeamY ) * OnePoweredToMinus3;
ModifiedYp = ( yp / RatioPtoPj  - ClosedOrbitBeamPy ) * OnePoweredToMinus3;
ModifiedSigma = ( PathLengthDiff - ClosedOrbitBeamSigma ) * OnePoweredToMinus3;
ModifiedDelta = RatioDeltaPtoP - ClosedOrbitBeamDelta;

coord[25] = ModifiedX;
coord[26] = ModifiedXp;
coord[27] = ModifiedY;
coord[28] = ModifiedYp;
coord[29] = ModifiedSigma;
coord[30] = ModifiedDelta;

return 1;
}

extern int thin6d_map_hirata_beambeam_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];
double PathLengthDiff = coord[5];
double EnergyOfParticle = coord[6], MomentumOfParticle = coord[7];
double RatioDeltaPtoP = coord[8];
double RatioBetaToBetaj = coord[12];
double ModifiedX = coord[25], ModifiedXp = coord[26], ModifiedY = coord[27], ModifiedYp = coord[28], ModifiedSigma = coord[29], ModifiedDelta = coord[30];

double HorBeamBeamSeparation = argf[9], VerBeamBeamSeparation = argf[10];
double EnergyOfReferenceParticle = argf[14], MomentumOfReferenceParticle = argf[13];
double RestMassOfParticle = argf[17];
double ClosedOrbitBeamX = argf[35], ClosedOrbitBeamY = argf[36], ClosedOrbitBeamSigma = argf[37], ClosedOrbitBeamPx = argf[38], ClosedOrbitBeamPy = argf[39], ClosedOrbitBeamDelta = argf[40];
double BeamOffsetX = argf[42], BeamOffsetY = argf[43], BeamOffsetSigma = argf[44], BeamOffsetPx = argf[45], BeamOffsetPy = argf[46], BeamOffsetDelta = argf[47];

x = ( ModifiedX * OnePoweredTo3 + ClosedOrbitBeamX ) - BeamOffsetX;
coord[0] = x;
y = ( ModifiedY * OnePoweredTo3 + ClosedOrbitBeamY ) - BeamOffsetY;
coord[1] = y;
RatioDeltaPtoP = ( ModifiedDelta + ClosedOrbitBeamDelta ) - BeamOffsetDelta;
coord[8] = RatioDeltaPtoP;
RatioPtoPj = One / ( One + RatioDeltaPtoP );
coord[4] = RatioPtoPj;
xp = (( ModifiedXp * OnePoweredTo3 + ClosedOrbitBeamPx ) - BeamOffsetPx ) * RatioPtoPj;
coord[2] = xp;
yp = (( ModifiedYp * OnePoweredTo3 + ClosedOrbitBeamPy ) - BeamOffsetPy ) * RatioPtoPj;
coord[3] = yp;
MomentumOfParticle = RatioDeltaPtoP * MomentumOfReferenceParticle + MomentumOfReferenceParticle;
coord[7] = MomentumOfParticle;
EnergyOfParticle = sqrt( MomentumOfParticle*MomentumOfParticle + RestMassOfParticle*RestMassOfParticle );
coord[6] = EnergyOfParticle;
RatioBetaToBetaj = ( EnergyOfParticle * MomentumOfReferenceParticle ) / ( EnergyOfReferenceParticle * MomentumOfParticle );
coord[12] = RatioBetaToBetaj;

printf("Hirata called\n");
return 1;
}

extern int thin6d_map_accelerating_cavity_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double PathLengthDiff = coord[5];
double RatioDeltaPtoP = coord[8];

int idz1 = (int)argf[54], idz2 = (int)argf[55];
double cotr_irrtr_1 = argf[56], cotr_irrtr_2 = argf[57], cotr_irrtr_3 = argf[58], cotr_irrtr_4 = argf[59], cotr_irrtr_5 = argf[60], cotr_irrtr_6 = argf[61];
double rrtr_irrtr_5_1 = argf[62], rrtr_irrtr_5_2 = argf[63], rrtr_irrtr_5_3 = argf[64], rrtr_irrtr_5_4 = argf[65], rrtr_irrtr_5_6 = argf[66], rrtr_irrtr_1_1 = argf[67], rrtr_irrtr_1_2 = argf[68], rrtr_irrtr_1_6 = argf[69], rrtr_irrtr_2_1 = argf[70], rrtr_irrtr_2_2 = argf[71], rrtr_irrtr_2_6 = argf[72], rrtr_irrtr_3_3 = argf[73], rrtr_irrtr_3_4 = argf[74], rrtr_irrtr_3_6 = argf[75], rrtr_irrtr_4_3 = argf[76], rrtr_irrtr_4_4 = argf[77], rrtr_irrtr_4_6 = argf[78];

double pux,dpsv3j;

PathLengthDiff  = ((((( PathLengthDiff + cotr_irrtr_5 ) + rrtr_irrtr_5_1 * x ) + rrtr_irrtr_5_2 * xp ) + rrtr_irrtr_5_3 * y ) + rrtr_irrtr_5_4 * yp ) + ( rrtr_irrtr_5_6 * RatioDeltaPtoP ) * OnePoweredTo3;
coord[5] = PathLengthDiff;
pux = x;
dpsv3j = RatioDeltaPtoP * OnePoweredTo3;
x = (( cotr_irrtr_2 + rrtr_irrtr_1_1 * pux ) + rrtr_irrtr_1_2 * xp ) + ( (double)idz1 * dpsv3j ) * rrtr_irrtr_1_6;
coord[0] = x;
xp = (( cotr_irrtr_2 + rrtr_irrtr_2_1 * pux ) + rrtr_irrtr_2_2 * xp ) + ( (double)idz1 * dpsv3j ) * rrtr_irrtr_2_6;
coord[2] = xp;
pux = y;
y = (( cotr_irrtr_3 + rrtr_irrtr_3_3 * pux ) + rrtr_irrtr_3_4 * yp ) + ( (double)idz2 * dpsv3j ) * rrtr_irrtr_3_6;
coord[1] = y;
yp = (( cotr_irrtr_4 + rrtr_irrtr_4_3 * pux ) + rrtr_irrtr_4_4 * yp ) + ( (double)idz2 * dpsv3j ) * rrtr_irrtr_4_6;
coord[3] = yp;

printf("accelerating cavity\n");
return 1;
}

extern int thin6d_map_dipedge_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];
double RatioBetaToBetaj = coord[12];

double CurrentEntryDisplacementX = argf[2], CurrentEntryDisplacementY = argf[3];
double TiltComponentCos = argf[4], TiltComponentSin = argf[5];
double PhysicalLengthOfBlock = argf[33];
double PhysicalLengthOfBlockHorComp = argf[79],  PhysicalLengthOfBlockVerComp = argf[80];

double xlvj, zlvj, crkve, cikve;

xlvj = ( x - CurrentEntryDisplacementX ) * TiltComponentCos + ( y - CurrentEntryDisplacementY ) * TiltComponentSin;
zlvj = ( y - CurrentEntryDisplacementY ) * TiltComponentCos + ( x - CurrentEntryDisplacementX ) * TiltComponentSin;
crkve = xlvj;
cikve = zlvj;
xp = xp + RatioPtoPj * ( PhysicalLengthOfBlockHorComp * crkve - PhysicalLengthOfBlock * TiltComponentCos * cikve );
coord[2] = xp;
yp = yp + RatioPtoPj * ( PhysicalLengthOfBlockVerComp * cikve + PhysicalLengthOfBlock * TiltComponentCos * crkve );
coord[3] = yp;

return 1;
}

int cntsolenoid = 0;
extern int thin6d_map_solenoid_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double PathLengthDiff = coord[5];
double EnergyOfParticle = coord[6], MomentumOfParticle = coord[7];
double RatioBetaToBetaj = coord[12];
double MomentumOfParticle0 = coord[13];
//double cos_rn = coord[31], sin_rn = coord[32];

double PhysicalLengthOfBlockHorComp = argf[79],  PhysicalLengthOfBlockVerComp = argf[80];
double crkve, cikve, temp;

xp = xp - y * PhysicalLengthOfBlockHorComp;
yp = yp + x * PhysicalLengthOfBlockHorComp;
crkve = xp - ((( x * PhysicalLengthOfBlockHorComp ) * PhysicalLengthOfBlockVerComp ) * MomentumOfParticle0 ) / MomentumOfParticle;

cikve = yp - ((( y * PhysicalLengthOfBlockHorComp ) * PhysicalLengthOfBlockVerComp ) * MomentumOfParticle0 ) / MomentumOfParticle;

temp = ( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle;

xp = crkve * cos_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle ) + cikve * sin_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle );
yp = cikve * cos_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle ) - crkve * sin_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle );

crkve = x * cos_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle ) + y * sin_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle );
cikve = y * cos_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle ) - x * sin_rn(( PhysicalLengthOfBlockVerComp * MomentumOfParticle0 ) / MomentumOfParticle );
x = crkve;
y = cikve;
xp = xp + y * PhysicalLengthOfBlockHorComp;
yp = yp - x * PhysicalLengthOfBlockHorComp;
crkve = PathLengthDiff - 0.5 * ((((((( x*x + y*y ) * PhysicalLengthOfBlockHorComp ) * PhysicalLengthOfBlockVerComp ) * RatioBetaToBetaj ) * MomentumOfParticle0 ) / MomentumOfParticle ) * MomentumOfParticle0 ) / MomentumOfParticle;
PathLengthDiff = crkve;
crkve = xp - ((( x * PhysicalLengthOfBlockHorComp ) * PhysicalLengthOfBlockVerComp ) * MomentumOfParticle0 ) / MomentumOfParticle;
cikve = yp - ((( y * PhysicalLengthOfBlockHorComp ) * PhysicalLengthOfBlockVerComp ) * MomentumOfParticle0 ) / MomentumOfParticle;
PathLengthDiff = PathLengthDiff + (((((( x * cikve - y * crkve ) * PhysicalLengthOfBlockVerComp ) * RatioBetaToBetaj ) * MomentumOfParticle0 ) / MomentumOfParticle ) * MomentumOfParticle0 ) /MomentumOfParticle;

coord[0] = x;   coord[1] = y;
coord[2] = xp;  coord[3]= yp;
coord[5] = PathLengthDiff;

//cntsolenoid++;
//printf("solenoid called %d times\n",cntsolenoid);
return 1;
}

int cntacdipole = 0;
extern int thin6d_map_ac_dipole_(double *coord, double *argf, double *argi)
{
double xp = coord[2], yp = coord[3];
double MomentumOfParticle = coord[7];

double TiltComponentCos = argf[4], TiltComponentSin = argf[5];
double xory = argf[81];
double ACDipoleAmplitude = argf[82], ACDipoleAmplitudeHorComp = argf[83], ACDipoleAmplitudeVerComp = argf[84];
int nramp1 = (int)argf[85], nramp2 = (int)argf[86], nac = (int)argf[87], nplato = (int)argf[90];
double Qd = argf[88], ACPhase = argf[89];

if( xory == 1 )
{
ACDipoleAmplitudeVerComp = ACDipoleAmplitude * TiltComponentSin;
ACDipoleAmplitudeHorComp = ACDipoleAmplitude * TiltComponentCos;
}
else
{
ACDipoleAmplitudeVerComp = ACDipoleAmplitude * TiltComponentCos;
ACDipoleAmplitudeHorComp = - ACDipoleAmplitude * TiltComponentSin;
}

if( nramp1 > nac )
{
xp = xp + ((( ACDipoleAmplitudeHorComp * sin_rn((( 2.0 * Pi ) * Qd ) * (double)nac + ACPhase ) ) * (double)nac ) / (double)nramp1 ) / MomentumOfParticle;
yp = yp + ((( ACDipoleAmplitudeVerComp * sin_rn((( 2.0 * Pi ) * Qd ) * (double)nac + ACPhase )  ) * (double)nac ) / (double)nramp1 ) / MomentumOfParticle;
}

if( nac >= nramp1 && ( nramp1 + nplato ) > nac )
{
xp = xp + ( ACDipoleAmplitudeHorComp * sin_rn((( 2.0 * Pi ) * Qd ) * (double)nac + ACPhase )  ) / MomentumOfParticle;
yp = yp + ( ACDipoleAmplitudeVerComp * sin_rn((( 2.0 * Pi ) * Qd ) * (double)nac + ACPhase )  ) / MomentumOfParticle;
}

if( nac >= ( nramp1 + nplato ) && ( nramp2 + nramp1 + nplato ) > nac )
{
xp = xp + (( ACDipoleAmplitudeHorComp * sin_rn((( 2.0 * Pi ) * Qd ) * (double)nac + ACPhase )  ) * (( -1.0 * (double)nac - nramp1 - nramp2 - nplato ) / (double)nramp2 )) / MomentumOfParticle;
yp = yp + (( ACDipoleAmplitudeVerComp * sin_rn((( 2.0 * Pi ) * Qd ) * (double)nac + ACPhase )  ) * (( -1.0 * (double)nac - nramp1 - nramp2 - nplato ) / (double)nramp2 )) / MomentumOfParticle;
}

coord[2] = xp;
coord[3] = yp;

cntacdipole++;
printf("AC Dipole called %d times",cntacdipole);
return 1;
}

/*
int cntcrabcavity1 = 0;
extern int thin6d_map_crab_cavity_1_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];
double PathLengthDiff = coord[5];
double EnergyOfParticle = coord[6], MomentumOfParticle = coord[7];
double RatioDeltaPtoP = coord[8], RatioDeltaPtoP1 = coord[9];
double RatioBetaToBetaj = coord[12];
double MomentumOfParticle0 = coord[13];
//double sin_rn = coord[34], cos_rn = coord[33];

double AmplitudeCrabCavity = argf[91], FrequencyCrabCavity = argf[6], PhaseCrabCavity = argf[92];
double FirstAdditionalDatum = argf[9];
double RestMassOfParticle = argf[17];
double EnergyOfReferenceParticle =argf[14], MomentumOfReferenceParticle = argf[13];

AmplitudeCrabCavity = ( FirstAdditionalDatum / MomentumOfParticle ) * OnePoweredTo3;
xp = xp - AmplitudeCrabCavity * sin_rn(((( PathLengthDiff / SpeedOfLight_mps ) * FrequencyCrabCavity ) * 2.0 ) * Pi + PhaseCrabCavity );

RatioDeltaPtoP = RatioDeltaPtoP - (((((( AmplitudeCrabCavity * FrequencyCrabCavity) * 2.0 ) * Pi ) / SpeedOfLight_mps ) * x ) * cos_rn(((( PathLengthDiff / SpeedOfLight_mps ) * FrequencyCrabCavity ) * 2.0 ) * Pi + PhaseCrabCavity ) ) * OnePoweredToMinus3;

MomentumOfParticle0 = MomentumOfParticle;
MomentumOfParticle = RatioDeltaPtoP * MomentumOfReferenceParticle + MomentumOfReferenceParticle;
EnergyOfParticle = sqrt( MomentumOfParticle*MomentumOfParticle + RestMassOfParticle*RestMassOfParticle );
RatioPtoPj = One / ( One + RatioDeltaPtoP );
RatioDeltaPtoP1 = ( RatioDeltaPtoP * OnePoweredTo3 ) * RatioPtoPj;
xp = ( MomentumOfParticle0 / MomentumOfParticle ) * xp;
yp = ( MomentumOfParticle0 / MomentumOfParticle ) * yp;
RatioBetaToBetaj = ( EnergyOfParticle * MomentumOfReferenceParticle ) / ( EnergyOfReferenceParticle * MomentumOfParticle );

coord[2] = xp;    coord[3] = yp;
coord[4] = RatioPtoPj;
coord[6] = EnergyOfParticle;  coord[7] = MomentumOfParticle; coord[13] = MomentumOfParticle0;
coord[8] = RatioDeltaPtoP;    coord[9] = RatioDeltaPtoP1;
coord[12] = RatioBetaToBetaj;

cntcrabcavity1++;
printf("Crab Cavity1 called %d times\n",cntcrabcavity1);
return 1;
}

int cntcrabcavity2 = 0;
extern int thin6d_map_crab_cavity_2_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioPtoPj = coord[4];
double PathLengthDiff = coord[5];
double EnergyOfParticle = coord[6], MomentumOfParticle = coord[7];
double RatioDeltaPtoP = coord[8], RatioDeltaPtoP1 = coord[9];
double RatioBetaToBetaj = coord[12];
double MomentumOfParticle0 = coord[13];
//double sin_rn = coord[34], cos_rn = coord[33];

double AmplitudeCrabCavity = argf[91], FrequencyCrabCavity = argf[6], PhaseCrabCavity = argf[92];
double FirstAdditionalDatum = argf[9];
double RestMassOfParticle = argf[17];
double EnergyOfReferenceParticle =argf[14], MomentumOfReferenceParticle = argf[13];

AmplitudeCrabCavity = ( FirstAdditionalDatum / MomentumOfParticle ) * OnePoweredTo3;
yp = yp - AmplitudeCrabCavity * sin_rn(((( PathLengthDiff / SpeedOfLight_mps ) * FrequencyCrabCavity ) * 2.0 ) * Pi + PhaseCrabCavity );
RatioDeltaPtoP = RatioDeltaPtoP - (((((( AmplitudeCrabCavity * FrequencyCrabCavity) * 2.0 ) * Pi ) / SpeedOfLight_mps ) * y ) * cos_rn(((( PathLengthDiff / SpeedOfLight_mps ) * FrequencyCrabCavity ) * 2.0 ) * Pi + PhaseCrabCavity ) ) * OnePoweredToMinus3;
MomentumOfParticle0 = MomentumOfParticle;
MomentumOfParticle = RatioDeltaPtoP * MomentumOfReferenceParticle + MomentumOfReferenceParticle;
EnergyOfParticle = sqrt( MomentumOfParticle*MomentumOfParticle + RestMassOfParticle*RestMassOfParticle );
RatioPtoPj = One / ( One + RatioDeltaPtoP );
RatioDeltaPtoP1 = ( RatioDeltaPtoP * OnePoweredTo3 ) * RatioPtoPj;
xp = ( MomentumOfParticle0 / MomentumOfParticle ) * xp;
yp = ( MomentumOfParticle0 / MomentumOfParticle ) * yp;
RatioBetaToBetaj = ( EnergyOfParticle * MomentumOfReferenceParticle ) / ( EnergyOfReferenceParticle * MomentumOfParticle );

coord[2] = xp;    coord[3] = yp;
coord[4] = RatioPtoPj;
coord[6] = EnergyOfParticle;  coord[7] = MomentumOfParticle; coord[13] = MomentumOfParticle0;
coord[8] = RatioDeltaPtoP;    coord[9] = RatioDeltaPtoP1;
coord[12] = RatioBetaToBetaj;

cntcrabcavity2++;
printf("Crab Cavity2 called %d times\n",cntcrabcavity2);
return 1;
} 
*/
int cntwire = 0;
extern int thin6d_map_wire_(double *coord, double *argf, double *argi)
{
double x = coord[0], y = coord[1];
double xp = coord[2], yp = coord[3];
double RatioDeltaPtoP = coord[8];

double embl = argf[93], tx = argf[94], ty= argf[95], lin = argf[96];
double rx = argf[97], ry = argf[98], cur = argf[99], chi = argf[100], l = argf[101], leff = argf[102];

double xi, yi;

x = x * OnePoweredToMinus3;
y = y * OnePoweredToMinus3;
xp = xp * OnePoweredToMinus3;
yp = yp * OnePoweredToMinus3;

x = x - (( embl * 0.5 ) * xp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );
y = y - (( embl * 0.5 ) * yp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );

y = y - ((( x * sin_rn(tx) ) * yp ) / sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - yp*yp )) / cos_rn(atan_rn(xp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) - tx );

x = x * ( cos_rn(tx) - sin_rn(tx) * tan_rn(atan_rn(xp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) - tx ));

xp = sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - yp*yp ) * sin_rn(atan_rn(xp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) - tx );

x = x - ((( y * sin_rn(ty) ) * xp ) / sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - yp*yp )) / cos_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) - ty );
y = y * ( cos_rn(ty) - sin_rn(ty) * tan_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) - ty ));

yp = sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - yp*yp ) * sin_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) - ty );
 
x = x + ( lin * xp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );
y = y + ( lin * yp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );

xi = x - rx;
yi = y - ry;

xp = xp - (((( OnePoweredToMinus7 * cur ) / chi ) * xi ) / ( xi*xi + yi*yi )) * ( sqrt((( lin + l )*( lin + l ) + xi*xi ) + yi*yi ) - sqrt((( lin -l )*( lin -l ) + xi*xi ) + yi*yi ));
yp = yp - (((( OnePoweredToMinus7 * cur ) / chi ) * yi ) / ( xi*xi + yi*yi )) * ( sqrt((( lin + l )*( lin + l ) + xi*xi ) + yi*yi ) - sqrt((( lin -l )*( lin -l ) + xi*xi ) + yi*yi ));

x = x + (( leff - lin ) * xp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );
y = y + (( leff - lin ) * yp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );

x = x - ((( y * sin_rn(-ty) ) * xp ) / sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp )) / cos_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) + ty );

y = y * ( cos_rn(-1.0 * ty) - sin_rn(-1.0 * ty) * tan_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) + ty ));

yp = sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) * sin_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) + ty );

y = y - ((( x * sin_rn(-1.0 * tx) ) * yp ) / sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - yp*yp )) / cos_rn(atan_rn(yp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) + tx );

x = x * ( cos_rn(-1.0 * tx) - sin_rn(-1.0 * tx) * tan_rn(atan_rn(xp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) + tx ));

xp = sqrt(( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - yp*yp ) * sin_rn(atan_rn(xp / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp )) + tx );

x = x + embl * tan_rn(tx);
y = y + (embl * tan_rn(ty) ) / cos_rn(tx);

x = x - (( embl * 0.5 ) * xp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );
y = y - (( embl * 0.5 ) * yp ) / sqrt((( 1.0 + RatioDeltaPtoP )*( 1.0 + RatioDeltaPtoP ) - xp*xp ) - yp*yp );

x = x * OnePoweredTo3;
y = y * OnePoweredTo3;
xp = xp * OnePoweredTo3;
yp = yp * OnePoweredTo3;

coord[0] = x;
coord[1] = y;
coord[2] = xp;
coord[3] = yp;

cntwire++;
printf("thin6d wire called %d times",cntwire);
return 1;
}
