/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurssion_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:48:23 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 16:48:24 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		recursion_stack_b(t_push *stack, t_info *info)
{
	t_info		*info_next;
	int			pivot;

	info_next = create_info();
	pivot = find_pivot(stack->b, info->size_b, 0, 0);
	if (info->size_b > 3)
	{
		rec_b_cycle(stack, info, info_next, pivot);
		rec_b_first(stack, info_next, pivot);
	}
	else
		sort_three_elem_b(stack, info);
	free(info_next);
	return (0);
}

void	rec_b_cycle(t_push *stack, t_info *info, t_info *info_next, int pivot)
{
	while (info->size_b > 1)
	{
		if (stack->b[0] >= pivot)
		{
			pa(stack);
			info_next->size_a++;
			info_next->position_a++;
		}
		else
		{
			rb(stack);
			info_next->size_b++;
			info_next->position_b--;
		}
		info->size_b--;
	}
}

void	rec_b_first(t_push *stack, t_info *info_next, int pivot)
{
	if (stack->b[0] >= pivot)
	{
		pa(stack);
		rrb(stack);
		info_next->size_a++;
		info_next->position_a++;
		info_next->position_b++;
	}
	else
		info_next->size_b++;
	recursion_stack_a(stack, info_next);
	if (info_next->size_b == stack->n_b)
	{
		info_next->position_b = info_next->size_b;
		recursion_stack_b(stack, info_next);
	}
	else
		reverse_recursion_stack_b(stack, info_next);
}
