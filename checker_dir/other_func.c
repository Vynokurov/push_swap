/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 17:17:10 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int			if_sorted(t_push *stack)
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

int			error_management(char *s)
{
	int			i;
	intmax_t	max;
	int			res;

	i = 0;
	max = 0;
	res = 0;
	while (s[i])
	{
		if ((s[i] != '+' && s[i] != '-') && (s[i] < '0' || s[i] > '9'))
			res = 1;
		if (s[i] == '+' || s[i] == '-')
			if (i > 0 || ft_strlen(s) == 1)
				res = 1;
		i++;
	}
	max = atoi_max(s);
	if (max < -2147483648 || max > 2147483647)
		res = 1;
	if (res == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

intmax_t	atoi_max(char *str)
{
	intmax_t	res;
	int			i;
	int			min;

	res = 0;
	i = 0;
	min = 1;
	if (str[i] == '+' && str[i + 1] >= 48 && str[i + 1] <= 57)
		i++;
	if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57)
	{
		min = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	i++;
	return (res * min);
}

int			seq(t_push *stack)
{
	int i;

	i = 0;
	if (stack->n_a > 1)
		while (i < (stack->n_a - 1))
		{
			if (stack->a[i] > stack->a[i + 1])
			{
				ft_putstr("KO\n");
				return (0);
			}
			i++;
		}
	if (stack->n_b == 0)
		ft_putstr("OK\n");
	else
	{
		ft_putstr("KO\n");
		return (0);
	}
	return (1);
}

int			check_duplicates(int *tab, int n)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = tab[0];
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (tab[i] == tab[j] && i != j)
			{
				ft_putstr("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
