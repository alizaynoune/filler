/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:08:27 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/14 12:07:04 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdlib.h>
# include "../next_line/get_next_line.h"
# include <stdio.h>

# define PLAT	("Plateau")
# define DEF	("\e[0m")
# define RED	("\e[1;31m")
# define GREEN	("\e[32;1m")
# define YELLOW	("\e[1;33m")
# define NOP	("-nop")

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_data
{
	t_pos		map_cor;
	t_pos		pic_cor;
	t_pos		min_p;
	t_pos		max_p;
	t_pos		max_cp;
	t_pos		pos_r;
	char		**map;
	int		**mapn;
	char		my_ch;
	char		fgt_ch;
	t_pos		*p_pos;
	t_pos		*cpy_p;
	int			pos_1[2];
	int			nb_pic;
	t_pos		*prf;
	int			finish;
}				t_data;

t_data			ft_make_map(char *line, t_data data, int cnt);
t_data			ft_cpy_map(t_data data, char *line);
t_data			ft_get_mychar(t_data data, char *line);
t_data			ft_get_piece(t_data data, char *line);
t_data			ft_pos_piece(t_data data, char **piece);
void			ft_free_tab(char **tab);
t_data			ft_min(t_data data);
t_data			ft_max(t_data data);
t_data			ft_get_fighter(t_data data);
t_data			ft_make_mapn(t_data data);
t_data			ft_move(t_data data);
t_data			ft_get_perfect(t_data data, int frst);
int				ft_saf(t_data data);
t_data			ft_move_y_x(t_data data, char c);
t_data			ft_get_fighter4(t_data data);
void			ft_free_tab_int(int **tab, int line);
t_data			ft_print(t_data data, int saf);
t_data			ft_get_perfect2(t_data data);
t_data			ft_pos_piece2(t_data data, char **piece);
t_data			ft_free_error(t_data data, char **tab);
t_data			ft_copy_pos(t_data data);
t_data			heat_map(t_data data);
int				finde0(int **tab, t_data data);
t_data			heat_map2(t_data data);
t_data			heat_map3(t_data data, int cnt, int cnt1);
#endif
