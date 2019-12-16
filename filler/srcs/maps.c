/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:12:33 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/14 12:10:20 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data		ft_make_map(char *line, t_data data, int cnt)
{
	if (data.map == NULL)
	{
		while (line[cnt] && !(ft_isdigit(line[cnt])))
			cnt++;
		data.map_cor.x = ft_atoi(&line[cnt]);
		if (!(data.map = (char **)malloc(sizeof(char *) *
						(data.map_cor.x + 1))))
			data = ft_free_error(data, NULL);
		data.map[data.map_cor.x] = NULL;
		while (line[cnt] && ft_isdigit(line[cnt]))
			cnt++;
		data.map_cor.y = ft_atoi(&line[cnt + 1]);
		cnt = 0;
		while (data.finish && cnt < data.map_cor.x)
		{
			if (!(data.map[cnt] = (char *)malloc(sizeof(char) *
						(data.map_cor.y + 1))))
				data = ft_free_error(data, NULL);
			data.map[cnt] = (char *)ft_memset(data.map[cnt], '.',
					data.map_cor.y);
			data.map[cnt++][data.map_cor.y] = '\0';
		}
	}
	return (ft_cpy_map(data, line));
}

t_data		ft_cpy_map(t_data data, char *line)
{
	int		cnt;

	cnt = 0;
	free(line);
	get_next_line(0, &line);
	free(line);
	while (cnt < data.map_cor.x)
	{
		get_next_line(0, &line);
		data.map[cnt] = ft_strcpy(data.map[cnt], line + 4);
		cnt++;
		free(line);
	}
	if (!data.mapn)
		data = ft_make_mapn(data);
	data = ft_get_fighter(data);
	return (data);
}

t_data		ft_get_piece(t_data data, char *line)
{
	int		cnt;
	char	**piece;

	cnt = 0;
	while (line[cnt] && !(ft_isdigit(line[cnt])))
		cnt++;
	data.pic_cor.x = ft_atoi(&line[cnt]);
	while (line[cnt] && ft_isdigit(line[cnt]))
		cnt++;
	data.pic_cor.y = ft_atoi(&line[cnt + 1]);
	free(line);
	if (!(piece = (char **)malloc(sizeof(char *) * (data.pic_cor.x + 1))))
		data = ft_free_error(data, NULL);
	piece[data.pic_cor.x] = NULL;
	cnt = 0;
	while (data.finish && cnt < data.pic_cor.x)
	{
		get_next_line(0, &line);
		if (!(piece[cnt] = (char *)malloc(sizeof(char) * (data.pic_cor.y + 1))))
			data = ft_free_error(data, piece);
		piece[cnt++][data.pic_cor.y] = '\0';
		piece[cnt - 1] = ft_strcpy(piece[cnt - 1], line);
		free(line);
	}
	return (ft_pos_piece(data, piece));
}

t_data		ft_pos_piece(t_data data, char **piece)
{
	int		cnt;
	int		cnt1;

	cnt = 0;
	data.nb_pic = 0;
	while (piece[cnt])
	{
		cnt1 = 0;
		while (piece[cnt][cnt1])
		{
			if (piece[cnt][cnt1] == '*')
				data.nb_pic++;
			if (data.nb_pic == 1 && piece[cnt][cnt1] == '*')
			{
				data.pos_1[0] = cnt;
				data.pos_1[1] = cnt1;
			}
			cnt1++;
		}
		cnt++;
	}
	if (!(data.p_pos = (t_pos *)malloc(sizeof(t_pos) * data.nb_pic)))
		data = ft_free_error(data, piece);
	return (ft_pos_piece2(data, piece));
}

t_data		ft_pos_piece2(t_data data, char **piece)
{
	int cnt;
	int cnt1;

	cnt = 0;
	data.nb_pic = 0;
	while (piece[cnt] != NULL)
	{
		cnt1 = 0;
		while (piece[cnt][cnt1])
		{
			if (piece[cnt][cnt1] == '*')
			{
				data.p_pos[data.nb_pic].x = cnt;
				data.p_pos[data.nb_pic].y = cnt1;
				data.nb_pic++;
			}
			cnt1++;
		}
		cnt++;
	}
	ft_free_tab(piece);
	return (ft_min(data));
}
