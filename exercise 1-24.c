#include <stdio.h>
/*
	syntaxArray[0] => {}
	syntaxArray[1] => []
	syntaxArray[2] => ()
	syntaxArray[3] => ""
	syntaxArray[4] => ''
	syntaxArray[5] => \
	syntaxArray[6] =>
*/

#define INVALID 0
#define VALID 	1
#define NORMAL	2
#define UNKNOWN	3

int syntaxArray[6] = {0};
short state = VALID;
short characterType = NORMAL;

int main(void){
	char character;
	printf("Please enter code to check syntax (ctrl + a to stop):\n");
	while (((character = getchar()) != 1) && (state == VALID)){
		switch(character){
			case '{':
				syntaxArray[0]++;
				characterType = NORMAL;
				state = (characterType != UNKNOWN) ? VALID : INVALID;
				break;		
			case '}':
				syntaxArray[0]--;
				state = (syntaxArray[0] > 0 && characterType != UNKNOWN) ? VALID : INVALID;
				characterType = NORMAL;
			case '[':
				syntaxArray[1]++;
				state = (characterType != UNKNOWN) ? VALID : INVALID;
				characterType = NORMAL;
				break;
			case ']':
				syntaxArray[1]--;
				state = (syntaxArray[1] > 0 && characterType != UNKNOWN) ? VALID : INVALID;
				characterType = NORMAL;
				break;
			case '(':
				syntaxArray[2]++;
				state = (characterType != UNKNOWN) ? VALID : INVALID;
				break;
			case ')':
				syntaxArray[2]--;
				state = (syntaxArray[2] > 0 && characterType != UNKNOWN) ? VALID : INVALID;
				characterType = NORMAL;
			case '"':
				if (characterType != UNKNOWN){
					if (syntaxArray[3] % 2 == 0)
						syntaxArray[3]++;
					else
						syntaxArray[3]--;
				}
				else{
					syntaxArray[5]--;
				}
				break;
			case '\'':
				if (characterType != UNKNOWN){
					if (syntaxArray[4] % 2 == 0)
						syntaxArray[4]++;
					else
						syntaxArray[4]--;
				}
				else
					syntaxArray[5]--;
				characterType = NORMAL;
			case '\\':
				if (characterType == UNKNOWN){
					syntaxArray[5]--;
					characterType = NORMAL;
				}
				else{
					characterType = UNKNOWN;
					syntaxArray[5]++;
				}
				break;
			case '?':
			case 'a':
			case 'b':
			case 'f':
			case 'n':
			case 'r':
			case 't':
			case 'v':
				if (characterType == UNKNOWN)
					syntaxArray[5]--;
				characterType = NORMAL;
				break;
			default: 
				break;
		}
	}

	for(int i = 0; i < 6; i++){
		if (syntaxArray[i] != 0){
			printf("%s", "There's an syntax error\n");
			break;
		}
	}

}
