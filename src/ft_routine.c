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

int	ft_waiting_to_live(t_philo *philo, long time)
{
	long now;
	while (time > 0)
	{
		now = get_time();
		if (philo->time_last_meal == 0)
			philo->time_last_meal = philo->first_time;
		if (now - philo->time_last_meal >= philo->death_time)
		{
			ft_print_status(philo, "died");
			philo->data->philo_died = 1;
			return(1);
		}
		usleep(1000);
		time = time - (1000);
	}
	return (0);
}

int	is_eating(t_philo *philo)
{

	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	philo->time_last_meal = get_time();
	ft_print_status(philo, "has taken a fork");
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->m_write);
	ft_print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->data->m_write);
	ft_waiting_to_live(philo, philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}

int	is_sleeping(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	ft_waiting_to_live(philo, philo->data->time_to_sleep * 1000);
	// usleep(philo->data->time_to_sleep * 1000);
	ft_print_status(philo, "is thinking");
	return (0);
}

void	*ft_routine(void *philos)
{
	t_philo *philo;
	int limit;

	philo = (t_philo *)philos;
	// printf("\nEmpieza la rutina!");
	limit = philo->data->meal_count;
	while (limit > 0 && philo->data->philo_died == 0)
	{
		if (philo->data->philo_died == 1)
			break;
		is_eating(philo);
		if (philo->data->philo_died == 1)
			break;
		is_sleeping(philo);
		if (philo->data->philo_died == 1)
		 	break ;
		if (limit != -1)
			limit--;
	}
	return(NULL);
}