/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:28:57 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 18:54:34 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	check_duplicate(char **str, int len)
{
	int		i;
	int		b;

	i = 0;
	while (++i < len)
	{
		b = i;
		while (++b < len)
		{
			if (strcmp(str[i], str[b]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
}

t_node	*parsing(char **str, int len, t_node *top_a)
{
	int		i;
	int		b;

	check_duplicate(str, len);
	i = 0;
	while (str[++i])
	{
		b = 0;
		if (str[i][b] == '-' && str[i][b + 1])
			b++;
		while (str[i][b])
		{
			if (ft_isdigit(str[i][b++]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		ft_atoi(str[i]);
	}
	i = 0;
	while (str[++i])
		push(ft_atoi(str[i]), &top_a);
	reverse(&top_a);
	return (top_a);
}