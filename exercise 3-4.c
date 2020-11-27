#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define MAXLINE 	100

void itoa(int n, char s[]);
void reverse(char vector[],unsigned int length);

int main(void){
	char s[MAXLINE];
	itoa(INT_MIN, s);
	printf("%s\n", s);
	printf("\n");
	return 0;
}

void itoa(int n, char s[])
{
	unsigned int abs;
	int i, sign;
	i = 0;

	if ((sign = n) < 0)
		abs = -n;
	do {
		s[i++] = abs % 10 + '0';
	} while ((abs /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s, i);
}

void reverse(char vector[],unsigned int length){
	char temp;
	for (int i=0, j=length-1; i <= j; i++, j--){
		temp = vector[j];
		vector[j] = vector[i];
		vector[i] = temp;
	}
}
