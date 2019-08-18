/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:45:11 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/17 20:10:08 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < na && j < nb)
	{
		if (a[i] > b[j])
			j++;
		else if (a[i] < b[j])
			i++;
		else
		{
			if (flag > 0)
				printf(" ");
			printf("%d", a[i]);
			i++;
			j++;
			flag = 1;
		}
	}
	printf("\n");
}

//int main()
//{
//	int a[] = { -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
//	int b[] = {2,  4,  5,  6,  7, 10,  40,  70};
//	print_doublon(a, 11, b,8);
//}
