#include <stdio.h>

unsigned int k_ocurrence(int search, int k, int *arr, int size)
{
	int i = 0;
	int ocurrences = 0;
	while (i < size && ocurrences < k)
	{
		ocurrences += arr[i] == search ? 1 : 0;
		i++;
	}

	return ocurrences == k ? i + 1 : 0;
}


int main()
{
	unsigned int casos;
	unsigned int size;
	unsigned int *arr;

	return 0;
}
