#include <stdio.h>

#define STRING_SIZE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void){
 	char s[STRING_SIZE] = "hello world i love python";
 	char t[STRING_SIZE] = "do	while\n";
 	char x[STRING_SIZE];
 	escape(s, t);
 	unescape(x, s);
 	printf("%s\n", s);
 	printf("%s\n", x);
 	return 0;
}

void unescape(char s[], char t[]){
	int i, j;

	for(i=0; s[i] != '\0'; i++);
	for(j=0; t[j] != '\0'; j++, i++){
		switch(t[j]){
			case '\\':
				if (t[j+1] == 'n'){
					s[i] = '\n';
					j++;
				}
				else if (t[j+1] == 't'){
					s[i] = '\t';
					j++;
				}
				else
					s[i] = '\\';
				break;
			default:
				s[i] = t[j];
				break;
		}
	}

	s[i] = '\0';
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
