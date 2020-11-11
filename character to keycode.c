#include <stdio.h>

int main(void){
	int currentCharacter, lastCharacter = EOF;
	short firstTime = 1;
	while (currentCharacter != EOF || firstTime){
		if (currentCharacter == '\n' || firstTime){
			if (!firstTime && lastCharacter != EOF)
				printf("The Entered Charachter Code is: %d\n", lastCharacter);
			printf("Please enter Character to get it's keycode: ");
			lastCharacter = EOF;
		}else{
			lastCharacter = currentCharacter;
		}
		firstTime = 0;
		currentCharacter = getchar();
	}
	printf("\n");
	return 0;
}
