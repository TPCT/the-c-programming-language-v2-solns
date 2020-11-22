#include <stdio.h>

#define INVALID    0
#define VALID	   1

void squeeze(char s[], char delets[]);

int main(void){
	char str[] = "hello world i love python\n"
				 "do you love python?\n";
	char deletes[] = "hieouy";
	squeeze(str, deletes);
	printf("%s", str);
 	return 0;
}

void squeeze(char s[], char deletes[]){
	int i, j, k, state, currentChar;
	state = VALID;
	for (i = j = 0; s[i] != '\0'; i++){
		for (k = 0, currentChar = s[i]; deletes[k] != '\0'; k++){
			if (currentChar == deletes[k]){
				state = INVALID;
				break;
			}
		}
		if (state == VALID)
			s[j++] = s[i];
		else
			state = VALID;
	}
	s[j] = '\0';
}
