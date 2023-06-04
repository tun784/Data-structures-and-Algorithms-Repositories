#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void readfromfile(int* array, int *n,char *file_name) {
	FILE* f;
	f = fopen(file_name, "r");
	if (f == NULL) {
		printf("File does not exists \n");
		return ;
	}
	fscanf(f, "%d", *n);
	for (int i = 0; i < *n; i++)
		fscanf(f, "%d", &array[i]);
	fclose(f);
}
void printarray(int array[], int n) {
	printf("%d elements of array are: ",n);
	for (int i = 0; i < n; i++)
		printf("%d, ", array[i]);
}
int main() {
	int array[10], n=0;
	char file_name[] = "Input.txt";
	readfromfile(&array,&n,&file_name);
	printarray(&array,&n);
	_getch();
	return 0;
}