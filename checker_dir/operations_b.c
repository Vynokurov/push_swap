/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 17:17:10 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	check_sb(t_push *stack)
{
	int temp;

	temp = 0;
	if (stack->n_b > 1)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
}

void	check_pb(t_push *stack)
{
	int *p1;
	int *p2;
	int i;

	i = 1;
	if (stack->n_a > 0)
	{
		p1 = malloc(sizeof(int) * (stack->n_a - 1));
		while (i <= stack->n_a - 1)
		{
			p1[i - 1] = stack->a[i];
			i++;
		}
		p2 = malloc(sizeof(int) * (stack->n_b + 1));
		p2[0] = stack->a[0];
		i = 1;
		if (stack->n_b > 0)
			while (i < (stack->n_b + 1))
			{
				p2[i] = stack->b[i - 1];
				i++;
			}
		filling_stack_b_check(stack, p1, p2);
	}
}

void	filling_stack_b_check(t_push *stack, int *p1, int *p2)
{
	free(stack->a);
	free(stack->b);
	stack->a = p1;
	stack->b = p2;
	stack->n_a -= 1;
	stack->n_b += 1;
}

void	check_rrb(t_push *stack)
{
	int *p;
	int i;

	i = 1;
	if (stack->n_b > 1)
	{
		if (!(p = malloc(sizeof(int) * (stack->n_b))))
			return ;
		p[0] = stack->b[stack->n_b - 1];
		while (i < stack->n_b)
		{
			p[i] = stack->b[i - 1];
			i++;
		}
		free(stack->b);
		stack->b = p;
	}
}

void	check_rb(t_push *stack)
{
	int *p;
	int i;

	i = 0;
	if (stack->n_b > 1)
	{
		if (!(p = malloc(sizeof(int) * (stack->n_b))))
			return ;
		while (i < (stack->n_b - 1))
		{
			p[i] = stack->b[i + 1];
			i++;
		}
		p[(stack->n_b) - 1] = stack->b[0];
		free(stack->b);
		stack->b = p;
	}
}
