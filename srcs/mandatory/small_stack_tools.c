/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:13:04 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 20:14:24 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	position_1(t_node **top_a, t_node **top_b)
{
	push_to_stack(top_b, top_a, "pb\n");
}

void	position_2(t_node **top_a, t_node **top_b)
{
	swap(top_a, "sa\n");
	push_to_stack(top_b, top_a, "pb\n");
}

void	position_3(t_node **top_a, t_node **top_b)
{
	reverse_rotate(top_a, "rra\n");
	reverse_rotate(top_a, "rra\n");
	push_to_stack(top_b, top_a, "pb\n");
}

void	position_4(t_node **top_a, t_node **top_b)
{
	reverse_rotate(top_a, "rra\n");
	push_to_stack(top_b, top_a, "pb\n");
}

int	find_min_num(t_node **top_a, t_node *current)
{
	t_node	*min;
	int		i;
	int		pos;

	min = *top_a;
	i = 2;
	pos = 1;
	while (current != NULL)
	{
		if (min->data > current->data)
		{
			min = current;
			pos = i;
		}
		i = i + 1;
		current = current->next;
	}
	return (pos);
}