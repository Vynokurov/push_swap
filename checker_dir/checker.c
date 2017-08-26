/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:08 by dvynokur          #+#    #+#             */
/*   Updated: 2017/04/13 17:17:10 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	checker(t_push *stack, char *str)
{
	int		i;
	char	**s;

	i = -1;
	s = ft_strsplit(str, '\n');
	while (s[++i])
		g_operation_check[op_type(s[i])](stack);
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	seq(stack);
}

int		argv_reading(char **argv, t_push *tab, int argc)
{
	int i;

	i = 0;
	if (argc == 1)
		return (1);
	while (argv[++i])
	{
		if (error_management(argv[i]) == 1)
			return (1);
		tab->a[i - 1] = ft_atoi(argv[i]);
	}
	tab->n_a = argc - 1;
	return (0);
}

void	if_correct(char *s)
{
	if (ft_strcmp(s, "sa") && ft_strcmp(s, "sb") &&
		ft_strcmp(s, "ss") && ft_strcmp(s, "pa") &&
		ft_strcmp(s, "pb") && ft_strcmp(s, "ra") &&
		ft_strcmp(s, "rb") && ft_strcmp(s, "rr") &&
		ft_strcmp(s, "rra") && ft_strcmp(s, "rrb") &&
		ft_strcmp(s, "rrr"))
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

char	*str_making(void)
{
	char	*buf;
	char	*str;
	char	*str2;

	buf = NULL;
	str2 = NULL;
	str = ft_strnew(1);
	while (get_next_line(0, &buf))
	{
		if_correct(buf);
		str2 = ft_strjoin(str, buf);
		if (str)
			free(str);
		str = ft_strjoin(str2, "\n");
		if (buf)
			free(buf);
		if (str2)
			free(str2);
		str2 = NULL;
		buf = NULL;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	t_push	*tab;
	int		fd;
	char	*str;

	fd = 0;
	tab = new_tab(argc);
	str = NULL;
	if ((argv_reading(argv, tab, argc) == 1) ||
		(check_duplicates(tab->a, tab->n_a) == 1))
		return (0);
	str = str_making();
	checker(tab, str);
	return (0);
}
