#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *previous;
}	s_node;

/*	Utils	*/
int		ischardigit(char var);
void	print_stacks(s_node *stack_a, s_node *stack_b);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *pointer);
int		ft_strcmp(char *str1, char *str2);
long long int	ft_atoi_long(const char *str);
/*	Error Handling	*/
void	error();
void	isbigger_handler(int argc, char *argv[]);
void	isduplic_handler(int argc, char *argv[]);
void	isnumber_handler(int argc, char *argv[]);
void	errors_handler(int argc, char *argv[]);
void	isfewarg_handler(int argc, char *argv[]);
/*	INIT Stack	*/
s_node	*init_stack();
void	populate(s_node *stack, int size, char *argv[]);
void	free_stack(s_node *stack);
#endif