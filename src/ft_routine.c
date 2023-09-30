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


void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	philo->time_last_meal = get_time();
	ft_print_status(philo, "has taken a fork");
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->m_write);
	ft_print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->data->m_write);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	is_sleeping(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	ft_print_status(philo, "is thinking");
}

void	*ft_routine(void *philos)
{
	t_philo *philo;
	int *ret = 0;
	int limit;

	philo = (t_philo *)philos;
	// printf("\nEmpieza la rutina!");
	limit = 3;
	while (limit > 0)
	{
		is_eating(philo);
		is_sleeping(philo);
		limit--;
	}

	return((void *)ret);
}