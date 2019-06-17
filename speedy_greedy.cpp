// Olivia Goodrich
// Algorithmic calculator for greedy fraction decompositions (more efficient than greedy.cpp)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long next_denom(long k, long n);
double gcf(long, long);

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Enter k, n, and maximum terms.\n");
    return 1;
  }
  long k = atoi(argv[1]);
  long n = atoi(argv[2]);
  int MAX_TERMS = atoi(argv[3]);

  long denom;
  double fact;
  for (int i=0; i<MAX_TERMS; i++) {
    denom = next_denom(k,n);
    k = k*denom - n;
    if (k == 0) {
      printf("%ld\n", denom);
      break;
    }
    fact = gcf(k, n*denom);
    k = long(double(k) / fact);
    n = long(n*(double(denom)/fact));

    printf("%ld  %ld  %ld\n", denom, k, n);
  }
  return 0;
}

long next_denom(long k, long n) {
  if (k==1) return n;
  else return long(double(n)/double(k)) + 1;
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
