/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:14:36 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/30 16:14:38 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

void	ft_clean(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	if (!philo)
		return ;
	while (++i < data->nbr_philos)
		pthread_mutex_destroy(data->m_fork[i]);
	pthread_mutex_destroy(data->m_write);
	pthread_mutex_destroy(data->m_philo_died);
	ft_free(data, philo);
}

void	ft_free(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (data->m_fork)
	{
		while (i < data->nbr_philos)
		{
			if (data->m_fork[i])
				free (data->m_fork[i]);
			i++;
		}
		free(data->m_fork);
	}
	if (data->m_write)
		free (data->m_write);
	if (data->shared_fork)
		free (data->shared_fork);
	if (data->m_philo_died)
		free (data->m_philo_died);
	if (philo)
		free (philo);
}

void	ft_error(t_data *data, t_philo *philo, char *str)
{
	printf("\nError, %s", str);
	ft_clean(data, philo);
	ft_free(data, philo);
}
