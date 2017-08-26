/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:50:11 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 16:50:12 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_three_elem_b(t_push *stack, t_info *info)
{
	if (info->size_b == 3)
		push_three_elem_b(stack, info);
	if (info->size_b == 2)
	{
		pa(stack);
		pa(stack);
		swap(stack);
	}
	if (info->size_b == 1)
		pa(stack);
}

void	push_three_elem_b(t_push *stack, t_info *info)
{
	if (stack->b[0] == find_next_b(stack->b, stack->n_b))
	{
		pa(stack);
	}
	else if (stack->b[1] == find_next_b(stack->b, stack->n_b))
	{
		sb(stack);
		pa(stack);
	}
	else if (stack->b[2] == find_next_b(stack->b, stack->n_b))
	{
		rb(stack);
		sb(stack);
		pa(stack);
		rrb(stack);
	}
	info->size_b--;
}

void	sort_three_elem_b_down(t_push *stack, t_info *info)
{
	int i;

	i = info->size_b;
	if (info->size_b == 1)
		pa(stack);
	else if (info->size_b == 2)
	{
		if (stack->b[0] == find_next_b(stack->b, stack->n_b))
		{
			pa(stack);
			rrb(stack);
			pa(stack);
		}
		else
		{
			rrb(stack);
			pa(stack);
			pa(stack);
		}
	}
	else
		sort_three_elem_b_down_cont(stack);
}

void	sort_three_elem_b_down_cont(t_push *stack)
{
	{
		if (stack->b[0] == find_next_b(stack->b, stack->n_b))
		{
			pa(stack);
			rrb(stack);
			if (stack->b[0] == find_next_b(stack->b, stack->n_b))
			{
				pa(stack);
				rrb(stack);
				pa(stack);
			}
			else
			{
				rrb(stack);
				pa(stack);
				pa(stack);
			}
		}
		else
		{
			rrb(stack);
			sort_three_elem_b_down_cont_second(stack);
		}
	}
}

void	sort_three_elem_b_down_cont_second(t_push *stack)
{
	if (stack->b[0] == find_next_b(stack->b, stack->n_b))
	{
		pa(stack);
		if (stack->b[0] == find_next_b(stack->b, stack->n_b))
		{
			pa(stack);
			rrb(stack);
			pa(stack);
		}
		else
		{
			rrb(stack);
			pa(stack);
			pa(stack);
		}
	}
	else
	{
		rrb(stack);
		pa(stack);
		pa(stack);
		pa(stack);
		swap(stack);
	}
}
