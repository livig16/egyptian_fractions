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
  long odd = 1;   // denominator

  for (int i=0; i < ITERS; i++) {
    while (double(frac[0])/double(frac[1]) < 1.0/double(odd)) odd += 2;

    double mult = gcf(odd, frac[1]);
    frac[0] = frac[0]*long(double(odd)/mult) - long(double(frac[1])/mult);
    if (frac[0] == 0) {
      printf("%ld\n", odd);
      break;
    }
    frac[1] *= long(double(odd)/mult);
    printf("%ld  %ld  %ld\n", odd, frac[0], frac[1]); 
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

