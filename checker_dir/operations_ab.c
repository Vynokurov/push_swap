/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 17:17:10 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	(*g_operation_check[12])(t_push *stack) =

{check_sa, check_sb, check_ss, check_pa, check_pb, check_ra, check_rb,
	check_rr, check_rra, check_rrb, check_rrr};

void	check_ss(t_push *stack)
{
	int temp;

	temp = 0;
	if (stack->n_a > 1 && stack->n_b > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
}

void	check_rrr(t_push *stack)
{
	check_rra(stack);
	check_rrb(stack);
}

void	check_rr(t_push *stack)
{
	check_ra(stack);
	check_rb(stack);
}

t_push	*new_tab(int size)
{
	t_push *new;

	new = malloc(sizeof(t_push));
	new->a = malloc(sizeof(int) * size);
	new->n_a = size - 1;
	new->b = NULL;
	new->n_b = 0;
	return (new);
}

int		op_type(char *s)
{
	if ((ft_strcmp(s, "sa")) == 0)
		return (0);
	else if ((ft_strcmp(s, "sb")) == 0)
		return (1);
	else if ((ft_strcmp(s, "ss")) == 0)
		return (2);
	else if ((ft_strcmp(s, "pa")) == 0)
		return (3);
	else if ((ft_strcmp(s, "pb")) == 0)
		return (4);
	else if ((ft_strcmp(s, "ra")) == 0)
		return (5);
	else if ((ft_strcmp(s, "rb")) == 0)
		return (6);
	else if ((ft_strcmp(s, "rr")) == 0)
		return (7);
	else if ((ft_strcmp(s, "rra")) == 0)
		return (8);
	else if ((ft_strcmp(s, "rrb")) == 0)
		return (9);
	else if ((ft_strcmp(s, "rrr")) == 0)
		return (10);
	return (11);
}
