/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataInit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:24:20 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/23 16:52:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"
#include <stdio.h>

t_data	*get_data(void)
{
	static t_data	*data = 0;

	if (data == 0)
		data = ft_scalloc(1, sizeof(t_data));
	return (data);
}

void	data_malloc(void)
{
	t_data	*data;

	data = get_data();
	data->input = ft_scalloc(1, sizeof(t_input));
	data->libx = ft_scalloc(1, sizeof(t_libx));
	data->map = ft_scalloc(1, sizeof(t_map));
	data->player = ft_scalloc(1, sizeof(t_player));
	data->texture = ft_scalloc(1, sizeof(t_texture));
}

void	data_init(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	data_malloc();
	libx_init();
	input_init();
	map_init();
	player_init();
}
