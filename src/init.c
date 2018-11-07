#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
Check these declarations against the C/Fortran source code.
*/

/* .C calls */
extern void downdate1(void *, void *, void *, void *, void *, void *);
extern void downdate2(void *, void *, void *, void *, void *);
extern void maketri2(void *, void *, void *, void *, void *, void *, void *);
extern void maketri3(void *, void *, void *, void *, void *, void *, void *, void *);
extern void maketri4(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void update1(void *, void *, void *, void *, void *);
extern void update2(void *, void *, void *, void *, void *, void *, void *);

static const R_CMethodDef CEntries[] = {
  {"downdate1", (DL_FUNC) &downdate1,  6},
  {"downdate2", (DL_FUNC) &downdate2,  5},
  {"maketri2",  (DL_FUNC) &maketri2,   7},
  {"maketri3",  (DL_FUNC) &maketri3,   8},
  {"maketri4",  (DL_FUNC) &maketri4,  10},
  {"update1",   (DL_FUNC) &update1,    5},
  {"update2",   (DL_FUNC) &update2,    7},
  {NULL, NULL, 0}
};

void R_init_genlasso(DllInfo *dll)
{
  R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}