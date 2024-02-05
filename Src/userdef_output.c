#include "pluto.h"

/* *************************************************************** */
void ComputeUserVar (const Data *d, Grid *grid)
/*
 *
 *  PURPOSE
 *
 *    Define user-defined output variables
 *
 *
 *
 ***************************************************************** */
{
  int i, j, k;
  //MY SECTION START:
  //double ***T, ***vortz;
  //double ***p, ***rho, ***vx, ***vy;
  //double *dx, *dy;
  //T = GetUserVar("T");
  //vortz = GetUserVar("vortz");
  //rho = d->Vc[RHO]; /* pointer shortcut to density */
  //p = d->Vc[PRS]; /* pointer shortcut to pressure */
  //vx = d->Vc[VX1]; /* pointer shortcut to x-velocity */
  //vy = d->Vc[VX2]; /* pointer shortcut to y-velocity */
  //dx = grid->dx[IDIR]; /* shortcut to dx */
  //dy = grid->dx[JDIR]; /* shortcut to dy */
  //END
  
  DOM_LOOP(k,j,i){
    //MY SECTION START
    //T[k][j][i] = p[k][j][i]/rho[k][j][i];
    //vortz[k][j][i] = 0.5*(vy[k][j][i+1] - vy[k][j][i-1])/dx[i]
    //  - 0.5*(vx[k][j+1][i] - vx[k][j-1][i])/dy[j];
    //END
  }
}
/* ************************************************************* */
void ChangeOutputVar ()
/* 
 *
 * 
 *************************************************************** */
{ 
  Image *image;
  //MY SECTION START
  //SetOutputVar("bx1", FLT_OUTPUT, NO);
  //SetOutputVar("prs", PPM_OUTPUT, YES);
  //SetOutputVar("vortz", PNG_OUTPUT, YES);
  //image = GetImage ("rho");
  //image->slice_plane = X13_PLANE;
  //image->slice_coord = 1.1;
  //image->max = image->min = 0.0;
  //image->logscale = 1;
  //image->colormap = "red";
  //END

#if PARTICLES
  //SetOutputVar ("energy",PARTICLES_FLT_OUTPUT, NO);
//  SetOutputVar ("x1",    PARTICLES_FLT_OUTPUT, NO);
  //SetOutputVar ("vx1",   PARTICLES_FLT_OUTPUT, NO);
#endif

}





