/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:16:23 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/12 17:37:26 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data		ft_move(t_data data)
{
	int		cnt;
	int		frst;
	int		saf;

	cnt = 0;
	frst = 0;
	saf = 0;
	while (data.max_p.x < data.map_cor.x)
	{
		while (data.max_p.y < data.map_cor.y)
		{
			if (ft_saf(data))
			{
				data = ft_get_perfect(data, frst++);
				saf = 2;
			}
			data = ft_move_y_x(data, 'y');
		}
		data = ft_move_y_x(data, 'x');
	}
	return (ft_print(data, saf));
}

t_data		ft_get_perfect(t_data data, int frst)
{
	if (frst == 0)
	{
		if (!(data.prf = (t_pos *)malloc(sizeof(t_pos) * data.nb_pic)))
			data = ft_free_error(data, NULL);
		return (ft_copy_pos(data));
	}
	return (ft_get_perfect2(data));
}

t_data		ft_get_perfect2(t_data data)
{
	int		cnt;
	t_pos	prf;

	cnt = 0;
	prf.x = 0;
	prf.y = 0;
	while (cnt < data.nb_pic)
	{
		if (data.mapn[data.prf[cnt].x][data.prf[cnt].y] >
				data.mapn[data.p_pos[cnt].x][data.p_pos[cnt].y])
			prf.x++;
		if (data.mapn[data.prf[cnt].x][data.prf[cnt].y] <
				data.mapn[data.p_pos[cnt].x][data.p_pos[cnt].y])
			prf.y++;
		cnt++;
	}
	if (prf.x > prf.y)
		return (ft_copy_pos(data));
	return (data);
}

int			ft_saf(t_data data)
{
	int		cnt;
	int		conect;

	cnt = 0;
	conect = 0;
	while (cnt < data.nb_pic)
	{
		if (data.map[data.p_pos[cnt].x][data.p_pos[cnt].y] != '.' &&
				data.map[data.p_pos[cnt].x][data.p_pos[cnt].y] != data.my_ch)
			return (0);
		if (data.map[data.p_pos[cnt].x][data.p_pos[cnt].y] == data.my_ch)
			conect++;
		cnt++;
	}
	if (conect != 1)
		return (0);
	return (1);
}

t_data		ft_move_y_x(t_data data, char c)
{
	int		cnt;

	cnt = 0;
	if (c == 'y')
	{
		while (cnt < data.nb_pic)
			data.p_pos[cnt++].y++;
		data.max_p.y++;
	}
	else if (c == 'x')
	{
		data.max_p.y = data.max_cp.y;
		while (cnt < data.nb_pic)
		{
			data.p_pos[cnt].y = data.cpy_p[cnt].y;
			cnt++;
		}
		cnt = 0;
		while (cnt < data.nb_pic)
			data.p_pos[cnt++].x++;
		data.max_p.x++;
	}
	return (data);
}
