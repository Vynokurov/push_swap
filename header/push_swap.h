/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/14 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BLACK   "\x1b[37m"
# define RESET   "\x1b[0m"
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	int				size_a;
	int				size_b;
	int				position_a;
	int				position_b;
}					t_info;
typedef struct		s_struct
{
	int				*a;
	int				*b;
	int				n_a;
	int				n_b;
}					t_push;
int					argv_reading(char **argv, t_push *tab, int argc);
int					ft_mod(int n);
int					recursion_stack_a(t_push *stack, t_info *info);
void				rec_a_cycle(t_push *stack, t_info *info,
					t_info *info_next, int pivot);
void				rec_a_first(t_push *stack, t_info *info_next, int pivot);
int					reverse_recursion_stack_a(t_push *stack, t_info *info);
void				rev_rec_a_cycle(t_push *stack, t_info *info,
					t_info *info_next, int pivot);
void				rev_rec_a_first(t_push *stack, t_info *info_next,
					int pivot);
int					recursion_stack_b(t_push *stack, t_info *info);
void				rec_b_cycle(t_push *stack, t_info *info, t_info
					*info_next, int pivot);
void				rec_b_first(t_push *stack, t_info *info_next, int pivot);
int					reverse_recursion_stack_b(t_push *stack, t_info *info);
void				rev_rec_b_cycle(t_push *stack, t_info *info,
					t_info *info_next, int pivot);
void				rev_rec_b_first(t_push *stack, t_info *info_next,
					int pivot);
int					*making_mass(int *mass, int n_elem, int n_new);
t_info				*create_info();
void				sort_three_elem_a(t_push *stack, t_info *info);
void				sort_three_elem_a_cont(t_push *stack);
void				sort_three_elem_a_down_cont(t_push *stack, t_info *info);
void				push_three_elem_b(t_push *stack, t_info *info);
void				sort_three_elem_b_down(t_push *stack, t_info *info);
void				sort_three_elem_b(t_push *stack, t_info *info);
void				sort_three_elem_b_down_cont(t_push *stack);
void				sort_three_elem_b_down_cont_second(t_push *stack);
void				swap_a_big(t_push *stack);
void				swap_a_big_cont(t_push *stack);
void				sort_three_elem_a_down(t_push *stack, t_info *info);
void				sort_three_elem_a_down_first(t_push *stack, t_info *info);
void				sort_three_elem_a_first(t_push *stack, t_info *info);
void				sort_three_elem_a_first_cont(t_push *stack, t_info *info);
void				swap(t_push *stack);
int					find_next_b(int *b, int size);
int					find_next_a(int *a, int size, int num);
int					find_next_a_first(int *a, int size, int num);
int					find_next_a_elem(int *n, int size);
int					find_pivot(int *tab, int n, int flag, int value);
int					if_sorted(t_push *stack);
void				first_temp(t_push *stack);
void				b_last(t_push *stack);
int					find_pa(t_push *stack);
void				push_pa(t_push *stack);
void				down_rev(t_push *stack);
void				(*g_operation_check[12])(t_push *stack);
void				pa(t_push *stack);
void				sa(t_push *stack);
void				ra(t_push *stack);
void				rra(t_push *stack);
void				filling_stack_a(t_push *stack, int *p1, int *p2);
void				filling_stack_b(t_push *stack, int *p1, int *p2);
void				sb(t_push *stack);
void				ss(t_push *stack);
void				pb(t_push *stack);
void				rrb(t_push *stack);
void				rrr(t_push *stack);
void				rb(t_push *stack);
void				rr(t_push *stack);
t_push				*new_tab(int size);
int					error_management(char *s);
intmax_t			atoi_max(char *s);
int					check_duplicates(int *tab, int n);
void				checker(t_push *stack, char *str);
void				check_sa(t_push *stack);
void				check_pa(t_push *stack);
void				filling_stack_a_check(t_push *stack, int *p1, int *p2);
void				check_rra(t_push *stack);
void				check_ra(t_push *stack);
void				check_sb(t_push *stack);
void				check_pb(t_push *stack);
void				filling_stack_b_check(t_push *stack, int *p1, int *p2);
void				check_rrb(t_push *stack);
void				check_rb(t_push *stack);
void				check_ss(t_push *stack);
void				check_rrr(t_push *stack);
void				check_rr(t_push *stack);
int					seq(t_push *stack);
int					op_type(char *s);
void				if_correct(char *s);
char				*str_making(void);
int					argv_reading(char **argv, t_push *tab, int argc);

#endif
