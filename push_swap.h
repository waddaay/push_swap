/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:33 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/16 03:56:09 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 2

typedef struct s_stack {
	int		size;
	int		top;
	long	*body;
	int		count;
	int		pushed;
}				t_stack;

typedef struct s_attr {
	int	pv1;
	int	pv2;
	int	vp1;
	int	b;
	int	div;
	int	max;
	int	med;
	int	max_val;
	int	count;
	int	i;
	int	tab[5];
}				t_attr;

int		array_size(char **arr);
int		stack_size(int argc, char **argv);
void	push(t_stack *stack_x, t_stack *stack_y);
void	create_stack(int stack_size, int top, t_stack *our_stack);
void	fill_stack(int argc, char **argv, t_stack *stack);
void	ft_putstr_fd(char *s, int fd);
void	pa(t_stack *stack_a, t_stack *stack_b, int b);
void	pb(t_stack *stack_a, t_stack *stack_b, int b);
void	swap(t_stack *stack);
void	sa(t_stack *stack_a, int b);
void	sb(t_stack *stack_b, int b);
void	ss(t_stack *stack_a, t_stack *stack_b, int b);
void	rotate(t_stack *stack, char *str, int b);
void	rrotate(t_stack *stack, char *str, int b);
void	rr(t_stack *stack_a, t_stack *stack_b, char *str, int b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	push_all_to_b(t_stack *stack_a, t_stack *stack_b, int div, int b);
void	push_all_to_a(t_stack *stack_a, t_stack *stack_b, int b);
int		max(t_stack *stack);
int		check_div(int size, int argc, char **argv);
void	ft_swap(int *a, int *b);
void	rules(t_stack *stack_a, t_stack *stack_b, int *s_tab, t_attr attr);
void	push_a(t_stack *stack_a, t_stack *stack_b, t_attr attr);
int		check_errors(int argc, char **argv, t_stack stack);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		is_sorted(long *tab, int size);
void	free_memory(t_stack *stack);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		check_new_line(char *string);
char	*get_next_line(int fd);
int		is_all_numeric(int argc, char **argv);

#endif