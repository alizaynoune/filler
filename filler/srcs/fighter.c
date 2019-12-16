/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fighter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:00:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/12 17:46:31 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data		ft_get_fighter(t_data data)
{
	int		cnt;
	int		cnt1;

	cnt = 0;
	while (cnt < data.map_cor.x)
	{
		cnt1 = 0;
		while (cnt1 < data.map_cor.y)
			data.mapn[cnt][cnt1++] = 0;
		cnt++;
	}
	data = heat_map(data);
	return (data);
}

t_data		heat_map(t_data data)
{
	int		cnt;
	int		cnt1;

	cnt = 0;
	while (data.map[cnt])
	{
		cnt1 = 0;
		while (data.map[cnt][cnt1])
		{
			if (data.map[cnt][cnt1] == data.fgt_ch)
				data.mapn[cnt][cnt1] = -1;
			cnt1++;
		}
		cnt++;
	}
	return (heat_map2(data));
}

t_data		heat_map2(t_data data)
{
	int cnt;
	int cnt1;

	cnt = -1;
	while (++cnt < data.map_cor.x)
	{
		cnt1 = -1;
		while (++cnt1 < data.map_cor.y)
		{
			if (data.mapn[cnt][cnt1] == -1)
			{
				if (cnt1 + 1 < data.map_cor.y && data.mapn[cnt][cnt1 + 1] == 0)
					data.mapn[cnt][cnt1 + 1] = 1;
				if (cnt1 > 0 && data.mapn[cnt][cnt1 - 1] == 0)
					data.mapn[cnt][cnt1 - 1] = 1;
				if (cnt + 1 < data.map_cor.x && data.mapn[cnt + 1][cnt1] == 0)
					data.mapn[cnt + 1][cnt1] = 1;
				if (cnt > 0 && data.mapn[cnt - 1][cnt1] == 0)
					data.mapn[cnt - 1][cnt1] = 1;
			}
		}
	}
	while (!finde0(data.mapn, data))
		data = heat_map3(data, -1, -1);
	return (data);
}

t_data		heat_map3(t_data data, int cnt, int cnt1)
{
	while (++cnt < data.map_cor.x)
	{
		cnt1 = -1;
		while (++cnt1 < data.map_cor.y)
		{
			if (data.mapn[cnt][cnt1] > 0)
			{
				if (cnt1 + 1 < data.map_cor.y && (!data.mapn[cnt][cnt1 + 1] ||
						data.mapn[cnt][cnt1 + 1] > data.mapn[cnt][cnt1] + 1))
					data.mapn[cnt][cnt1 + 1] = data.mapn[cnt][cnt1] + 1;
				if (cnt1 > 0 && (!data.mapn[cnt][cnt1 - 1] ||
						data.mapn[cnt][cnt1 - 1] > data.mapn[cnt][cnt1] + 1))
					data.mapn[cnt][cnt1 - 1] = data.mapn[cnt][cnt1] + 1;
				if (cnt + 1 < data.map_cor.x && (!data.mapn[cnt + 1][cnt1] ||
						data.mapn[cnt + 1][cnt1] > data.mapn[cnt][cnt1] + 1))
					data.mapn[cnt + 1][cnt1] = data.mapn[cnt][cnt1] + 1;
				if (cnt > 0 && (!data.mapn[cnt - 1][cnt1] ||
						data.mapn[cnt - 1][cnt1] > data.mapn[cnt][cnt1] + 1))
					data.mapn[cnt - 1][cnt1] = data.mapn[cnt][cnt1] + 1;
			}
		}
	}
	return (data);
}

int			finde0(int **tab, t_data data)
{
	int cnt;
	int cnt1;

	cnt = 0;
	while (cnt < data.map_cor.x)
	{
		cnt1 = 0;
		while (cnt1 < data.map_cor.y)
		{
			if (tab[cnt][cnt1] == 0)
				return (0);
			cnt1++;
		}
		cnt++;
	}
	return (1);
}
