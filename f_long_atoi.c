#include "pushswap.h"

long long int	ft_isdigit(long long int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}

static long long int	ft_isspace(long long int chr)
{
	if (chr == '\n' || chr == '\t' || chr == '\v'
		|| chr == '\r' || chr == '\f' || chr == ' ')
		return (1);
	else
		return (0);
}

static long long int	calc_atoi(const char *str, long long int len, long long int counter)
{
	long long int	result;

	result = 0;
	while (counter < len)
	{
		if (ft_isdigit(str[counter]))
		{
			result = (result * 10) + (str[counter] - '0');
			counter++;
		}
		else
			return (result);
	}
	return (result);
}

long long int	ft_atoi_long(const char *str)
{
	long long int		len;
	long long int		final_result;
	long long int		counter;

	counter = 0;
	len = ft_strlen(str);
	while (ft_isspace(str[counter]))
		counter++;
	if (str[counter] == '+')
		final_result = calc_atoi(str, len, counter + 1);
	else if (str[counter] == '-')
		final_result = calc_atoi(str, len, counter + 1) * -1;
	else
		final_result = calc_atoi(str, len, counter);
	return (final_result);
}