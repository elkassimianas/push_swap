/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:53:47 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 21:02:12 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	free_list(t_node *top)
{
	t_node	*tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}
