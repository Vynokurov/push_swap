/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_a_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:48:23 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 16:48:24 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		reverse_recursion_stack_a(t_push *stack, t_info *info)
{
	t_info		*info_next;
	int			pivot;
	int			*p;

	p = &stack->a[stack->n_a - info->size_a + 1];
	info_next = create_info();
	pivot = find_pivot(p, info->size_a, 1, stack->a[0]);
	if (info->size_a > 3)
	{
		rev_rec_a_cycle(stack, info, info_next, pivot);
		rev_rec_a_first(stack, info_next, pivot);
	}
	else
		sort_three_elem_a_down_first(stack, info);
	free(info_next);
	return (0);
}

void	rev_rec_a_cycle(t_push *stack, t_info *info, t_info *info_next, int n)
{
	while (info->size_a > 1)
	{
		if (stack->a[0] < n)
		{
			pb(stack);
			info_next->size_b++;
			info_next->position_b++;
		}
		else
		{
			info_next->size_a++;
			info_next->position_a++;
		}
		rra(stack);
		info->size_a--;
	}
}

void	rev_rec_a_first(t_push *stack, t_info *info_next, int n)
{
	if (stack->a[0] < n)
	{
		pb(stack);
		info_next->size_b++;
		info_next->position_b++;
	}
	else
	{
		info_next->size_a++;
		info_next->position_a++;
	}
	recursion_stack_a(stack, info_next);
	recursion_stack_b(stack, info_next);
}
