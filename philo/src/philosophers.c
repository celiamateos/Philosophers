/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:55:01 by cmateos-          #+#    #+#             */
/*   Updated: 2023/10/01 15:55:03 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

int	ft_start_pthreads(t_data *data, t_philo *philo)
{
	int	size;
	int	i;

	i = 0;
	size = data->nbr_philos;
	while (i < size)
	{
		if (pthread_create(&philo[i].id, NULL, ft_routine, (void *)&philo[i]))
		{
			printf("\nError, failed create thread");
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_join_pthreads(t_philo *philo, t_data *data)
{
	int	size;
	int	i;

	i = 0;
	size = data->nbr_philos;
	while (i < size)
	{
		if (pthread_join((philo[i].id), NULL) != 0)
		{
			printf("\nError, failed join thread");
			break ;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	philo = 0;
	if (ft_check_args(&data, ac, av))
	{
		printf("Error\n Bad arguments!");
		return (1);
	}
	philo = ft_init(ac, av, &data);
	if (philo)
	{
		if (!ft_start_pthreads(&data, philo))
			ft_join_pthreads(philo, &data);
	}
	ft_clean(&data, philo);
	return (0);
}
