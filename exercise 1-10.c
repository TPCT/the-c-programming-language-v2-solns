#include <stdio.h>

/* 
exercise 1-10
	Write a program to copy its input to its output, replacing each
	tab by \ t, each backspace by \b, and each backslash by \ \. This makes tabs
	and backspaces visible in an unambiguous way
 */
int main(void){
	int currentCharacter;
	do{
		currentCharacter = getchar();
		if (currentCharacter == ' ')
			printf("\\b");
		else if(currentCharacter == '\t')
			printf("\\t");
		else if (currentCharacter == '\\')
			printf("\\\\");
		else
			putchar(currentCharacter);
	}while(currentCharacter != EOF);
	return 0;
}
