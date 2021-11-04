/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:58 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/03 17:58:41 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int		ft_passing(const char *str)
{
	int		i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	long		nb;
	int			sign;
	int			i;

	i = 0;
	nb = 0;
	sign = 1;
	i = ft_passing(str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (nb < 0)
		{
			ft_putstr_fd("error\n", 2);
			exit(EXIT_FAILURE);
		}
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_putstr_fd("error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (nb);
}
