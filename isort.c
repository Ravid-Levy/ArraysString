#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void shift_element(int *arr, int i)
{
	for (int j = i; j > 0; j--)
		*(arr + j) = *(arr + j - 1);
}
void insertion_sort(int *arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = *(arr + i);
		j = i - 1;
		while (j >= 0 && *(arr + j) > key)
		{
			*(arr + j + 1) = *(arr + j);
			j = j - 1;
		}
		*(arr + j + 1) = key;
	}
}
void print_array(int *arr, int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	printf("%d,", *(arr + i));
	printf("%d\n", *(arr + i));
}

int main()
{
	int *arr = (int *)calloc(SIZE, sizeof(int *));
	for (int i = 0; i < SIZE; i++)
		scanf("%d", arr + i);
	insertion_sort(arr, SIZE);
	print_array(arr, SIZE);
	free(arr);
	return 0;
}
