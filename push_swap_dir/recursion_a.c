/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:48:23 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 16:48:24 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		recursion_stack_a(t_push *stack, t_info *info)
{
	t_info		*info_next;
	int			pivot;
	int			i;

	i = 0;
	info_next = create_info();
	pivot = find_pivot(stack->a, info->size_a, 0, 0);
	if (info->size_a > 3)
	{
		rec_a_cycle(stack, info, info_next, pivot);
		rec_a_first(stack, info_next, pivot);
	}
	else
		sort_three_elem_a(stack, info);
	free(info_next);
	return (0);
}

void	rec_a_cycle(t_push *stack, t_info *info, t_info *info_next, int pivot)
{
	while (info->size_a > 1)
	{
		if (stack->a[0] < pivot)
		{
			pb(stack);
			info_next->size_b++;
			info_next->position_b++;
		}
		else
		{
			ra(stack);
			info_next->size_a++;
			info_next->position_a--;
		}
		info->size_a--;
	}
}

void	rec_a_first(t_push *stack, t_info *info_next, int pivot)
{
	if (stack->a[0] < pivot)
	{
		pb(stack);
		rra(stack);
		info_next->size_b++;
		info_next->position_b++;
		info_next->position_a++;
	}
	else
		info_next->size_a++;
	if (info_next->size_a == stack->n_a)
	{
		info_next->position_a = info_next->size_a;
		recursion_stack_a(stack, info_next);
	}
	else
		reverse_recursion_stack_a(stack, info_next);
	recursion_stack_b(stack, info_next);
}
