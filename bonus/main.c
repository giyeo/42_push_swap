#include <stdio.h> //printf
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <fcntl.h> //open
#include <unistd.h> //close
#include <stdlib.h>
#include "get_next_line.h"
#include "../push_swap.h"

void	exec_command(char *line, t_node *stack_a, t_node *stack_b)
{
	if(ft_strcmp(line, "sa"))
		sa_checker(stack_a);
	else if(ft_strcmp(line, "sb"))
		sb_checker(stack_b);
	else if(ft_strcmp(line, "ss"))
		ss_checker(stack_a, stack_b);
	else if(ft_strcmp(line, "pa"))
		pa_checker(stack_a, stack_b);
	else if(ft_strcmp(line, "pb"))
		pb_checker(stack_a, stack_b);
	else if(ft_strcmp(line, "ra"))
		ra_checker(stack_a);
	else if(ft_strcmp(line, "rb"))
		rb_checker(stack_b);
	else if(ft_strcmp(line, "rr"))
		rr_checker(stack_a, stack_b);
	else if(ft_strcmp(line, "rra"))
		rra_checker(stack_a);
	else if(ft_strcmp(line, "rrb"))
		rrb_checker(stack_b);
	else if(ft_strcmp(line, "rrr"))
		rrr_checker(stack_a, stack_b);
	else
		printf("error");
}

void	populate_checker(t_node *stack, int size, char *argv[])
{
	int	i;

	i = 0;
	stack->next = (t_node *)malloc(sizeof(t_node));
	stack->next->previous = stack;
	stack->previous = NULL;
	stack = stack->next;
	while (i < size - 2)
	{
		stack->next = (t_node *)malloc(sizeof(t_node));
		stack->next->previous = stack;
		stack->value = atoi(argv[i + 1]);
		stack = stack->next;
		i++;
	}
	stack->value = atoi(argv[i + 1]);
	stack->next = NULL;
}

void print_stack(t_node *stack)
{
	stack = stack->next;
	while(stack->next)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("%d\n", stack->value);
	printf("--\n");
}

int main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
    char	*line;
    int		i;

	i = 1;

	stack_a = init_stack();
	stack_b = init_stack();
	populate_checker(stack_a, argc, argv);
	print_stack(stack_a);
	while(i)
	{
		i = get_next_line(0, &line);
		if(!i)
		{
			free(line);
			break;
		}
		exec_command(line, stack_a, stack_b);
		printf("%s\n", line);
		print_stack(stack_a);
		free(line);
	}
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}