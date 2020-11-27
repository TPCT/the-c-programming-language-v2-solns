#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define MAXLINE 100

void itob(int n, char s[], unsigned char b);
void reverse(char vector[],unsigned int length);

int main(void){
	char s[MAXLINE];
	itob(15, s, 16);
	printf("%s\n", s);
	return 0;
}

void itob(int n, char s[], unsigned char b){
	unsigned char digit;
	unsigned int abs;
	int i, sign;
	i = 0;

	if((sign = n) < 0)
		abs = -n;
	else
		abs = n;

	do{
		digit = abs % b;
		s[i++] = (0 <= digit && digit <= 9) ? digit + '0' : (digit - 10) + 'a';
	} while((abs /= b) > 0);

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
