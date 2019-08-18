/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:07:24 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/17 19:20:03 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int find_pivot(int *arr, int n)
{
	int sum_left;
	int sum_right;
	int i;

	i = -1;
	sum_right = 0;
	sum_left = 0;
	while (++i < n)
		sum_right += arr[i];
	i = -1;
	while (++i < n)
	{
		sum_right -= arr[i];
		if (sum_right == sum_left)
			return (i);
		sum_left += arr[i];
	}
	return (-1);
}

//int main()
//{
//	int arr[] = {1, 100, 0, 0, 1};
//	printf("%d\n", find_pivot(arr, 5));
//}
