#include <stdio.h>

/* exercise 1-8 write a program to count blanks, tabs, and newlines. */
int main(void){
	char character;
	int counter = 0;
	printf("Please enter text to count blanks, tabs, and newlines:\n");
	do{
		character = getchar();
		if (character == ' ' || character == '\t' || character == '\n')
			++counter;
		if (character == '\n')
				printf("The number of spaces and newlines in text is: %d", counter);
	}while(character != EOF);
	return 0;
}
