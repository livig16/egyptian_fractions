// egyptian fraction hackery
// DE, 16 May 1992
//
// Implements Stewart's brute-force algorithm for finding k-term egyptian frax.
// usage: a.out numerator denominator nterms
// only uses 32-bit integer arithmetic; doesnt check for overflows.

#include "Streams-master/source/Stream.h"

typedef unsigned long num;

num gcd(num a, num b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

class rat {
 public:
    num x, y;
    rat() { ; }
    rat(num xx, num yy) {
	num d = gcd(xx, yy);
	x = xx/d; y = yy/d;
    }
};

rat operator-(rat a, rat b)
{
    rat c(a.x * b.y - b.x * a.y, a.y * b.y);
    return c;
}

ostream& operator<< (ostream & o, rat r) { return o << r.x << "/" << r.y; }

void fill(rat g, rat* r, int n, int i, num m)
{
    if (i == n) {
	if (g.x == 0) {
	    for (int j = 0; j < n; j++)
		cout << r[j] << " ";
	    cout << "\n";
	}
	return;
    }

    if (g.x == 0) return;

    num j = (g.y + g.x - 1) / g.x;
    num k = j;
    if (k < m) k = m;
    while (k <= j*(n-i)) {
	r[i].x = 1;
	r[i].y = k;
	fill(g - r[i], r, n, i+1, k+1);
	k++;
    }
}

extern "C" int atoi(char *);

int main(int ac, char **av)
{
    rat goal(atoi(av[1]), atoi(av[2]));
    int nterms = atoi(av[3]);
    rat terms[nterms];
    fill(goal, terms, nterms, 0, 2);
}
