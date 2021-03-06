/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:38:24 by rpaulino          #+#    #+#             */
/*   Updated: 2022/01/15 14:07:31 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
	struct node	*previous;
}	t_node;

typedef struct index
{
	int	value;
	int	index;
}	t_index;

typedef struct sort
{
	int	up;
	int	down;
	int	last_up;
	int	last_down;
	int	len;
}	t_sort;

/*	Utils	*/
int				ischardigit(char var);
int				print_command(char *name);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *pointer);
int				ft_strcmp(char *str1, char *str2);
long long int	ft_atoi_long(const char *str);
/*	Error Handling	*/
void			error(void);
void			isbigger_handler(int argc, char *argv[]);
void			isduplic_handler(int argc, char *argv[]);
void			isnumber_handler(int argc, char *argv[]);
void			errors_handler(int argc, char *argv[]);
void			isfewarg_handler(int argc);
void			error(void);
/*	INIT Stack	*/
t_node			*init_stack(void);
void			populate(t_node *stack, int size, char *argv[], int *indexator);
void			free_stack(t_node *stack);
/*	LLists Utils	*/
int				more_than_one(t_node *stack);
/*	COMMANDS	*/
void			sa(t_node *stack);
void			sb(t_node *stack);
void			ss(t_node *stack_a, t_node *stack_b);
void			pa(t_node *stack_a, t_node *stack_b);
void			pb(t_node *stack_a, t_node *stack_b);
void			ra(t_node *stack);
void			rb(t_node *stack);
void			rr(t_node *stack_a, t_node *stack_b);
void			rra(t_node *stack);
void			rrb(t_node *stack);
void			rrr(t_node *stack_a, t_node *stack_b);
/*  COMMANDS CHECKER  */
void			sa_checker(t_node *stack);
void			sb_checker(t_node *stack);
void			ss_checker(t_node *stack_a, t_node *stack_b);
void			pa_checker(t_node *stack_a, t_node *stack_b);
void			pb_checker(t_node *stack_a, t_node *stack_b);
void			ra_checker(t_node *stack);
void			rb_checker(t_node *stack);
void			rr_checker(t_node *stack_a, t_node *stack_b);
void			rra_checker(t_node *stack);
void			rrb_checker(t_node *stack);
void			rrr_checker(t_node *stack_a, t_node *stack_b);
/*	Sorting		*/
void			sort(t_node *stack_a, t_node *stack_b);
int				find_lower(t_node *stack_a);
int				*index_it(int argc, char *argv[]);
int				stack_length(t_node *stack);
int				stack_length(t_node *stack);
int				ordered(t_node *stack_a);
int				find_next_position(t_node *stack_b);
void			sort_with_3(t_node *stack_a);
void			sort_with_5(t_node *stack_a, t_node *stack_b);
void			sort_with_n(t_node *stack_a, t_node *stack_b, int len);
#endif