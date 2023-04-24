/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputInit01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:52:39 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/24 12:39:21 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../02.Incs/data.h"
#include "../../02.Incs/util.h"
#include "../../02.Incs/libft.h"

void	temp_init(t_input *input)
{
	input->floor = ft_strdup("F 220,100,0");
	input->ceiling = ft_strdup("C 225,30,0");
	input->no_png = ft_strdup("NO ./05.Files/N.png");
	input->so_png = ft_strdup("NO ./05.Files/S.png");
	input->ea_png = ft_strdup("NO ./05.Files/E.png");
	input->we_png = ft_strdup("NO ./05.Files/W.png");
	input->map = (char **)ft_smalloc(sizeof(char *) * (14 + 1));
	input->map[0] = ft_strdup("        1111111111111111111111111");
	input->map[1] = ft_strdup("        1000000000110000000000001");
	input->map[2] = ft_strdup("        1011000001110000000000001");
	input->map[3] = ft_strdup("        1001000000000000000000001");
	input->map[4] = ft_strdup("111111111011000001110000000000001");
	input->map[5] = ft_strdup("100000000011000001110111111111111");
	input->map[6] = ft_strdup("11110111111111011100000010001");
	input->map[7] = ft_strdup("11110111111111011101010010001");
	input->map[8] = ft_strdup("11000000110101011100000010001");
	input->map[9] = ft_strdup("10000000000000001100000010001");
	input->map[10] = ft_strdup("10000000000000001101010010001");
	input->map[11] = ft_strdup("11000001110101011111011110N0111");
	input->map[12] = ft_strdup("11110111 1110101 101111010001");
	input->map[13] = ft_strdup("11111111 1111111 111111111111");
	input->map[14] = 0;
}

void	input_init(void)
{
	t_input	*input;

	input = get_data()->input;
	temp_init(input);
}
