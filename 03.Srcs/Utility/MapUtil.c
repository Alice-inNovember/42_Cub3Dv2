/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapUtil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:25:15 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/23 16:37:47 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"

void	get_player_data(double *x, double *y, char *face)
{
	t_map	*map;
	int		i;
	int		j;

	map = get_data()->map;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (\
			map->map[i][j] == 'N' || \
			map->map[i][j] == 'S' || \
			map->map[i][j] == 'E' || \
			map->map[i][j] == 'W')
			{
				*x = (double)j;
				*y = (double)i;
				*face = map->map[i][j];
			}
			j++;
		}
		i++;
	}
}
