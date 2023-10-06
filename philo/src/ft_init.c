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

int	ft_full_data(char **args, int i, t_data *data)
{
	data->nbr_philos = atoi(args[i]);
	data->time_to_die = atoi(args[i + 1]);
	data->time_to_eat = atoi(args[i + 2]);
	data->time_to_sleep = atoi(args[i + 3]);
	data->philo_died = 0;
	if (args[i + 4] != NULL)
	{
		data->meal_count = atoi(args[i + 4]);
		if (data->meal_count < 1)
			return (1);
	}
	else
		data->meal_count = -1;
	return (0);
}

int	ft_init_data(int ac, char **av, t_data *data)
{
	int		i;
	int		lock;
	char	**args;

	lock = 0;
	i = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (1);
	}
	else
	{
		i = 1;
		args = av;
	}
	if (ft_full_data(args, i, data))
		lock = 1;
	if (ac == 2)
		ft_free_array(args);
	if (data->nbr_philos < 1 || data->nbr_philos > 200
		||data->time_to_die < 0 || lock == 1)
		return (1);
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int				i;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	data->tv_sec = start_time.tv_sec;
	data->tv_usec = start_time.tv_usec;
	data->m_fork = ft_calloc(data->nbr_philos, sizeof(pthread_mutex_t *));
	data->m_write = ft_calloc(1, sizeof(pthread_mutex_t));
	data->m_philo_died = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->m_fork || !data->m_philo_died || !data->m_write)
		return (free(data), 1);
	i = 0;
	while (i < data->nbr_philos)
	{
		data->m_fork[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!data->m_fork[i])
			ft_free(data, NULL);
		pthread_mutex_init(data->m_fork[i], NULL);
		i++;
	}
	pthread_mutex_init(data->m_write, NULL);
	pthread_mutex_init(data->m_philo_died, NULL);
	return (0);
}

t_philo	*ft_init_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo = ft_calloc(data->nbr_philos, sizeof(t_philo));
	data->shared_fork = ft_calloc(data->nbr_philos, sizeof(char));
	if (!philo)
		ft_error(data, philo, "\nError, failed malloc philo");
	while (i < data->nbr_philos)
	{
		philo[i].philo_index = i + 1;
		philo[i].data = data;
		philo[i].death_time = data->time_to_die;
		philo[i].time_last_meal = 0;
		philo[i].first_time = get_time(philo->data);
		philo[i].forks = 0;
		i++;
	}
	return (philo);
}

t_philo	*ft_init(int ac, char **av, t_data *data)
{
	t_philo	*philo;

	philo = 0;
	if (ft_init_data(ac, av, data))
		return (NULL);
	if (ft_init_mutex(data))
		return (NULL);
	philo = ft_init_philos(data, philo);
	return (philo);
}
