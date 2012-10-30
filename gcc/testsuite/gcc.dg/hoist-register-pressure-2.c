/* { dg-options "-Os -fdump-rtl-hoist" }  */
/* { dg-final { scan-rtl-dump "PRE/HOIST: end of bb .* copying expression" "hoist" } } */

#define BUF 100
int a[BUF];

void com (int);
void bar (int);

int foo (int x, int y, int z)
{
  /* "x+y" won't be hoisted if "-fira-hoist-pressure" is disabled,
     because its rtx_cost is too small.  */
  if (z)
    {
      a[1] = a[0];
      a[2] = a[1];
      a[3] = a[3];
      a[4] = a[5];
      a[5] = a[7];
      a[6] = a[11];
      a[7] = a[13];
      a[8] = a[17];
      com (x+y);
    }
  else
    {
      bar (x+y);
    }

  return 0;
}
