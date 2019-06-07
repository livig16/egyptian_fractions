// Algorithmic calculator of greedy fibonacci fraction expansions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double gcf(long, long);

int main(int argc, char* argv[]) {   // init num, init denom, iters

  if (argc<4) {
    printf("Please enter numerator, denominator, and maximum output terms.\n");
    return 1;
  }

  long frac[2];   // 1st element num 2nd denom
  frac[0] = atoi(argv[1]);
  frac[1] = atoi(argv[2]);

  const long ITERS = atoi(argv[3]);

  long local_fib[3];
  local_fib[0] = 2;
  local_fib[1] = 1;
  local_fib[2] = 2;

  for (int i=0; i < ITERS; i++) {
    while (double(frac[0])/double(frac[1]) < 1.0/double(local_fib[0])) {
      local_fib[0] = local_fib[1] + local_fib[2];
      local_fib[1] = local_fib[2];
      local_fib[2] = local_fib[0];
    }
    double mult = gcf(local_fib[0], frac[1]);
    frac[0] = frac[0]*long(double(local_fib[0])/mult) - long(double(frac[1])/mult);
    if (frac[0] == 0) {
      printf("%ld\n", local_fib[0]);
      break;
    }
    frac[1] *= long(double(local_fib[0])/mult);
    double div = gcf(frac[0], frac[1]);
    frac[0] = long(double(frac[0]) / div);
    frac[1] = long(double(frac[1]) / div);

    printf("%ld  %ld  %ld\n", local_fib[0], frac[0], frac[1]); 
  }

  return 0;
}

double gcf(long num1, long num2) {

  int ans = 1;
  long least;
  if (num1 < num2) least = num1;
  else if (num2 < num1) least = num2;
  else return num1;

  for (int i=1; i<=least; i++) {
    if (num1%i == 0 && num2%i == 0) ans = i;
  }
  return double(ans);
}

