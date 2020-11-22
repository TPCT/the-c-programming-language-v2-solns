#include <stdio.h>

int any(char s1[], char s2[]);

int main(void){
	char str[] = "hello world i love python\n"
				 "do you love python?\n";
	char finds[] = "x";
	printf("%d\n", any(str, finds));
 	return 0;
}

int any(char s1[], char s2[]){
	for (int i = 0, j; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	}
	return -1;
}
