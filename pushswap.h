#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define FIRST_NODE_A stack_a->next
#define FIRST_NODE_B stack_b->next
#define SECOND_NODE_A stack_a->next->next
#define SECOND_NODE_B stack_b->next->next
#define THIRD_NODE_A stack_a->next->next->next
#define LAST_NODE_A last_a
#define LAST_NODE_B last_b

typedef struct node
{
	int value;
	int index;
	struct node *next;
	struct node *previous;
}	s_node;

/*	Utils	*/
int		ischardigit(char var);
int		print_command(char *name);
int		print_stack(s_node *stack);
void	print_stacks(s_node *stack_a, s_node *stack_b);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *pointer);
int		ft_strcmp(char *str1, char *str2);
long long int	ft_atoi_long(const char *str);
/*	Error Handling	*/
void	error();
void	isbigger_handler(int argc, char *argv[]);
void	isduplic_handler(int argc, char *argv[]);
void	isnumber_handler(int argc, char *argv[]);
void	errors_handler(int argc, char *argv[]);
void	isfewarg_handler(int argc);
/*	INIT Stack	*/
s_node	*init_stack();
void	populate(s_node *stack, int size, char *argv[], int *indexator);
void	free_stack(s_node *stack);
/*	LLists Utils	*/
int		more_than_one(s_node *stack);
/*	COMMANDS	*/
void	sa(s_node *stack);
void	sb(s_node *stack);
void	ss(s_node *stack_a, s_node *stack_b);
void	pa(s_node *stack_a, s_node *stack_b);
void	pb(s_node *stack_a, s_node *stack_b);
void	ra(s_node *stack);
void	rb(s_node *stack);
void	rr(s_node *stack_a, s_node *stack_b);
void	rra(s_node *stack);
void	rrb(s_node *stack);
void	rrr(s_node *stack_a, s_node *stack_b);
/*	Sorting		*/
void	sort(s_node *stack_a, s_node *stack_b);
int		find_lower(s_node *stack_a);
int		*index_it(int argc, char *argv[]);
int		stack_length(s_node *stack);
#endif