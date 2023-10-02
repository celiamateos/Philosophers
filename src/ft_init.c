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

int	ft_init_data(int ac, char **av, t_data *data)
{
	int i;
	char **args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	data->nbr_philos = atoi(args[i]);
	data->time_to_die = atoi(args[i + 1]);
	data->time_to_eat = atoi(args[i + 2]);
	data->time_to_sleep = atoi(args[i + 3]);
	data->philo_died = 0;
	if (args[i + 4] != NULL)
		data->meal_count = atoi(args[i + 4]);
	else
		data->meal_count = 100;
	if (ac == 2)
		ft_free_array(args);
	if (data->nbr_philos < 1 || data->nbr_philos > 200
		||data->time_to_die < 0 || data->meal_count < 0)
		return(free(data), 1);
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int i;

	data->m_fork = ft_calloc(data->nbr_philos, sizeof(pthread_mutex_t *));
	data->m_philo_died = ft_calloc(1, sizeof(pthread_mutex_t));
	if(!data->m_fork)
		return (free(data), 1);
	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_init(&data->m_fork[i], NULL);	
		i++;
	}
	pthread_mutex_init(&data->m_write, NULL);
	pthread_mutex_init(data->m_philo_died, NULL);
	return (0);
}

t_philo *ft_init_philos(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	philo = ft_calloc(data->nbr_philos, sizeof(t_philo *));
	if (!philo)
		exit(1);
	while (i < data->nbr_philos)
	{
		philo[i].philo_index = i + 1;
		philo[i].data = data;
		philo[i].death_time = data->time_to_die;
		philo[i].meal_counter = 0;
		philo[i].time_last_meal = 0;
		philo[i].first_time = get_time();
		// philo[i].r_fork = &data->m_fork[i];
		// if (i - 1 < 0)
		// 	philo[i].l_fork = &data->m_fork[data->nbr_philos - 1];
		// else
		// 	philo[i].l_fork = &data->m_fork[i - 1];
		i++;
	}
	return (philo);
}

t_philo *ft_init(int ac, char **av, t_data *data)
{
	t_philo *philo = 0;

	if (ft_init_data(ac, av, data))
		return (NULL);
	if (ft_init_mutex(data))
		return (NULL);
	philo = ft_init_philos(data, philo);
	return (NULL);
}

