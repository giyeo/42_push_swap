#include "pushswap.h"

int		print_stack(s_node *stack)
{
	char *temp;
	char s = ' ';

	temp = ft_itoa(stack->index);
	write(1, temp, ft_strlen(temp));
	write(1, &s, 1);
	free(temp);
	return (1);
}

void	print_stack_foot()
{
	char *sep;
	char *names;

	sep = "- -\n";
	names = "a b\n";
	write(1, sep, 4);
	write(1, names, 4);
	write(1, sep, 4);
}

void	print_stacks(s_node *stack_a, s_node *stack_b)
{
	int printed;
	char temp;
	
	temp = '\n';
	printed = 1;
	while(printed)
	{
		printed = 0;
		if(stack_a->next)
		{
			stack_a = stack_a->next;
			printed = print_stack(stack_a);
		}
		else
		{
			char *s = "  ";
			if(stack_b->next)
				write(1, s, 2);
		}
		if(stack_b->next)
		{
			stack_b = stack_b->next;
			printed = print_stack(stack_b);
		}
		if (printed)
			write(1, &temp, 1);
	}
	print_stack_foot();
}

int	print_command(char *name)
{
	static int count = 0;
	char new_line = '\n';
	write(1, name, ft_strlen(name));
	write(1, &new_line, 1);
	count++;
	return 0;
}