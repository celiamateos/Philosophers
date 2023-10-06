/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:20:48 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/26 17:20:50 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

int	len_array(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
		i++;
	return (i);
}

int	ft_isdigit(char **av, int i)
{
	int	j;

	if (av)
	{
		while (av[i] != NULL)
		{
			j = -1;
			while (av[i][++j])
			{
				if (av[i][j] < '0' || av[i][j] > '9')
					return (-1);
			}
			i++;
		}
	}
	return (0);
}

void	ft_free_array(char **arr)
{
	int	i;
	int	len_arr;

	i = 0;
	len_arr = len_array(arr);
	while (i < len_arr + 1)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_invalid_nbr(char **args, int i)
{
	long	check;

	if (!args)
		return (1);
	while (args[i] != NULL)
	{
		check = ft_atol(args[i]);
		if (check < 0)
			return (1);
		if (check > (long)INT_MAX || check < (long)INT_MIN)
		{
			printf("Error\n param is too big or too small.");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int		i;
	char	**args;

	i = 1;
	if (ac != 5 && ac != 6 && ac != 2)
		return (1);
	if (ac == 2)
	{
		i = 0;
		args = ft_split(av[1], 32);
		if (len_array(args) != 4 && len_array(args) != 5)
		{
			ft_free_array(args);
			return (1);
		}
	}
	else
		args = av;
	if (ft_isdigit(args, i) || ft_invalid_nbr(args, i))
		i = -1;
	if (ac == 2)
		ft_free_array(args);
	if (i == -1)
		return (1);
	return (0);
}
