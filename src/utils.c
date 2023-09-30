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

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	memset(p, 0, (count * size));
	return (p);
}




long     ft_atol(const char *str)
{
        unsigned int    i;
        long int    result;
        unsigned int    sign;

        i = 0;
        result = 0;
        sign = 1;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
                || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
                        i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        sign = sign * (-1);
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
                result = result * 10 + str[i++] - '0';
        return (sign * result);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        unsigned char           *destination;
        unsigned const char     *source;
        size_t                          i;

        destination = dst;
        source = src;
        i = 0;
        if (dst || src)
        {
                while (i < n)
                {
                        destination[i] = source[i];
                        i++;
                }
        }
        return (dst);
}

unsigned int ft_strlen(const char *s)
{
	int i;
	
	i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char                    *subs;

        if (s == NULL)
                return (NULL);
        if (start > ft_strlen(s))
                len = 0;
        if (len > ft_strlen(s) - start)
                len = ft_strlen(s) - start;
        subs = malloc((len + 1) * sizeof(char));
        if (!subs)
                return (NULL);
        ft_memcpy(subs, &s[start], len);
        subs[len] = '\0';
        return (subs);
}
