/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapInit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:06:53 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/23 16:59:06 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"

int	map_hight(void)
{
	t_data	*data;
	int		size;

	data = get_data();
	size = 0;
	while (get_data()->input->map[size])
		size++;
	return (size);
}

int	map_width(void)
{
	t_data	*data;
	int		i;
	int		max;
	int		len;

	i = 0;
	max = 0;
	data = get_data();
	while (data->input->map[i])
	{
		len = ft_strlen(data->input->map[i]);
		if (max < len)
			max = len;
		i++;
	}
	return (max);
}

void	map_init(void)
{
	t_map	*map;
	int		hight;
	int		width;
	int		i;
	int		j;

	map = get_data()->map;
	hight = map_hight();
	width = map_width();
	i = 0;
	map->map = ft_smalloc(sizeof(char *) * (hight + 1));
	while (i < hight)
	{
		map->map[i] = ft_scalloc(width + 1, sizeof(char));
		ft_memset(map->map[i], ' ', sizeof(char) * width);
		j = 0;
		while (get_data()->input->map[i][j])
		{
			map->map[i][j] = get_data()->input->map[i][j];
			j++;
		}
		map->map[i][width] = 0;
		i++;
	}
	map->map[hight] = 0;
}
