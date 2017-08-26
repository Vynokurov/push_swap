/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:48:23 by dvynokur          #+#    #+#             */
/*   Updated: 2017/07/12 16:48:24 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		find_pivot(int *tab, int n, int flag, int value)
{
	int i;
	int temp;
	int	*array;

	i = -1;
	if (!(array = (int *)malloc(sizeof(int) * n)))
		return (0);
	while (++i < n - flag)
		array[i] = tab[i];
	if (flag == 1)
		array[n - 1] = value;
	i = -1;
	while (++i < n - 1)
		if (array[i + 1] < array[i])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = -1;
		}
	i = 0;
	free(array);
	return (array[(n / 2)]);
}

void	swap(t_push *stack)
{
	if (stack->n_a > 1)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
}

t_push	*new_tab(int size)
{
	t_push *new;

	new = malloc(sizeof(t_push));
	new->a = malloc(sizeof(int) * size);
	new->n_a = size - 1;
	new->b = NULL;
	new->n_b = 0;
	return (new);
}

int		if_sorted(t_push *stack)
{
	int i;
	int	a;
	int un_first;

	i = 0;
	a = 0;
	un_first = 0;
	while (i < stack->n_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			a = 1;
			un_first = stack->a[i];
		}
		i++;
	}
	if (a == 0)
		return (1);
	return (0);
}

int		find_next_b(int *b, int size)
{
	int res;
	int i;

	i = 0;
	res = b[0];
	while (i < size)
	{
		if (res < b[i])
			res = b[i];
		i++;
	}
	return (res);
}
