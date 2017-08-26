/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 17:17:10 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sa(t_push *stack)
{
	int temp;

	temp = 0;
	if (stack->n_a > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	ft_putstr("sa\n");
}

void	pa(t_push *stack)
{
	int *p1;
	int *p2;
	int i;

	i = 1;
	if (stack->n_b > 0)
	{
		p1 = malloc(sizeof(int) * (stack->n_b - 1));
		while (i <= stack->n_b - 1)
		{
			p1[i - 1] = stack->b[i];
			i++;
		}
		p2 = malloc(sizeof(int) * (stack->n_a + 1));
		p2[0] = stack->b[0];
		i = 1;
		if (stack->n_a > 0)
			while (i < (stack->n_a + 1))
			{
				p2[i] = stack->a[i - 1];
				i++;
			}
		filling_stack_a(stack, p1, p2);
	}
	ft_putstr("pa\n");
}

void	filling_stack_a(t_push *stack, int *p1, int *p2)
{
	free(stack->a);
	free(stack->b);
	stack->b = p1;
	stack->a = p2;
	stack->n_b -= 1;
	stack->n_a += 1;
}

void	rra(t_push *stack)
{
	int *p;
	int i;

	i = 1;
	if (stack->n_a > 1)
	{
		if (!(p = malloc(sizeof(int) * stack->n_a)))
			return ;
		p[0] = stack->a[stack->n_a - 1];
		while (i < stack->n_a)
		{
			p[i] = stack->a[i - 1];
			i++;
		}
		free(stack->a);
		stack->a = p;
	}
	ft_putstr("rra\n");
}

void	ra(t_push *stack)
{
	int *p;
	int i;

	i = 0;
	if (stack->n_a > 1)
	{
		if (!(p = malloc(sizeof(int) * stack->n_a)))
			return ;
		while (i < (stack->n_a - 1))
		{
			p[i] = stack->a[i + 1];
			i++;
		}
		p[stack->n_a - 1] = stack->a[0];
		free(stack->a);
		stack->a = p;
	}
	ft_putstr("ra\n");
}
