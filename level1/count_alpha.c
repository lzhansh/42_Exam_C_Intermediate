/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:58:53 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/18 22:43:17 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int not_seen(char* str, char c, int n)
{
	int i;

	i = -1;
	while (++i < n)
		if (str[i] == c)
			return (0);
	return (1);
}

int main(int ac, char **av)
{
	int num[32] = {0};
	int i;
	int flag;

	if (ac == 2)
	{
		flag = 0;
		i = -1;
		while (av[1][++i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += 32;
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				num[(int)(av[1][i]) - 97] += 1;
		}
		i = -1;
		while (av[1][++i])
		{
			if (num[(int)(av[1][i]) - 97] != 0 && not_seen(av[1], av[1][i], i))
			{
				if (flag == 1)
					printf(", ");
				flag = 1;
				printf("%d%c", num[(int)(av[1][i]) - 97], av[1][i]);
			}
		}
	}
	printf("\n");
	return (0);
}
