/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:41:42 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/14 00:00:29 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_node	*top_a;
	t_node	*top_b;

	top_a = NULL;
	top_b = NULL;
	top_a = parsing(argv, argc, top_a);
	if (top_a == NULL)
		return (0);
	if (!read_operations(&top_a, &top_b))
		return (-1);
	else if (check_is_sorted(&top_a) && top_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	return (0);
}
