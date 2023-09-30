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

void ft_clean(t_data *data, t_philo *philo)
{
	int i = 0;
	if (!philo)
		return ;
	while (i < data->nbr_philos)
        {
                pthread_mutex_destroy(&data->m_fork[i]);
                i++;
        }
        pthread_mutex_destroy(&data->m_write);
}

int ft_free(t_data *data, t_philo *philo)
{

	if(data->m_fork)
	        free(data->m_fork);
        if(philo)
		free (philo);
	if(data)
		free(data);
	exit (1);
	return 0;
}

int    ft_error(int n, t_data *data, t_philo *philo)
{
	if (n == 1)
		exit(0);
	if (data || philo)
		ft_free(data, philo);
	exit(1);
}