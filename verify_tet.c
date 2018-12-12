/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:13:02 by hchung            #+#    #+#             */
/*   Updated: 2018/09/10 06:02:48 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}

int		hash_count(int *str, int tet_coord, int coord_rider, int odd)
{
	int hash_sides;

	hash_sides = 0;
	while (coord_rider < 8)
	{
		if (!odd)
		{
			if (str[tet_coord] == str[coord_rider])
			{
				if (abs(str[tet_coord + 1] - str[coord_rider + 1]) == 1)
					hash_sides++;
			}
			coord_rider += 2;
		}
		else
		{
			if (str[tet_coord] == str[coord_rider])
			{
				if (abs(str[tet_coord - 1] - str[coord_rider - 1]) == 1)
					hash_sides++;
			}
			coord_rider += 2;
		}
	}
	return (hash_sides);
}

int		tet_check(int *str)
{
	int	tet_coord;
	int coord_rider;
	int	hash_sides;

	tet_coord = 0;
	coord_rider = 0;
	hash_sides = 0;
	while (tet_coord < 8)
	{
		if (tet_coord % 2 == 0)
		{
			hash_sides += hash_count(str, tet_coord, 0, 0);
			tet_coord++;
		}
		else if (tet_coord % 2 != 0)
		{
			hash_sides += hash_count(str, tet_coord, 1, 1);
			tet_coord++;
		}
	}
	return (hash_sides == 6 || hash_sides == 8) ? 1 : 0;
}

int		verify_tet(int **tet_list, int tet)
{
	int i;
	int	valid_tet;
	int tet_coord;

	i = 0;
	valid_tet = 0;
	tet_coord = 0;
	tet_list = minimize_tet(tet_list, tet, 0);
	while (i < tet)
	{
		if (tet_check(tet_list[i++]))
			valid_tet++;
	}
	if (valid_tet == tet)
	{
		return (1);
	}
	return (0);
}
