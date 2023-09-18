/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:20:43 by cmateos           #+#    #+#             */
/*   Updated: 2023/09/16 11:20:44 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

int	ft_init(t_data data)
{
	data.philo = malloc(data.nbr_philos * sizeof(t_philo));
	if (!data.philo)
		return (ft_error(0, data));
	data.tpid = malloc(data.nbr_philos * sizeof(pthread_t));
	if (!data.tpid)
		return (ft_error(0, data));
	data.fork = malloc(data.nbr_philos * sizeof(pthread_mutex_t));
	if(!data.fork)
		return(ft_error(0, data));
	return (0);
}

int	ft_check_av(char **av, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (-1);
		}
	}
	data->nbr_philos = atoi(av[1]);
	data->time_to_die = atoi(av[2]);
	data->time_to_eat = atoi(av[3]);
	data->time_to_sleep = atoi(av[4]);
	if (av[5])
		data->meal_count = atoi(av[5]);
	if (data->nbr_philos < 1 || data->nbr_philos > 200
		||data->time_to_die < 0 || data->meal_count < 0)
		return (-1);
	return (0);
}
