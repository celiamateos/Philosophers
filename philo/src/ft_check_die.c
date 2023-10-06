/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:43:29 by cmateos           #+#    #+#             */
/*   Updated: 2023/10/05 16:43:30 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

int	check_i_die(t_philo *philo)
{
	if (get_time(philo->data) - philo->time_last_meal >= philo->death_time)
	{
		ft_print_status(philo, "died");
		return (1);
	}
	return (0);
}

int	check_any_die(t_philo *philo)
{
	int	any_dead;

	pthread_mutex_lock(philo->data->m_philo_died);
	any_dead = philo->data->philo_died;
	pthread_mutex_unlock(philo->data->m_philo_died);
	return (any_dead);
}

int	check_die(t_philo *philo)
{
	if (check_any_die(philo))
		return (1);
	if (get_time(philo->data) - philo->time_last_meal >= philo->death_time)
	{
		ft_print_status(philo, "died");
		return (1);
	}
	return (0);
}
