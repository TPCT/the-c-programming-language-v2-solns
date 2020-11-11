#include <stdio.h>

/* 
Exercise 1-13. 
	Write a program to print a histogram of the lengths of words in
	its input. It is easy to draw the histogram with the bars horizontal; a vertical
	orientation is more challenging.
*/

#define MAXWORDLENGTH  20
#define HISTOGRAMWIDTH 20
#define QUIT_KEYCODE   24
#define IN 				1
#define OUT 			0

int main(void){
	char histogramFilledCells;
	int histogram[MAXWORDLENGTH], currentCharacter, wordLength;

	wordLength = 0;
	state = OUT;

	for (unsigned short i = 0; i < MAXWORDLENGTH; i++){
		histogram[i] = 0;
	}
	

	while((currentCharacter = getchar()) != QUIT_KEYCODE){
		if (currentCharacter == '\n' || currentCharacter == ' ' || currentCharacter == '\t'){
			if (state != OUT)
				histogram[wordLength]++;
			wordLength = 0;
			histogram[wordLength]++;
			state = OUT;
		}else{
			wordLength++;
			state = IN;
		}
	}

	for (unsigned short i = 0; i < MAXWORDLENGTH; i++){
		printf("Word Of Length: %3d ->  [", i);
		histogramFilledCells = histogram[i] % HISTOGRAMWIDTH;
		for (char i = 0; i < HISTOGRAMWIDTH; i++){
			if (i < histogramFilledCells)
				printf("|");
			else
				printf("_");
		}
		printf("][%d]\n", histogram[i]);
	}

	return 0;
}
