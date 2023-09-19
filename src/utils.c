/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:22:54 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/01 17:22:56 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

int ft_free(t_data *data, t_philo *philo)
{
	if(philo)
		free (philo);
	if(data->philo_id)
		free(data->philo_id);
	if(data->fork)
		free(data->fork);
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

long	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == 0)
	{
        printf("\nSegundos: %ld", current_time.tv_sec);
        printf("\nMicrosegundos: %d", current_time.tv_usec);
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	}
	return (0);
}