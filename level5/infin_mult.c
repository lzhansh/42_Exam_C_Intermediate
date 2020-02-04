/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:55:12 by lzhansha          #+#    #+#             */
/*   Updated: 2020/02/03 17:18:42 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void infin_mult(char* res, int *len, char *n1, char *n2)
{
	int len1;
	int len2;
	int tmp = 0;

	len1 = ft_strlen(n1);
	len2 = ft_strlen(n2);

	for (int i = 0; i < len1 + len2; i++)
		res[i] = '0';
	res[len1 + len2] = '\0';

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			tmp = ((n1[len1 - 1 - i] - '0') * (n2[len2 - 1 - j] - '0')) + res[len1 + len2 -i-j-1] - '0';
			res[len1 + len2 - i - j - 1] = (tmp % 10) + '0';
			res[len1 + len2 -i -j -2] += tmp/10;
		}
	}
	*len = (len1 + len2 - (res[0] == '0' ? 1 : 0));

}

int main(int ac, char **av)
{
	char res[4096];
	int len = 0;

	if (ac == 3)
	{
		if (av[1][0] == '0' || av[2][0] == '0')
		   write(1, "0", 1);
		else
		{
			if ((av[1][0] == '-' || av[2][0] == '-') && !(av[1][0] != '-' && av[2][0] != '-'))
				write(1, "-", 1);
			av[1] += (av[1][0] == '-' ? 1 : 0);
			av[2] += (av[2][0] == '-' ? 1 : 0);

			infin_mult(res, &len, av[1], av[2]);

			write(1, res + (res[0] == '0' ? 1 : 0), len);
		}	
	}
	write(1, "\n", 1);
	return (0);
}
