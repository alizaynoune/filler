/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:13:21 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/14 12:09:20 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_data	data;
	char	*line;

	data.map = NULL;
	data.mapn = NULL;
	data.finish = 1;
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "alzaynou"))
			data = ft_get_mychar(data, line);
		else if (ft_strstr(line, "Plateau"))
			data = ft_make_map(line, data, 0);
		else if (ft_strstr(line, "Piece"))
			data = ft_get_piece(data, line);
		else
			free(line);
		if (!data.finish)
			break ;
	}
	return (0);
}
