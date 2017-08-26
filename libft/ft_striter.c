/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:23:59 by dvynokur          #+#    #+#             */
/*   Updated: 2016/12/10 19:44:56 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			(*f)(&s[i]);
			i++;
		}
	}
}
