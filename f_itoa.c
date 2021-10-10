#include "pushswap.h"

static int	power(long int n, int p)
{
	int	result;

	result = 1;
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

static int	len_int(long int n)
{
	int	counter;

	counter = 0;
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	counter++;
	return (counter);
}

static char	*int_to_str(long int n, int len, char *result, int counter)
{
	int	original;

	original = len + counter;
	while (len > 0)
	{
		result[counter] = ((n / power(10, len - 1)) + '0');
		n = (n % power(10, len - 1));
		counter++;
		len--;
	}
	result[original] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	long int	number;
	char		*result;
	size_t		len;
	int			counter;

	number = (long)n;
	counter = 0;
	if (n < 0)
	{
		number *= -1;
		len = len_int(number);
		result = (char *)malloc((len * sizeof(char)) + 2);
		if (result == 0)
			return (0);
		result[0] = '-';
		counter = 1;
	}
	else
	{
		len = len_int(number);
		result = (char *)malloc(len * sizeof(char) + 1);
	}
	if (result == 0)
		return (0);
	return (int_to_str(number, len, result, counter));
}
