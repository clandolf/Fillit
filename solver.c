/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:34:07 by clandolf          #+#    #+#             */
/*   Updated: 2018/10/19 16:10:38 by clandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		losesomedots(char map[20][20], int **storage, int minsize)
{
	while (!readmap(map, storage, minsize, 'A'))
	{
		fillwdots(map, ++minsize);
	}
	return (minsize);
}

int		readmap(char map[20][20], int **storage, int minsize, char c)
{
	t_pams	p;

	if (*storage == NULL)
		return (1);
	p.x = 0;
	p.y = -1;
	p.c = c;
	p.storage = storage;
	p.minsize = minsize;
	while (++p.y < minsize)
	{
		while (p.x < minsize)
		{
			if (tetplacer(map, p))
			{
				if (readmap(map, storage + 1, minsize, c + 1))
					return (1);
				else
					replacewdots(map, storage, p.y, p.x);
			}
			p.x++;
		}
		p.x = 0;
	}
	return (0);
}

void	replacewdots(char map[20][20], int **storage, int y, int x)
{
	int			*tetcoord;
	int			i;

	i = 0;
	tetcoord = storage[0];
	while (i < 8)
	{
		map[y + tetcoord[i + 1]][x + tetcoord[i]] = '.';
		i = i + 2;
	}
}

int		tetplacer(char map[20][20], t_pams p)
{
	int			*tcoord;
	int			i;

	i = 0;
	tcoord = p.storage[0];
	while (i < 8)
	{
		if (p.y + tcoord[i + 1] < p.minsize && p.x + tcoord[i] < p.minsize)
		{
			if (map[p.y + tcoord[i + 1]][p.x + tcoord[i]] != '.')
				return (0);
		}
		else
			return (0);
		i = i + 2;
	}
	i = 0;
	while (i < 8)
	{
		map[p.y + tcoord[i + 1]][p.x + tcoord[i]] = p.c;
		i = i + 2;
	}
	return (1);
}

void	imprimante(char map[20][20], int size)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}
