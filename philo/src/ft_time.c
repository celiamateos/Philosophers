/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:40:00 by cmateos           #+#    #+#             */
/*   Updated: 2023/10/05 17:40:01 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philosophers.h"

int	ft_waiting_to_live(t_philo *philo, long time)
{
	long	now;
	int		lock;

	lock = 0;
	now = get_time(philo->data);
	time = time * 1000;
	while (1)
	{
		
		if (get_time(philo->data) - philo->time_last_meal >= philo->death_time)
		{
			lock = ft_print_status(philo, "died");
			break ;
		}
		if (get_time(philo->data) - now >= time / 1000)
			break ;
		usleep(5);
		//ft_mssleep(5, philo->data);
	}
	if (lock == 1)
		return (1);
	return (0);
}

long	get_time(t_data *data)
{
	struct timeval	now_time;
	long			sec;
	int				usec;

	gettimeofday(&now_time, NULL);
	sec = now_time.tv_sec;
	usec = now_time.tv_usec;
	return ((sec - data->tv_sec) * 1000 + ((usec - data->tv_usec) / 1000));
}

void ft_mssleep(long ms, t_data *data)
{
	long	start;
	long	current;

	start = get_time(data);
	while (1)
	{
		current = get_time(data);
		if (current -  start >= ms)
			break;
		usleep(20);
	}
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
	pthread_mutex_lock(philo->data->m_philo_died);
	time = get_time(philo->data) - philo->first_time;
	if (philo->data->philo_died == 0)
		printf("%ld %d %s\n", time, index, msg);
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

void	ft_print_think(t_philo *philo, char *msg)
{
	int		index;
	long	time;

	index = philo->philo_index;
	time = get_time(philo->data) - philo->first_time;
	if (philo->data->philo_died == 0)
		printf("%ld %d %s\n", time, index, msg);
}