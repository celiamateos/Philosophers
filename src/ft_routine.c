/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:16:36 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/30 16:16:48 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philosophers.h"
//Revisar los calculos de usleep y time.
int	ft_waiting_to_live(t_philo *philo, long time)
{
	long	now;
	int		lock;

	lock = 0;

	// printf("\nTIME LAST MEAL: %ld", (get_time() - philo->time_last_meal));
	while (time > 0)
	{
		now = get_time();
		// if (philo->time_last_meal == 0)
		// 	philo->time_last_meal = philo->first_time;
		if (now - philo->time_last_meal >= philo->death_time)
		{
			// printf("\n MUERTOOOOO");
			lock = ft_print_status(philo, "died");
		}

		usleep(time * 1000);
		time = time - 1000;
	}
	if (lock == 1)
		return (1);
	return (0);
}

int	is_eating(t_philo *philo)
{
	int	lock;

	philo->time_last_meal = get_time();
	if (philo->philo_index % 2 == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}

	ft_print_status(philo, "has taken a fork");
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->m_write);
	ft_print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->data->m_write);

	lock = ft_waiting_to_live(philo, philo->data->time_to_eat);
	// usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (lock == 1)
		return (1);
	return (0);
}

int	is_sleeping(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	if (ft_waiting_to_live(philo, philo->data->time_to_sleep) == 1)
		return (1);
	// usleep(philo->data->time_to_sleep * 1000);
	ft_print_status(philo, "is thinking");
	return (0);
}

void	*ft_routine(void *philos)
{
	t_philo	*philo;
	long	limit;
	int		ret;

	ret = 0;
	philo = (t_philo *)philos;
	limit = philo->data->meal_count;
	philo->first_time = get_time();
	if (philo->data->nbr_philos == 1)
	{
		ft_print_status(philo, "has taken a fork");		
		usleep(philo->data->time_to_die * 1000);
		printf("\n%ld 1 died", (get_time() - philo->first_time));
		return (NULL);
	}
	while (limit != 0)
	{
		ret = is_eating(philo);
		if (ret == 1)
			break ;
		ret = is_sleeping(philo);
		if (ret == 1)
			break ;
		limit--;
	}
	return (NULL);
}
