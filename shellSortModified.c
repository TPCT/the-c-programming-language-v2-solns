#include <stdio.h>
#include <ctype.h>

void shellSort(int v[], unsigned int n);
void printArray(int v[], unsigned int n);

int main(void){
    int v[] = {9, 8, 3, 7, 5, 6, 4, 1};
	shellSort(v, 8);
	printArray(v, 8);
	return 0;
}

void shellSort(int v[], unsigned int n){
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /=2){
		for(i=0; i < n; i+=gap){
			for(j = n-1; j >=0 && i != j; j-=gap){
				if (v[i] > v[j]){
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
	}
}

void printArray(int v[], unsigned int n){
	printf("[");
	for (int i = 0; i < n-1; i++)
		printf("%d, ", v[i]);
	printf("%d]\n", v[n-1]);
}
