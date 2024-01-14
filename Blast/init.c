/* ///////////////////////////////////////////////////////////////////// */
/*! 
  \file  
  \brief Hydrodynamics blast wave problem.

  Set up an isothermal blast wave in a non-uniform, randomnly
  perturbed density field.
  The background perturbation is interpolated read from an input 
  file generated externally.

  \authors A. Mignone (mignone@ph.unito.it)\n
           P. Tzeferacos (petros.tzeferacos@ph.unito.it)
  \date    Nov 19, 2016
*/
/* ///////////////////////////////////////////////////////////////////// */
#include "pluto.h"

/* ********************************************************************* */
void Init (double *v, double x1, double x2, double x3)
/*! 
 *
 *********************************************************************** */
{
	double r;
	g_gamma = g_inputParam[gamma]; /* calls the auxiliary parameter GAMMA*/
	r = x1*x1 + x2*x2;
	r = sqrt(r);
	v[RHO] = 1.0; /* initial density array */
	v[VX1] = 0.0; /* initial Vx array */
	v[VX2] = 0.0; /* initial Vy array */
	v[VX3] = 0.0; /* initial Vz array */
	v[PRS] = g_inputParam[P_OUT]; /* calls the auxiliary parameter P_OUT */
	if (r <= 0.3) v[PRS] = g_inputParam[P_IN]; /* calls the input parameter P_IN */
}

/* ********************************************************************* */
void InitDomain (Data *d, Grid *grid)
/*! 
 * Assign initial condition by looping over the computational domain.
 * Called after the usual Init() function to assign initial conditions
 * on primitive variables.
 * Value assigned here will overwrite those prescribed during Init().
 *
 *
 *********************************************************************** */
{
  int i,j,k,id;
  double *x1 = grid->x[IDIR];
  double *x2 = grid->x[JDIR];
  double *x3 = grid->x[KDIR];
  double r;


#if ADD_TURBULENCE == YES
  id = InputDataOpen ("rho0.dbl","grid0.out"," ", 0, CENTER);
  TOT_LOOP(k,j,i){
    d->Vc[RHO][k][j][i] = InputDataInterpolate(id,x1[i],x2[j],x3[k]);
  }
  InputDataClose(id);
#else
  TOT_LOOP(k,j,i){
    d->Vc[RHO][k][j][i] = 1.0;
  }
#endif

  TOT_LOOP(k,j,i){

    #if GEOMETRY == CARTESIAN
    r = DIM_EXPAND(x1[i]*x1[i], + x2[j]*x2[j], + x3[k]*x3[k]);
    r = sqrt(r);
    #elif GEOMETRY == POLAR
    r = x1[i]; 
    #endif

  /* -- Set ambient pressure -- */

    #if EOS == IDEAL
    d->Vc[PRS][k][j][i] = 1.0/g_gamma;  /* ambient pressure */
    #elif EOS == PVTE_LAW
    d->Vc[PRS][k][j][i] = 1.0;
    #endif

  /* -- Set blast wave density and pressure -- */

    if (r < 0.1) {
      d->Vc[RHO][k][j][i] = g_inputParam[RHO_IN];
      #if HAVE_ENERGY
      d->Vc[PRS][k][j][i] = g_inputParam[PRS_IN];
      #endif
    }

  /* -- Static medium, v = 0 -- */

    d->Vc[VX1][k][j][i] = 0.0; 
    d->Vc[VX2][k][j][i] = 0.0;
    d->Vc[VX3][k][j][i] = 0.0;
  }
  
}

/* **************************************************************** */
void Analysis (const Data *d, Grid *grid)
/* 
 *
 * PURPOSE
 *  
 *   Perform some pre-processing data
 *
 * ARGUMENTS
 *
 *   d:      the PLUTO Data structure.
 *   grid:   pointer to array of GRID structures  
 *
 **************************************************************** */
{

}

/* ************************************************************** */
void UserDefBoundary (const Data *d, RBox *box, int side, Grid *grid) 
/* 
 *
 *
 **************************************************************** */
{
}
