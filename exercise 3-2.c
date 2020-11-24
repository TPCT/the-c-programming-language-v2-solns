#include <stdio.h>

#define STRING_SIZE 100

void escape(char s[], char t[]);

int main(void){
 	char s[STRING_SIZE] = "hello world i love python";
 	char t[STRING_SIZE] = "do	while\n";
 	escape(s, t);
 	printf("%s\n", s);
 	return 0;
}

void escape(char s[], char t[]){
	int i, j;
	for (i=0; s[i] != '\0'; i++);
	for (j=0; t[j] != '\0'; j++, i++){
		switch (t[j]){
			case '\n':
				s[i++] = '\\';
				s[i]   = 'n';
				break; 
			case '\t':
				s[i++] = '\\';
				s[i]   = 't';
				break;
			default:
				s[i] = t[j];
				break; 
		}
	}
	s[i] = '\0';
}
