/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:21:32 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/17 17:24:45 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	check_2(int n, int *count)
{
	if (n >= 10)
	{
		check_2(n / 10, count);
		check_2(n % 10, count);
	}
	if (n == 2)
		(*count)++;
}

int    count_of_2(int n)
{
	int count;

	count = 0;
	if (n <= 1)
		return (0);
	while (n)
		check_2(n--, &count);	
	return (count);
}	

//int main()
//{
//	printf("%d\n",count_of_2(25));
//}
