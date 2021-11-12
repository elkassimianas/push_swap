/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:22:59 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 20:13:55 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_small_stack(t_node **top_a, t_node **top_b, int len)
{
	t_node	*current;

	current = *top_a;
	if (len == 2)
		swap(top_a, "sa\n");
	else if (len == 3)
		three_numbers(top_a, current);
	else if (len == 4)
		four_numbers(top_a, top_b, (*top_a)->next);
	else
		five_numbers(top_a, top_b, (*top_a)->next);
}

void	help_three(t_node **top_a, t_node *current)
{
	reverse_rotate(top_a, "rra\n");
	current = (*top_a)->next;
	if ((*top_a)->data > current->data)
		swap(top_a, "sa\n");
}

void	three_numbers(t_node **top_a, t_node *current)
{
	t_node	*temp;

	current = current->next;
	if ((*top_a)->data > current->data)
	{
		current = current->next;
		if ((*top_a)->data > current->data)
		{
			rotate(top_a, "ra\n");
			current = (*top_a)->next;
			if ((*top_a)->data > current->data)
				swap(top_a, "sa\n");
		}
		else
			swap(top_a, "sa\n");
	}
	else
	{
		temp = current->next;
		if (current->data > temp->data)
			help_three(top_a, current);
		else if ((*top_a)->data > current->data)
			swap(top_a, "sa\n");
	}
}

void	four_numbers(t_node **top_a, t_node **top_b, t_node *current)
{
	int		pos;

	pos = find_min_num(top_a, current);
	if (pos == 1)
		position_1(top_a, top_b);
	if (pos == 2)
		position_2(top_a, top_b);
	if (pos == 3)
		position_3(top_a, top_b);
	if (pos == 4)
		position_4(top_a, top_b);
	three_numbers(top_a, *top_a);
	push_to_stack(top_a, top_b, "pa\n");
}

void	five_numbers(t_node **top_a, t_node **top_b, t_node *current)
{
	int		pos;

	pos = find_min_num(top_a, current);
	if (pos == 1)
		position_1(top_a, top_b);
	if (pos == 2)
		position_2(top_a, top_b);
	if (pos == 3)
	{
		rotate(top_a, "ra\n");
		rotate(top_a, "ra\n");
		push_to_stack(top_b, top_a, "pb\n");
	}
	if (pos == 4)
		position_3(top_a, top_b);
	if (pos == 5)
		position_4(top_a, top_b);
	if (!check_is_sorted(top_a))
		four_numbers(top_a, top_b, (*top_a)->next);
	push_to_stack(top_a, top_b, "pa\n");
	return ;
}
