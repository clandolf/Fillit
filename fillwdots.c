/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillwdots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 03:29:28 by clandolf          #+#    #+#             */
/*   Updated: 2018/09/10 04:47:49 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillwdots(char map[20][20], int size)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < 11)
		ft_bzero(map[i++], 11);
	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
			map[x][y++] = '.';
		y = 0;
		x++;
	}
	return ;
}

int		racinecarre(int num)
{
	int			result;

	result = 1;
	while (result * result < num)
		result++;
	return (result);
}
