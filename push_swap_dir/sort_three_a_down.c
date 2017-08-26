/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:00:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 17:00:53 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_three_elem_a_down_first(t_push *stack, t_info *info)
{
	if (info->size_a == 2)
	{
		rra(stack);
		swap(stack);
	}
	else
	{
		if (stack->a[0] == find_next_a_first(stack->a,
			stack->n_a, info->size_a))
		{
			rra(stack);
			rra(stack);
			swap(stack);
		}
		else
			sort_three_elem_a_down_cont(stack, info);
	}
}

void	sort_three_elem_a_down_cont(t_push *stack, t_info *info)
{
	if (stack->a[stack->n_a - 1] == find_next_a_first(stack->a,
		stack->n_a, info->size_a))
	{
		rra(stack);
		swap(stack);
		rra(stack);
		swap(stack);
	}
	else if (stack->a[stack->n_a - 2] == find_next_a_first(stack->a,
		stack->n_a, info->size_a))
	{
		rra(stack);
		rra(stack);
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		swap(stack);
	}
}

int		find_next_a_first(int *a, int size, int num)
{
	int res;

	res = a[0];
	if (num == 3)
	{
		if (a[size - 1] > res)
			res = a[size - 1];
		if (a[size - 2] > res)
			res = a[size - 2];
	}
	return (res);
}
