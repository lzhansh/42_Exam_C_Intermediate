#include <stdlib.h>
#include <unistd.h>

int ft_atoi(char *str)
{
	int res = 0;

	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n/10);
	char rem = (n % 10) + '0';
	write(1, &rem, 1);
}

int find_max(char *str)
{
	int max = 0;
	int a;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			a = ft_atoi(str);
		while (*str >= '0' && *str <= '9' && *str)
			str++;
		if (a > max)
			max = a;
		while (*str == '-' || *str == ' ')
			str++;
	}
	return (max);
}

void fill_arr(int **arr, char *str)
{
	int a;
	int b;

	while (*str)
	{
		a = ft_atoi(str);
		while (*str >= '0' && *str <= '9' && *str)
			str++;
		while (*str == '-')
			str++;
		b = ft_atoi(str);
		while (*str >= '0' && *str <= '9' && *str)
			str++;
		while (*str == ' ')
			str++;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
}

void	g_diam(int* vector, int **arr, int max, int *res, int local, int i)
{
	vector[i] = 1;

	for (int j = 0; j <= max; j++)
	{
		if (vector[j] == 0 && arr[i][j] != 0)
		{
			if (*res <= local)
				*res = local + 1;
			g_diam(vector, arr, max, res, local + 1, j);
		}
	}
	vector[i] = 0;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int max = find_max(av[1]);
		int **arr = malloc(sizeof(int *) * (max + 1));
		int *vector = malloc(sizeof(int) * (max + 1));
		for (int i = 0; i <= max; i++)
		{
			vector[i] = 0;
			arr[i] = malloc(sizeof(int) * (max+1));
			for (int j = 0; j <= max; j++)
				arr[i][j] = 0;
		}
		fill_arr(arr, av[1]);
		
		int res = 2;
		for (int i = 0; i <= max; i++)
			g_diam(vector, arr, max, &res, 1, i);
		ft_putnbr(res);
	}
	write(1, "\n", 1);
	return (0);
}
