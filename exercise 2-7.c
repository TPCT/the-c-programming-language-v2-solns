#include <stdio.h>

unsigned invert(unsigned x, unsigned short p, unsigned short n);
void bin(unsigned n, unsigned short l);

int main(void){
	int x = 0b10101111;
	bin(invert(x, 4, 3), 8);
 	return 0;
}

unsigned invert(unsigned x, unsigned short p, unsigned short n){
	return ((x & ~(~(~0 << n) << p - n))) | ((((~x >> p - n) & ~(~0 << n)) & ~(~0 << n)) << p - n);
}

void bin(unsigned n, unsigned short l)
{
    unsigned i;
    for (i = 1 << (l-1); i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    putchar('\n');
}
