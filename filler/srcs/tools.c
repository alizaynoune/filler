/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:07:40 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/14 12:09:55 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data		ft_print(t_data data, int saf)
{
	if (saf == 2)
	{
		ft_putnbr(data.prf[0].x - data.pos_1[0]);
		ft_putchar(' ');
		ft_putnbr(data.prf[0].y - data.pos_1[1]);
		ft_putchar('\n');
		free(data.prf);
	}
	else
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		ft_free_tab(data.map);
		ft_free_tab_int(data.mapn, data.map_cor.x);
		data.finish = 0;
	}
	free(data.p_pos);
	free(data.cpy_p);
	return (data);
}

t_data		ft_copy_pos(t_data data)
{
	int		cnt;

	cnt = 0;
	while (cnt < data.nb_pic)
	{
		data.prf[cnt].x = data.p_pos[cnt].x;
		data.prf[cnt].y = data.p_pos[cnt].y;
		cnt++;
	}
	return (data);
}

t_data		ft_get_mychar(t_data data, char *line)
{
	if (ft_strstr(line, "p1"))
		data.my_ch = 'O';
	else if (ft_strstr(line, "p2"))
		data.my_ch = 'X';
	data.fgt_ch = data.my_ch == 'O' ? 'X' : 'O';
	free(line);
	return (data);
}

t_data		ft_min(t_data data)
{
	int		cnt;
	int		min[2];

	cnt = 0;
	min[0] = data.p_pos[0].x;
	min[1] = data.p_pos[0].y;
	if (!(data.cpy_p = (t_pos *)malloc(sizeof(t_pos) * data.nb_pic)))
		data = ft_free_error(data, NULL);
	while (++cnt < data.nb_pic)
	{
		min[0] = min[0] > data.p_pos[cnt].x ? data.p_pos[cnt].x : min[0];
		min[1] = min[1] > data.p_pos[cnt].y ? data.p_pos[cnt].y : min[1];
	}
	cnt = 0;
	while (cnt < data.nb_pic)
	{
		data.p_pos[cnt].x -= min[0];
		data.p_pos[cnt].y -= min[1];
		data.cpy_p[cnt].x = data.p_pos[cnt].x;
		data.cpy_p[cnt].y = data.p_pos[cnt].y;
		cnt++;
	}
	data.min_p.x = min[0];
	data.min_p.y = min[1];
	return (ft_max(data));
}

t_data		ft_max(t_data data)
{
	int		cnt;
	int		x;
	int		y;

	cnt = 0;
	x = data.p_pos[0].x;
	y = data.p_pos[0].y;
	while (cnt < data.nb_pic)
	{
		x = x < data.p_pos[cnt].x ? data.p_pos[cnt].x : x;
		y = y < data.p_pos[cnt].y ? data.p_pos[cnt].y : y;
		cnt++;
	}
	data.max_p.x = x;
	data.max_p.y = y;
	data.max_cp.x = x;
	data.max_cp.y = y;
	data = ft_move(data);
	return (data);
}
