/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:00:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 17:00:53 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_three_elem_a(t_push *stack, t_info *info)
{
	if (info->size_a == 2)
		swap(stack);
	else
	{
		if (stack->n_a == 3)
		{
			if (stack->a[1] < stack->a[0] && stack->a[0] > stack->a[2] &&
				stack->a[1] < stack->a[2])
				ra(stack);
			else if (stack->a[1] < stack->a[0] && stack->a[0] > stack->a[2])
			{
				sa(stack);
				rra(stack);
			}
			else if (stack->a[1] < stack->a[0] && stack->a[0] < stack->a[2])
				sa(stack);
			else if (stack->a[2] < stack->a[0] && stack->a[0] < stack->a[1])
				rra(stack);
			else
				sort_three_elem_a_cont(stack);
		}
		else
			swap_a_big(stack);
	}
}

void	sort_three_elem_a_cont(t_push *stack)
{
	if (stack->a[2] < stack->a[0] && stack->a[0] > stack->a[1])
	{
		sa(stack);
		rra(stack);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
	{
		rra(stack);
		sa(stack);
	}
}

void	swap_a_big(t_push *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[0] < stack->a[2])
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (stack->a[1] < stack->a[0] && stack->a[0] < stack->a[2])
	{
		sa(stack);
	}
	else if (stack->a[1] < stack->a[0] && stack->a[0] > stack->a[2]
		&& stack->a[1] < stack->a[2])
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else
		swap_a_big_cont(stack);
}

void	swap_a_big_cont(t_push *stack)
{
	if (stack->a[2] < stack->a[0] && stack->a[0] < stack->a[1])
	{
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
	else if (stack->a[2] < stack->a[0] && stack->a[0] > stack->a[1])
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
}
