#include <stdio.h>

/* 
Exercise 1-12. 
	Write a program that prints its input one word per line. 
*/

int main(void){
	int currentCharacter, spaceCounter = 0;
	while ((currentCharacter = getchar()) != EOF){
		if (currentCharacter == '\n' || currentCharacter == '\t' || currentCharacter == ' '){
			spaceCounter++;
			if (spaceCounter == 1)
				putchar('\n');
		}
		else{
			putchar(currentCharacter);
			spaceCounter = 0;
		}
	}
	return 0;
}
