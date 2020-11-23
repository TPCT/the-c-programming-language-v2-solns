#include <stdio.h>

unsigned setbits(unsigned x, unsigned short p, unsigned short n, unsigned y);
void bin(unsigned n, unsigned short l);

int main(void){
	int x = 0b10101111;
	int y = 0b11101101;
	bin(setbits(x, 4, 3, y), 8);
 	return 0;
}

unsigned setbits(unsigned x, unsigned short p, unsigned short n, unsigned y){
	y = (y & ~(~0 << n)) << p - n;
	x = (x & ~(~(~0 << n) << p - n));
	return x | y;
}

void bin(unsigned n, unsigned short l)
{
    unsigned i;
    for (i = 1 << (l-1); i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    putchar('\n');
}
