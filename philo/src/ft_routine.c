/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:39:36 by cmateos           #+#    #+#             */
/*   Updated: 2023/10/05 17:39:37 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philosophers.h"

static void	check_fork(t_philo *philo, int pos)
{
	pthread_mutex_lock(philo->data->m_fork[pos]);
	if (philo->data->shared_fork[pos] == 0)
	{
		philo->data->shared_fork[pos] = 1;
		philo->forks += 1;
		ft_print_status(philo, FORK);
	}
	pthread_mutex_unlock(philo->data->m_fork[pos]);
}

void	putdown_fork(t_philo *philo, int l_fork, int r_fork)
{
	pthread_mutex_lock(philo->data->m_fork[l_fork]);
	philo->data->shared_fork[l_fork] = 0;
	pthread_mutex_unlock(philo->data->m_fork[l_fork]);
	pthread_mutex_lock(philo->data->m_fork[r_fork]);
	philo->data->shared_fork[r_fork] = 0;
	pthread_mutex_unlock(philo->data->m_fork[r_fork]);
	philo->forks = 0;
}

int	is_eating(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->philo_index - 1;
	right_fork = philo->philo_index % philo->data->nbr_philos;
	if (philo->philo_index % 2 == 0)
	{
		left_fork = philo->philo_index % philo->data->nbr_philos;
		right_fork = philo->philo_index - 1;
	}
	while (philo->forks < 2 && !check_i_die(philo))
	{
		check_fork(philo, left_fork);
		check_fork(philo, right_fork);
	}
	if (!check_die(philo))
	{
		ft_print_status(philo, EAT);
		philo->time_last_meal = get_time(philo->data);
		philo->lock = ft_waiting_to_live(philo, philo->data->time_to_eat);
		putdown_fork(philo, left_fork, right_fork);
		if (philo->lock == 0)
			return (0);
	}
	return (1);
}

int	is_sleeping(t_philo *philo)
{
	ft_print_status(philo, SLEEP);
	if (ft_waiting_to_live(philo, philo->data->time_to_sleep) == 1)
		return (1);
	ft_print_status(philo, THINK);
	return (0);
}

void	*ft_routine(void *philos)
{
	t_philo	*philo;
	long	limit;

	philo = (t_philo *)philos;
	limit = philo->data->meal_count;
	philo->first_time = get_time(philo->data);
	if (philo->data->nbr_philos == 1)
	{
		ft_print_status(philo, FORK);
		printf("%ld 1 died", philo->data->time_to_die);
		return (NULL);
	}
	if (philo->philo_index % 2 == 0)
		usleep(2 * 1000);
	while (limit != 0)
	{
		if (is_eating(philo))
			break ;
		if (is_sleeping(philo))
			break ;
		limit--;
	}
	return (NULL);
}
