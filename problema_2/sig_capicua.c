#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int es_capicua(unsigned long long x)
{
	unsigned long long y;
	unsigned long long z;

	z = x;
	y = 0;
	while (z > 0)
	{
		y = y * 10 + z % 10;
		z /= 10;
	}
	return (x == y);
}

int *num2arr(unsigned long long n, int *size)
{
	unsigned long long n2;
	int div;
	int *out;

	n2 = n;
	div = 0;
	while (n2 > 0)
	{
		n2 /= 10;
		div++;
	}
	*size = div;
	out = (int *)malloc(div * sizeof(int));
	while (div > 0)
	{
		out[--div] = n % 10;
		n /= 10;
	}
	return (out);
}

unsigned long long arr2num(int *arr, int size)
{
	unsigned long long out;
	int i;

	out = 0;
	i = size;
	while (i > 0)
		out = out * 10 + arr[--i];
	return (out);
}

unsigned long long handle_nines(unsigned long long n, int *arr, int size)
{
	int all_nines;
	int i;

	i = 0;
	all_nines = 1;
	while (i < size)
	{
		if (arr[i++] != 9)
		{
			all_nines = 0;
			break;
		}
	}
	if (all_nines)
	{
		return (n + 2);
	}
	return (0);
}

unsigned long long sig_capicua(unsigned long long n)
{
	unsigned long long all_nines;
	int rbigger;
	unsigned long long result;
	int size;
	int *arr;
	int mid;
	int r;
	int l;
	int i;

	if (es_capicua(n))
		return (n);
	if (n <= 0)
		return (1);
	arr = num2arr(n, &size);
	all_nines = handle_nines(n, arr, size);

	if (all_nines != 0)
	{
		free(arr);
		return (all_nines);
	}

	mid = (size % 2 == 0) ? size / 2 - 1 : size / 2;
	r = mid;
	l = mid;

	while (r >= 0 && arr[r] == arr[l])
	{
		r--;
		l++;
	}

	if (size == 2)
	{
		r = 0;
		l = 1;
	}

	rbigger = (r < 0 || arr[r] > arr[l]) ? 1 : 0;

	if (rbigger)
	{
		i = 0;
		while (i <= size / 2)
		{
			arr[size - 1 - i] = arr[i];
			i++;
		}
	}
	else
	{
		r = mid;
		l = mid + 1;
		if (size % 2 == 1)
		{
			arr[mid] += 1;
		}
		else
		{
			arr[mid] += 1;
			arr[mid + 1] = arr[mid];
		}
		while (r >= 0 && arr[r] == 10)
		{
			arr[r] = 0;
			if (r > 0)
				arr[r - 1] += 1;
			r--;
		}
		i = 0;
		while (i < size / 2)
		{
			arr[size - 1 - i] = arr[i];
			i++;
		}
		result = arr2num(arr, size);
		free(arr);
		return result;
	}
	result = arr2num(arr, size);
	free(arr);
	return (result);
}

int main()
{
	unsigned long long casos;
	unsigned long long n;
	unsigned long long i;

	scanf("%llu", &casos);
	getchar();
	i = 0;
	while (i < casos)
	{
		scanf("%llu", &n);
		getchar();
		if (es_capicua(n))
			printf("%llu\n", sig_capicua(n + 1) - n);
		else
			printf("%llu\n", sig_capicua(n) - n);
		i++;
	}
	return (0);
}
