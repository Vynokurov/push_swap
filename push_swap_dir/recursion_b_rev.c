/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurssion_b_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:48:23 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 16:48:24 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		reverse_recursion_stack_b(t_push *stack, t_info *info)
{
	t_info		*info_next;
	int			pivot;
	int			*p;

	p = &stack->b[stack->n_b - info->size_b + 1];
	info_next = create_info();
	pivot = find_pivot(p, info->size_b, 1, stack->b[0]);
	if (info->size_b > 3)
	{
		rev_rec_b_cycle(stack, info, info_next, pivot);
		rev_rec_b_first(stack, info_next, pivot);
	}
	else
		sort_three_elem_b_down(stack, info);
	free(info_next);
	return (0);
}

void	rev_rec_b_cycle(t_push *stack, t_info *info, t_info *info_next, int n)
{
	while (info->size_b > 1)
	{
		if (stack->b[0] >= n)
		{
			pa(stack);
			info_next->size_a++;
			info_next->position_a++;
		}
		else
		{
			info_next->size_b++;
			info_next->position_b++;
		}
		rrb(stack);
		info->size_b--;
	}
}

void	rev_rec_b_first(t_push *stack, t_info *info_next, int n)
{
	if (stack->b[0] >= n)
	{
		pa(stack);
		info_next->size_a++;
		info_next->position_a++;
	}
	else
	{
		info_next->size_b++;
		info_next->position_b++;
	}
	recursion_stack_a(stack, info_next);
	recursion_stack_b(stack, info_next);
}
