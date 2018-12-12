/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:48:43 by hchung            #+#    #+#             */
/*   Updated: 2018/09/10 05:54:57 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		ft_usage(void)
{
	ft_putstr("pls use right number of args, bub");
	return (0);
}

int		ft_parser(int fd, char c, int hash, int tet)
{
	int i;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (++i % 5 == 0)
			hash = (c != '\n') ? (hash + 1) : hash;
		else if (i % 5 != 0)
		{
			if (c != '.' && c != '#')
				return (ft_error());
			hash = (c == '#') ? (hash + 1) : hash;
		}
		if (i == 20)
		{
			if (hash != 4)
				return (ft_error());
			i = -1;
			hash = 0;
			tet++;
		}
	}
	return ((i != -1 || tet > 26) ? ft_error() : tet);
}
