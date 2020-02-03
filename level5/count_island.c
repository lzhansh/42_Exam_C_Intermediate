/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:52:28 by lzhansha          #+#    #+#             */
/*   Updated: 2020/02/03 14:21:16 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 10000

void	ft_fill(char *buf, int size, int col, int i, char ch)
{
	if (i < 0 || i > size || buf[i] != 'X')
		return ;
	buf[i] = ch;

	ft_fill(buf, size, col, i + 1, ch);
	ft_fill(buf, size, col, i + col, ch);
	ft_fill(buf, size, col, i - col, ch);
	ft_fill(buf, size, col, i - 1, ch);
}

void	count_island(char *buf, int size)
{
	int col = 0;
	char ch = '0';

	while (buf[col] != '\n' && buf[col])
		col++;

	for (int i = 0; buf[i]; i++)
		if ((buf[i] != '.' && buf[i] != 'X' && i % col != col) || (buf[i] != '\n' && i % col == col))
			return;

	for (int i = 0; buf[i]; i++)
		if (buf[i] == 'X')
			ft_fill(buf, size, col + 1, i, ch++);
	write(1, buf, size);
}

int main(int ac, char **av)
{
	int fd;
	int rd;
	char buff[BUFF_SIZE];

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
		{
			rd = read(fd, buff, BUFF_SIZE);
			if (rd > 0)
			{
				buff[rd] = 0;
				count_island(buff, rd);
			}
			close(fd);
		}
	}
	write(1, "\n", 1);
	return (0);
}
