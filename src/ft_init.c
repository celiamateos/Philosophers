/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student42madridcom>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:20:43 by cmateos           #+#    #+#             */
/*   Updated: 2023/09/16 11:20:44 by cmateos-         ###   ########fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

long	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == 0)
	{
        printf("\nSegundos: %ld", current_time.tv_sec);
        printf("\nMicrosegundos: %ld", current_time.tv_usec);
	}
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	ft_init(t_data *data, t_philo *philo)
{
	data->tpid = malloc(data->nbr_philos * sizeof(pthread_t));
	if (!data->tpid)
		return (ft_error(0, data, philo));
	data->fork = malloc(data->nbr_philos * sizeof(pthread_mutex_t));
	if(!data->fork)
		return(ft_error(0, data, philo));
	data->start_time = get_time();
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