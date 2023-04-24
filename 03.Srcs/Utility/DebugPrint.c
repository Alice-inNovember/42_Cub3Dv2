/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebugPrint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:49:53 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/24 12:18:39 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"
#include <unistd.h>
#include <stdio.h>

void	print_map(void)
{
	t_data	*data;
	int		i;
	int		w;

	data = get_data();
	w = ft_strlen(data->map->map[1]) + 2;
	write(1, "--------------------------------------------------", w);
	write(1, "\n", 1);
	i = 0;
	while (data->map->map[i])
	{
		write(1, "|", 1);
		ft_putstr_fd(data->map->map[i], 1);
		write(1, "|\n", 2);
		i++;
	}
	write(1, "--------------------------------------------------", w);
	write(1, "\n", 1);
}

void	print_data(void)
{
	t_data	*data;

	data = get_data();
	print_map();
	printf("Pos : x%d y%d\n", \
	(int)data->player->pos_x, (int)data->player->pos_y);
	printf("Mlx : %p\n", data->libx->mlx);
	printf("Win : %p\n", data->libx->win);
}
