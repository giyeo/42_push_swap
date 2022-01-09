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
	if(FIRST_NODE_A->index > SECOND_NODE_A->index)
	{
		if(SECOND_NODE_A->index > THIRD_NODE_A->index)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
		{
			if (THIRD_NODE_A->index > FIRST_NODE_A->index)
				sa(stack_a);
			else
				ra(stack_a);
		}
	}
	else
	{
		if(THIRD_NODE_A->index > FIRST_NODE_A->index)
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
	int min_index, min_position;
	int counter = 1;

	stack_a = stack_a->next;
	min_index = stack_a->index;
	
	while(stack_a->next)
	{
		if(stack_a->index <= min_index)
		{
			min_position = counter;
			min_index = stack_a->index;
		}
		stack_a = stack_a->next;
		counter++;
	}
	if(stack_a->index <= min_index)
	{
		min_position = counter;
		min_index = stack_a->index;
	}
	return (min_position);
}

int	ordered(s_node *stack_a)
{
	stack_a = stack_a->next;
	while(stack_a->next)
	{
		if(stack_a->index > stack_a->next->index)
			return 0;
		stack_a = stack_a->next;
	}
	return 1;
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
		exit(0);
	pb(stack_a, stack_b);
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
		pa(stack_a, stack_b);
}









int	find_next_position(s_node *stack_b)
{
	int max_index, max_position;
	int counter = 1;

	stack_b = stack_b->next;
	max_index = stack_b->index;
	
	while(stack_b->next)
	{
		if(stack_b->index >= max_index)
		{
			max_position = counter;
			max_index = stack_b->index;
		}
		stack_b = stack_b->next;
		counter++;
	}
	if(stack_b->index >= max_index)
	{
		max_position = counter;
		max_index = stack_b->index;
	}
	return (max_position);
}

void	sort_with_n(s_node *stack_a, s_node *stack_b, int len)
{
	//divide in n chunks until len of stack_a equal 0
	int chunk = 14;
	if (len > 450)
		chunk = 29;
    int up = (len / 2) + chunk;
    int down = (len / 2) - chunk;

    int last_up = len / 2;
    int last_down = len / 2;

    int counter = 0;
    while(stack_length(stack_a) > 0)
    {
        if (FIRST_NODE_A->index >= last_up && FIRST_NODE_A->index < up)
		{
			counter++;
			pb(stack_a, stack_b);
		}
        else if (FIRST_NODE_A->index >= down && FIRST_NODE_A->index < last_down)
        {
            counter++;
            pb(stack_a, stack_b);
            if(stack_length(stack_b) > 1)
                rb(stack_b);
        }
        else
            ra(stack_a);
        if (counter == chunk * 2)
        {
            last_up = up;
            last_down = down;
            down -= chunk;
            up += chunk;
			counter = 0;
        }
    }
	//bring back numbers in order
	while(stack_length(stack_b) != 0)
	{
		int len_b = stack_length(stack_b);
		int position = find_next_position(stack_b);
		int swap_signal = 0;
		//after half rrb
		if(position >= len_b / 2 + 1)
			while(stack_b->next->index != len_b - 1)
			{
				if(stack_b->next->index == len_b - 2)
				{
					pa(stack_a, stack_b);
					swap_signal = 1;
				}
				else
					rrb(stack_b);
			}
		//before half rb
		else
			while(stack_b->next->index != len_b - 1)
			{
				if(stack_b->next->index == len_b - 2)
				{
					pa(stack_a, stack_b);
					swap_signal = 1;
				}
				else
					rb(stack_b);
			}
		//put in a, swap if necessary
		pa(stack_a, stack_b);
		if(swap_signal)
			sa(stack_a);
	}
}

void sort(s_node *stack_a, s_node *stack_b)
{
	int len = stack_length(stack_a);

	if(more_than_one(stack_a))
		return ;
	if(ordered(stack_a))
		return ;
	if(len == 2)
		if (FIRST_NODE_A->index > SECOND_NODE_A->index)
			sa(stack_a);
	if(len == 3)
		sort_with_3(stack_a);
	else if (len <= 5)
		sort_with_5(stack_a, stack_b);
	else
		sort_with_n(stack_a, stack_b, len);
}
	