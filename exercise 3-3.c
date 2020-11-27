#include <stdio.h>
#include <ctype.h>

#define MAXLINE 	100

void expand(int s1[], int s2[]);

int main(void){
	int s1[] = {'a', '-', 'b', '-', 'c', 0};
	int s2[MAXLINE];
	expand(s1, s2);
	for(int i =0; s2[i] != '\0'; i++)
		printf("%c", s2[i]);
	printf("\n");
	return 0;
}

void expand(int s1[], int s2[]){

	int startCharacter, endCharacter, currentCharacter, j, i;
	startCharacter = endCharacter = 0;

	for (i = j = 0; ((currentCharacter = s1[i]) != '\0') && j < MAXLINE; i++, j++){
		s2[j] = currentCharacter;
		if (isdigit(currentCharacter) || isalpha(currentCharacter)){
			startCharacter = currentCharacter;
		}else if (currentCharacter == '-'){
			if (startCharacter){
				endCharacter = isdigit(s1[i+1]) || isalpha(s1[i+1]) ? s1[i+1] : 0;
				s2[j] = endCharacter ? endCharacter : currentCharacter;
				if (startCharacter < endCharacter){
					for(startCharacter += 1; (startCharacter < endCharacter); startCharacter++, j++)
						s2[j] = startCharacter;
					--j;
				}
				else{
					s2[++j] = endCharacter;
				}
				startCharacter = 0;
				endCharacter = 0;
			}
		}
	}
	s2[j] = 0;
}
