/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:34:34 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/14 00:03:43 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	push(int data, t_node **top)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	temp->data = data;
	temp->next = *top;
	*top = temp;
}

int	pop(t_node **top)
{
	t_node	*temp;
	int		data;

	if (*top == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *top;
		*top = (*top)->next;
		data = temp->data;
		temp->next = NULL;
		free(temp);
	}
	return (data);
}

void	reverse(t_node **top)
{
	t_node	*prev;
	t_node	*current;
	t_node	*next;

	prev = NULL;
	next = NULL;
	current = *top;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*top = prev;
}

int	check_is_sorted(t_node **top_a)
{
	t_node	*cmp;
	t_node	*current;

	current = *top_a;
	cmp = current->next;
	while (cmp != NULL)
	{
		if (current->data > cmp->data)
			return (0);
		current = current->next;
		cmp = current->next;
	}
	return (1);
}

int	len_linked_list(t_node *top)
{
	int		i;
	t_node	*current;

	current = top;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
