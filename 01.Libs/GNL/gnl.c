/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:51:24 by junlee2           #+#    #+#             */
/*   Updated: 2023/04/15 15:41:17 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <malloc/_malloc.h>
#include <unistd.h>

char	*get_line(int fd, int cnt)
{
	char	buffer;
	char	*line;

	if (read(fd, &buffer, 1) != 1 || buffer == '\n')
	{
		if (cnt == 0)
			return (0);
		line = malloc(sizeof(char) * (cnt + 1));
		if (!line)
			return (0);
		line[cnt] = 0;
		return (line);
	}
	line = get_line(fd, cnt + 1);
	if (!line)
		return (0);
	line[cnt] = buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0)
		return (0);
	return (get_line(fd, 0));
}
