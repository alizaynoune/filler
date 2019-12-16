/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:42:46 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/12 17:47:04 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data		ft_make_mapn(t_data data)
{
	int		cnt;

	cnt = 0;
	if (!(data.mapn = (int **)malloc(sizeof(int *) * data.map_cor.x)))
		data = ft_free_error(data, NULL);
	while (cnt < data.map_cor.x)
	{
		if (!(data.mapn[cnt++] = (int *)malloc(sizeof(int) * data.map_cor.y)))
			data = ft_free_error(data, NULL);
	}
	return (data);
}
