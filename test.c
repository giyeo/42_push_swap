#include <stdio.h>
#include <string.h>
#include "./libft/atoi.c"
int main(int argc, char *argv[])
{
    int len = ft_atoi(argv[1]);
    int chunk = 20;

    int up = (len / 2) + chunk;
    int down = (len / 2) - chunk;

    int last_up = len / 2;
    int last_down = len / 2;

    int counter = 0;
    while(last_up <= len || last_down >= 0)
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
        if (counter % (chunk * 2) == 0)
        {
            last_up = up;
            last_down = down;
            down -= chunk;
            up += chunk;
        }
    }
    return 0;
}


while(stack_length(stack_a) > 0)
	{
		while(counter < 40)
		{
			if (FIRST_NODE_A->index >= 40 && FIRST_NODE_A->index < 60)
			{
				counter++;
				pb(stack_a, stack_b);
			}
			else if (FIRST_NODE_A->index >= 20 && FIRST_NODE_A->index < 40)
			{
				counter++;
				pb(stack_a, stack_b);
				if(stack_length(stack_b) > 1)
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		while(counter < 80)
		{
			if (FIRST_NODE_A->index >= 60 && FIRST_NODE_A->index < 80)
			{
				counter++;
				pb(stack_a, stack_b);
			}
			else if (FIRST_NODE_A->index >= 0 && FIRST_NODE_A->index < 20)
			{
				counter++;
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			else
				ra(stack_a);
		}
		while(stack_length(stack_a) > 0)
			pb(stack_a, stack_b);
	}