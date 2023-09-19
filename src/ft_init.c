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

void	ft_init_philos(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	data->philo_id = malloc(data->nbr_philos * sizeof(pthread_t));
	if (!data->philo_id)
		ft_error(0, data, philo);
	while (i < data->nbr_philos)
	{
		philo[i].pdata = data;
		philo[i].death_time = data->time_to_die;
		philo[i].philo_num = i + 1;
		philo[i].meal_counter = 0;
		i++;
	}
	i = 0;
	/*while (1 < data->nbr_philos)
	{
		pthread_create(&data->philo_id[i], NULL, s, (void *)&philo[i]);
		i++;
	}*/
}

void	ft_init_fork(t_data *data, t_philo *philo)
{
	int i;

	i = -1;
	data->fork = malloc(data->nbr_philos * sizeof(pthread_mutex_t));
	if(!data->fork)
		ft_error(0, data, philo);
	while(++i < data->nbr_philos)
		pthread_mutex_lock(&data->fork[++i]);	
}

int	ft_init(t_data *data, t_philo *philo)
{
	ft_init_fork(data, philo);
	ft_init_philos(data, philo);
	data->start_time = get_time();
	//printf("%ld", data->start_time);
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