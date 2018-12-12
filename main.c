/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 03:43:07 by hchung            #+#    #+#             */
/*   Updated: 2018/09/10 06:07:45 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		**tet_list;
	int		tet;
	char	map[20][20];
	int		size;

	if (argc != 2)
		return (ft_usage());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error());
	if (!(tet = ft_parser(fd, 0, 0, 0)))
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	tet_list = coordinate_transplant(fd, 0, 0, tet);
	tet_list = minimize_tet(tet_list, tet, 0);
	if (!verify_tet(tet_list, tet))
		return (ft_error());
	fillwdots(map, racinecarre(tet * 4));
	size = losesomedots(map, tet_list, racinecarre(tet * 4));
	imprimante(map, size);
	return (0);
}
