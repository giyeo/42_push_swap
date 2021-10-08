#include "pushswap.h"

int	ischardigit(char var)
{
	if ((var >= 48 && var <= 57) || var == 45 || var == 43)
		return 1;
	return 0;
}

size_t	ft_strlen(const char *pointer)
{
	size_t	counter;

	counter = 0;
	while (pointer[counter] != '\0')
		counter++;
	return (counter);
}

int ft_strcmp(char *str1, char *str2)
{
	int size;
	int i;

	i = 0;
	size = ft_strlen(str1);
	if(size != ft_strlen(str2))
		return (0);
	while(i < size)
		if(str1[i] != str2[i++])
			return (0);
	return (1);
}