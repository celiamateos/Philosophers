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

int    ft_error(int n, t_data *data, t_philo *philo)
{
	if (n == 1)
		exit(0);
	if (data || philo)
		ft_free(data, philo);
	exit(1);
}

