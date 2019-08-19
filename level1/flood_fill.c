/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:50:07 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/18 23:28:11 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void f_fill(char **area, t_point size, char tgt, int row, int col)
{
	if (row >= size.y || col >= size.x || row < 0 || col < 0)
		return;
	if (area[row][col] != tgt || area[row][col] == 'F')
		return;
	area[row][col] = 'F';
	f_fill(area, size, tgt, row - 1, col);
	f_fill(area, size, tgt, row + 1, col);
	f_fill(area, size, tgt, row, col - 1);
	f_fill(area, size, tgt, row, col + 1);
}

void  flood_fill(char **area, t_point size, t_point begin)
{
	char target;

	target = tab[begin.y][begin.x];
	f_fill(area, size, target, begin.y, begin.x);
}
