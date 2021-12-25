#include "../pushswap.h"

void error()
{
	char *error = "Error";
	char temp = '\n';

	write(1, error, 5);
	write(1, &temp, 1);
	exit(-1);
}

void	isbigger_handler(int argc, char *argv[])
{
	int i;

	i = 1;
	while(i < argc)
	{
		if(ft_atoi_long(argv[i]) > 2147483647)
			error();
		if(ft_atoi_long(argv[i]) < -2147483648) 
			error();
		i++;
	}
}

void	isduplic_handler(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	while(i < argc - 1)
	{
		j = i + 1;
		while(j < argc)
			if(ft_strcmp(argv[i], argv[j++]))
				error();
		i++;
	}
}

void	isnumber_handler(int argc, char *argv[])
{
	int i;
	int j;
	int lenght;
	char *string;

	i = 0;
	while(i < argc - 1)
	{
		j = 0;
		string = argv[i++ + 1];
		lenght = strlen(string);
		while(j < lenght)
			if (!ischardigit(string[j++]))
				error();
	}
}

void	isfewarg_handler(int argc)
{
	if (argc == 1)
			error();
}