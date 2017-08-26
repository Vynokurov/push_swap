/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:39:41 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 15:39:45 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_info		*create_info(void)
{
	t_info		*info;

	info = malloc(sizeof(t_info));
	info->size_a = 0;
	info->size_b = 0;
	info->position_a = 0;
	info->position_b = 0;
	return (info);
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

int			main(int argc, char **argv)
{
	t_push	*stack;
	t_info	*info;
	int		i;

	i = 0;
	info = create_info();
	stack = new_tab(argc);
	while (argv[++i])
	{
		if (error_management(argv[i]) == 1)
			return (0);
		stack->a[i - 1] = ft_atoi(argv[i]);
	}
	stack->n_a = argc - 1;
	if ((check_duplicates(stack->a, stack->n_a) == 1) ||
		(if_sorted(stack) == 1))
		return (0);
	info->size_a = stack->n_a;
	info->position_a = info->size_a;
	recursion_stack_a(stack, info);
	return (0);
}
