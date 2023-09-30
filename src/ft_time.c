/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:43:14 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/30 15:43:17 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

long	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == 0)
	{
        // printf("\nSegundos: %ld", current_time.tv_sec);
        // printf("\nMicrosegundos: %ld", current_time.tv_usec);
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	}
	return (0);
}

void    ft_print_status(t_philo *philo, char *msg)
{
    int index = philo->philo_index;
    long time = get_time() - philo->first_time;
    printf("\n%ld %d %s", time, index, msg);

}