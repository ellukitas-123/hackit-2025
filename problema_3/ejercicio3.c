#include <stdio.h>
#include <stdlib.h>

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

int	in_set(char c, char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

int	ft_sizearr(char *str, char *set)
{
	int	sc;
	int	iw;

	sc = 1;
	iw = 0;
	while (*str)
	{
		if (!in_set(*str, set))
			iw = 0;
		if (!iw && in_set(*str, set))
		{
			iw = 1;
			sc += 1;
		}
		str++;
	}
	return (sc);
}

void	ft_strcpyupto(char *dest, char *src, int n)
{
	while (*src && n--)
		*dest++ = *src++;
	*dest = 0;
}

char	**ft_split(char *str, char *set)
{
	int		sc;
	int		c;
	int		c2;
	char	**strarr;
	char	*substr;

	sc = ft_sizearr(str, set);
	strarr = (char **)malloc((sc + 1) * sizeof(char *));
	strarr[sc] = NULL;
	c2 = 0;
	while (*str)
	{
		if (in_set(*str, set))
			str++;
		else
		{
			substr = str;
			c = 0;
			while (*str && !in_set(*str++, set))
				c++;
			strarr[c2] = malloc(c + 1);
			if (!strarr[c2])
				return (NULL);
			ft_strcpyupto(strarr[c2++], substr, c);
		}
	}
	return (strarr);
}
void	free_arr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		free(str[i])
		i++;
	}
	free(str);
}

int main()
{
	unsigned int casos;
	unsigned int size;
	unsigned int *arr;
	
	return 0;
}
