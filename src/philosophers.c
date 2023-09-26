/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student->42madrid->com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:06:56 by cmateos-          #+#    #+#             */
/*   Updated: 2023/09/01 17:06:58 by cmateos-         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../philosophers.h"

void    leaks()
{
	system ("leaks -q philosophers");
}


/*void	ft_eating(t_data *data, t_philo *philo)
{

}

void	ft_loop(t_data *data, t_philo *philo)
{
	ft_eating(data, philo);
	ft_sleeping(data, philo);
	ft_thinking(data, philo);
}*/

int main (int ac, char **av)
{
	// atexit(leaks);
	t_data *data;
	t_philo *philo;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (-1);
	if (ft_check_args(ac, av))
	{
		printf("Error\n Bad arguments!");
		ft_free(data, NULL);
	}
	philo = ft_calloc(data->nbr_philos, sizeof(t_philo));
	if (!philo)
		return (-1);
	 ft_init(ac, av, data, philo);
	// //ft_start_threads(philo);
	// //ft_start_simulation(data, philo);
	printf("\nNúmero de philos:%d", data->nbr_philos);
	printf("\nTime to die:%d", data->time_to_die);
	printf("\nTime to eat:%d", data->time_to_eat);
	printf("\nTime to sleep:%d", data->time_to_sleep);

	ft_free(data, philo);
	return (0);
}