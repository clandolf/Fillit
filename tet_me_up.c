/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_me_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:37:20 by hchung            #+#    #+#             */
/*   Updated: 2018/09/10 03:54:36 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**make_tet_list(int tet)
{
	int		**tet_list;
	int		i;

	tet_list = (int **)malloc(sizeof(int*) * tet + 1);
	i = 0;
	if (!tet_list)
		return (NULL);
	while (i <= tet)
	{
		tet_list[i] = (int *)malloc(sizeof(int) * 8);
		i++;
	}
	tet_list[tet] = NULL;
	return (tet_list);
}

int		tet_tat(int *str, int val, int index)
{
	str[index] = val;
	index++;
	return (index);
}

void	helper(char c, int *x, int *y)
{
	if (c == '\n')
	{
		*x = 0;
		if (*y == 3)
			*y = -1;
		else
			*y = *y + 1;
	}
}

int		**coordinate_transplant(int fd, int x, int y, int tet)
{
	t_helper	h;

	h.tet_coord = 0;
	h.tet_list = make_tet_list(tet);
	h.tet_list_i = 0;
	while (read(fd, &h.c, 1) > 0)
	{
		helper(h.c, &x, &y);
		if (h.c == '.')
			x++;
		else if (h.c == '#')
		{
			if (h.tet_coord == 8)
			{
				h.tet_list_i++;
				h.tet_coord = 0;
			}
			h.tet_coord = tet_tat(h.tet_list[h.tet_list_i], x, h.tet_coord);
			h.tet_coord = tet_tat(h.tet_list[h.tet_list_i], y, h.tet_coord);
			x++;
		}
	}
	return (h.tet_list);
}
