/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:48:17 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/17 17:33:34 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>
# include "data.h"

void	err_exit(char *str);
void	*ft_smalloc(size_t size);
void	*ft_scalloc(size_t count, size_t size);

void	test_input(t_data *data);

#endif