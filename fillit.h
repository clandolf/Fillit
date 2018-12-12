/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:46:30 by hchung            #+#    #+#             */
/*   Updated: 2018/09/10 05:37:06 by hchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_helper
{
	int			**tet_list;
	int			tet_list_i;
	int			tet_coord;
	char		c;
}				t_helper;

typedef struct	s_pams
{
	int			**storage;
	char		c;
	int			y;
	int			x;
	int			minsize;
}				t_pams;

int				ft_error(void);
int				ft_usage(void);
int				ft_parser(int fd, char c, int hash, int tet);

int				**make_tet_list(int tet);
int				tet_tat(int *str, int val, int index);
void			helper(char c, int *x, int *y);
int				**coordinate_transplant(int fd, int x, int y, int tet);

int				abs(int i);
int				hash_count(int *str, int tet_coord, int coord_rider, int odd);
int				tet_check(int *str);
int				verify_tet(int **tet_list, int tet);

int				find_min(int **tet_list, int i, int tet_coord);
int				**minimize_tet(int **tet_list, int tet, int i);
int				racinecarre(int num);

int				losesomedots(char map[20][20], int **storage, int minsize);
int				readmap(char map[20][20], int **storage, int minsize, char c);
void			replacewdots(char map[20][20], int **storage, int x, int y);
int				tetplacer(char map[20][20], t_pams p);

int				losesomedots(char map[20][20], int **storage, int minsize);
int				readmap(char map[20][20], int **storage, int minsize, char c);
void			replacewdots(char map[20][20], int **storage, int x, int y);

void			imprimante(char map[20][20], int size);
void			fillwdots(char map[20][20], int size);
#endif
