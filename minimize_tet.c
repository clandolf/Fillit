/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:40:06 by hchung            #+#    #+#             */
/*   Updated: 2018/09/10 03:15:52 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_min(int **tet_list, int i, int tet_coord)
{
	int low;

	low = tet_list[i][tet_coord];
	while (tet_coord < 8)
	{
		low = (low <= tet_list[i][tet_coord] ? low : tet_list[i][tet_coord]);
		tet_coord += 2;
	}
	return (low);
}

int		**minimize_tet(int **tet_list, int tet, int i)
{
	int tet_coord;
	int x_low;
	int y_low;

	while (i < tet)
	{
		x_low = find_min(tet_list, i, 0);
		y_low = find_min(tet_list, i, 1);
		tet_coord = 0;
		while (tet_coord < 8)
		{
			if (tet_coord % 2 == 0)
			{
				tet_list[i][tet_coord] = tet_list[i][tet_coord] - x_low;
				tet_coord++;
			}
			else
			{
				tet_list[i][tet_coord] = tet_list[i][tet_coord] - y_low;
				tet_coord++;
			}
		}
		i++;
	}
	return (tet_list);
}
