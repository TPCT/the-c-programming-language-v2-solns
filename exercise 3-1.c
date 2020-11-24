#include <stdio.h>

#define VECTOR_SIZE 10

int binSearch(int x, int v[], int n);

int main(void){
 	int v[VECTOR_SIZE] = {0, 1, 2, 3, 5, 7, 8, 10, 12, 14}, index;
 	index = binSearch(5, v, VECTOR_SIZE);
 	printf("%d\n", index);
 	return 0;
}

int binSearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high && x != v[mid]){
		mid = (high + low) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (x == v[mid])
		return mid;
	else
		return -1;
}
