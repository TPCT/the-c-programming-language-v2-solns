#include <stdio.h>

/* 
Exercise 1-13. 
	Write a program to print a histogram of the lengths of words in
	its input. It is easy to draw the histogram with the bars horizontal; a vertical
	orientation is more challenging.
*/

#define END_CHARACTER    126
#define START_CHARACTER	  33
#define CHARACTERS_COUNT  94
#define HISTOGRAM_WIDTH   20
#define QUIT_KEYCODE   	  24
#define IN 				   1
#define OUT 			   0

int main(void){
	char histogramFilledCells;
	int histogram[CHARACTERS_COUNT], currentCharacter;

	for (unsigned short i = 0; i < CHARACTERS_COUNT; i++){
		histogram[i] = 0;
	}
	

	while((currentCharacter = getchar()) != QUIT_KEYCODE){
		if (START_CHARACTER <= currentCharacter <= END_CHARACTER)
			histogram[currentCharacter - START_CHARACTER]++;
	}

	for (unsigned short i = 0; i < CHARACTERS_COUNT; i++){
		printf("Character %c (%03d) ->  [", START_CHARACTER + i, START_CHARACTER + i);
		histogramFilledCells = histogram[i] / HISTOGRAM_WIDTH;
		for (char i = 0; i < HISTOGRAM_WIDTH; i++){
			if (i < histogramFilledCells)
				printf("|");
			else
				printf("_");
		}
		printf("][%-d]\n", histogram[i]);
	}

	return 0;
}
