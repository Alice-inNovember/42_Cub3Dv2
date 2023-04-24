/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerInit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:56:37 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/23 16:58:05 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"

void	dir_plane_init(t_player *player, char face)
{
	if (face == 'E')
	{
		player->dir_x = -1.0;
		player->plane_y = 0.66;
	}
	else if (face == 'W')
	{
		player->dir_x = 1.0;
		player->plane_y = -0.66;
	}
	else if (face == 'S')
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (face == 'N')
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
}

void	player_init(void)
{
	t_player	*player;
	char		face;

	player = get_data()->player;
	get_player_data(&player->pos_x, &player->pos_y, &face);
	dir_plane_init(player, face);
}
