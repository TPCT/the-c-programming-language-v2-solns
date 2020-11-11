#include <stdio.h>

/* 
exercise 1-9
	Write a program to copy its input to its output, replacing each
	string of one or more blanks by a single blank
 */
int main(void){
	int currentCharacter, spaceCounter = 0;
	do{
		currentCharacter = getchar();
		if (currentCharacter == ' ' || currentCharacter == '\t')
			spaceCounter++;
		else
			spaceCounter = 0;
		if (spaceCounter > 1);
		else{
			putchar(currentCharacter);
		}
	}while(currentCharacter != EOF);
	return 0;
}
