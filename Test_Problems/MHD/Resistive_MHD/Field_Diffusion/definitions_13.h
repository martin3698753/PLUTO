#define  PHYSICS                        MHD
#define  DIMENSIONS                     3
#define  GEOMETRY                       SPHERICAL
#define  BODY_FORCE                     NO
#define  COOLING                        NO
#define  RECONSTRUCTION                 LINEAR
#define  TIME_STEPPING                  RK2
#define  NTRACER                        0
#define  PARTICLES                      NO
#define  USER_DEF_PARAMETERS            3

/* -- physics dependent declarations -- */

#define  EOS                            IDEAL
#define  ENTROPY_SWITCH                 NO
#define  DIVB_CONTROL                   CONSTRAINED_TRANSPORT
#define  BACKGROUND_FIELD               NO
#define  AMBIPOLAR_DIFFUSION            NO
#define  RESISTIVITY                    SUPER_TIME_STEPPING
#define  HALL_MHD                       NO
#define  THERMAL_CONDUCTION             NO
#define  VISCOSITY                      NO
#define  ROTATING_FRAME                 NO

/* -- user-defined parameters (labels) -- */

#define  ETAX                           0
#define  ETAY                           1
#define  ETAZ                           2

/* [Beg] user-defined constants (do not change this line) */

#define  INTERNAL_BOUNDARY              YES
#define  LIMITER                        VANLEER_LIM

/* [End] user-defined constants (do not change this line) */
