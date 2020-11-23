#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned short n);
unsigned int wordLength(void);
void bin(unsigned n, unsigned short l);

int main(void){
	unsigned int x = 0xf0f0f0f0;
	bin(x, 32);
	bin(x << 3, 32);
	bin(rightrot(x, 3), 32);
	return 0;
}

unsigned int rightrot(unsigned int x, unsigned short n){
	unsigned int word_length;
	word_length = wordLength();
	return (x << n) | x >> word_length - n;
}

unsigned int wordLength(void){
	unsigned int word = (unsigned int) ~0;
	int wordLength = 0;
	for(; (word & 1) > 0; wordLength++)
		word >>= 1;
	return wordLength;
}

void bin(unsigned n, unsigned short l)
{
    unsigned i;
    for (i = 1 << (l-1); i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    putchar('\n');
}
