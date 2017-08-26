/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 17:17:10 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ss(t_push *stack)
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
	ft_putstr("ss\n");
}

void	rrr(t_push *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr("rrr\n");
}

void	rr(t_push *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr("rr\n");
}
