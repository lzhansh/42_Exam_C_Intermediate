/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:22:48 by lzhansha          #+#    #+#             */
/*   Updated: 2019/08/17 19:43:42 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_anagram(char *a, char *b)
{
	int arr[95] = {0};
	int i;
	
	while (*a)
	{
		arr[((int)(*a) - 32)] += 1;
		a++;
	}
	while (*b)
	{
		arr[((int)(*b) - 32)] -= 1;
		b++;
	}
	i = -1;
	while (++i < 95)
		if (arr[i] != 0)
			return (0);
	return (1);
}

//int main()
//{
//	char *str1 = "iceman";
//	char *str2 = "cinema";
//	printf("%d\n",is_anagram(str1, str2));
//}
