#define  PHYSICS                        HD
#define  DIMENSIONS                     2
#define  GEOMETRY                       CARTESIAN
#define  BODY_FORCE                     NO
#define  COOLING                        NO
#define  RECONSTRUCTION                 LINEAR
#define  TIME_STEPPING                  HANCOCK
#define  NTRACER                        0
#define  PARTICLES                      NO
#define  USER_DEF_PARAMETERS            3

/* -- physics dependent declarations -- */

#define  DUST_FLUID                     NO
#define  EOS                            ISOTHERMAL
#define  ENTROPY_SWITCH                 NO
#define  THERMAL_CONDUCTION             NO
#define  VISCOSITY                      NO
#define  ROTATING_FRAME                 NO

/* -- user-defined parameters (labels) -- */

#define  P_IN                           0
#define  P_OUT                          1
#define  GAMMA                          2

/* [Beg] user-defined constants (do not change this line) */

#define  LIMITER                        MC_LIM
#define  ADD_TURBULENCE                 YES

/* [End] user-defined constants (do not change this line) */