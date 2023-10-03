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
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	if (!s2 || !n)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (((i + 1) < n)))
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_print_status(t_philo *philo, char *msg)
{
	int		index;
	int		lock;
	long	time;

	lock = 0;
	index = philo->philo_index;
	time = get_time() - philo->first_time;
	pthread_mutex_lock(philo->data->m_philo_died);
	if (philo->data->philo_died == 0)
		printf("\n%ld %d %s", time, index, msg);
	if (ft_strncmp(msg, "died", 3) == 0)
	{
		philo->data->philo_died = 1;
		lock = 1;
	}
	pthread_mutex_unlock(philo->data->m_philo_died);
	if (lock == 1)
		return (1);
	return (0);
}
