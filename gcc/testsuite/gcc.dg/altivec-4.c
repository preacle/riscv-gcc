/* { dg-do compile { target powerpc-*-* } } */
/* { dg-options "-maltivec -O0 -Wall" } */

#define vector __attribute__((vector_size(16)))

static int __attribute__((mode(V4SI))) x, y;

static vector signed int i,j,k;
static vector signed short s,t;
static vector signed char c,d;
static vector float f,g;

static vector unsigned char uc;

static vector signed int *pi;

static int int1, int2;

void
b()
{
  __builtin_altivec_vadduwm (x, y);

  /* Make sure the predicates accept correct argument types.  */
  
  k = __builtin_altivec_vcmpbfp_p (f, g);
  k = __builtin_altivec_vcmpeqfp_p (f, g);
  k = __builtin_altivec_vcmpequb_p (c, d);
  k = __builtin_altivec_vcmpequh_p (s, t);
  k = __builtin_altivec_vcmpequw_p (i, j);
  k = __builtin_altivec_vcmpgefp_p (f, g);
  k = __builtin_altivec_vcmpgtfp_p (f, g);
  k = __builtin_altivec_vcmpgtsb_p (c, d);
  k = __builtin_altivec_vcmpgtsh_p (s, t);
  k = __builtin_altivec_vcmpgtsw_p (i, j);
  k = __builtin_altivec_vcmpgtub_p (c, d);
  k = __builtin_altivec_vcmpgtuh_p (s, t);
  k = __builtin_altivec_vcmpgtuw_p (i, j);

  __builtin_altivec_mtvscr (i);
  __builtin_altivec_dssall ();
  s = __builtin_altivec_mfvscr ();
  __builtin_altivec_dss (3);

  __builtin_altivec_dst (pi, int1 + int2, 3);
  __builtin_altivec_dstst (pi, int1 + int2, 3);
  __builtin_altivec_dststt (pi, int1 + int2, 3);
  __builtin_altivec_dstt (pi, int1 + int2, 3);

  uc = (vector unsigned char) __builtin_altivec_lvsl (int1 + 69, pi);
  uc = (vector unsigned char) __builtin_altivec_lvsr (int1 + 69, pi);
}
