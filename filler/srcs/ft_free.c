/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:55:54 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/11 16:58:28 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_data		ft_free_error(t_data data, char **tab)
{
	if (data.map)
		ft_free_tab(data.map);
	if (data.mapn)
		ft_free_tab_int(data.mapn, data.map_cor.x);
	if (data.cpy_p)
		free(data.cpy_p);
	if (data.p_pos)
		free(data.p_pos);
	if (tab)
		ft_free_tab(tab);
	if (data.prf)
		free(data.prf);
	data.map_cor.x = 0;
	data.map_cor.y = 0;
	data.pic_cor.x = 0;
	data.pic_cor.y = 0;
	data.nb_pic = 0;
	data.finish = 0;
	return (data);
}

void		ft_free_tab_int(int **tab, int line)
{
	int		cnt;

	cnt = 0;
	while (tab[cnt] && cnt < line)
		free(tab[cnt++]);
	free(tab);
	tab = NULL;
}

void		ft_free_tab(char **tab)
{
	int	cnt;

	cnt = 0;
	while (tab[cnt])
		free(tab[cnt++]);
	free(tab);
	tab = NULL;
}
