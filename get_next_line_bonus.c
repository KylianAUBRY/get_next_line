/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:16:05 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/17 23:27:49 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[1025][BUFFER_SIZE + 1];
	char		*dest;
	int			i;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (0);
	if (ft_chr(buff[fd]) == 1)
	{
		ft_buf_cut(buff[fd]);
		dest = ft_join(dest, buff[fd]);
	}
	while (i > 0 && ft_chr(buff) == 0)
	{
		i = read(fd, buff[fd], BUFFER_SIZE);
		if (i <= 0)
			return (dest);
		buff[fd][i] = '\0';
		dest = ft_join(dest, buff[fd]);
	}
	return (dest);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int i;

	i = open("read_error.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));

	return (0);
}*/
