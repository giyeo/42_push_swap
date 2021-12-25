#include "pushswap.h"

int	stack_length(s_node *stack)
{
	int counter;

	counter = 0;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	sort_with_3(s_node *stack_a)
{
	if(FIRST_NODE_A->value > SECOND_NODE_A->value)
	{
		if(SECOND_NODE_A->value > THIRD_NODE_A->value)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
		{
			if (THIRD_NODE_A->value > FIRST_NODE_A->value)
				sa(stack_a);
			else
				ra(stack_a);
		}
	}
	else
	{
		if(THIRD_NODE_A->value > FIRST_NODE_A->value)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

int	find_lower(s_node *stack_a)
{
	int min_value, min_position;
	int counter = 1;

	stack_a = stack_a->next;
	min_value = stack_a->value;
	
	while(stack_a->next)
	{
		if(stack_a->value <= min_value)
		{
			min_position = counter;
			min_value = stack_a->value;
		}
		stack_a = stack_a->next;
		counter++;
	}
	if(stack_a->value <= min_value)
	{
		min_position = counter;
		min_value = stack_a->value;
	}
	return (min_position);
}

int	ordered(s_node *stack_a)
{
	stack_a = stack_a->next;
	while(stack_a->next)
	{
		if(stack_a->value > stack_a->next->value)
			return 0;
		stack_a = stack_a->next;
	}
	return 1;
}

void	in_order(s_node *stack_a, s_node *stack_b)
{
	print_stacks(stack_a, stack_b);

	char *str = ft_itoa(print_command("count"));
	FILE *fp;
	fp = fopen("./output.txt","a");
	fputs(str, fp);
	fputc('\n', fp);
	free(str);
	fclose(fp);
	exit(0);
}

void	remove_lower(s_node *stack_a, s_node *stack_b, int len)
{
	int i = 0;
	int lower_number_position;

	lower_number_position = find_lower(stack_a);
	if(lower_number_position >= len / 2 + 1)
		while(i++ < len - (lower_number_position - 1))
			rra(stack_a);
	else
		while(i++ < lower_number_position - 1)
			ra(stack_a);
	if(ordered(stack_a))
		in_order(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_with_5(s_node *stack_a, s_node *stack_b)
{
	int len = stack_length(stack_a);
	int len2 = len;
	while(len-- > 3)
		remove_lower(stack_a, stack_b, stack_length(stack_a));
	if(!ordered(stack_a))
		sort_with_3(stack_a);
	while(len2-- > 3)
		pb(stack_a, stack_b);
}

void	sort_snake(s_node *stack_a, s_node *stack_b)
{
	//bring_up_by_index
}

void sort(s_node *stack_a, s_node *stack_b)
{
	int len = stack_length(stack_a);

	print_stacks(stack_a, stack_b);

	if(more_than_one(stack_a))
		return ;
	if(ordered(stack_a))
	{
		print_stacks(stack_a, stack_b);
		return ;
	}
	if(len == 2)
		if (FIRST_NODE_A->value > SECOND_NODE_A->value)
			sa(stack_a);
	if(len == 3)
		sort_with_3(stack_a);
	else if (len <= 5)
		sort_with_5(stack_a, stack_b);
	else
		sort_snake(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
}