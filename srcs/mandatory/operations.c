/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:05:39 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 20:36:59 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_node **top, char *str)
{
	int		temp;
	t_node	*next;

	if (len_linked_list(*top) <= 1)
		return ;
	next = (*top)->next;
	temp = next->data;
	next->data = (*top)->data;
	(*top)->data = temp;
	ft_putstr_fd(str, 1);
}

void	push_to_stack(t_node **top1, t_node **top2, char *str)
{
	int		data;
	int		index;

	if (*top2 == NULL)
		return ;
	index = (*top2)->index;
	data = pop(top2);
	push(data, top1);
	(*top1)->index = index;
	ft_putstr_fd(str, 1);
}

void	rotate(t_node **top, char *str)
{
	t_node	*tail;

	tail = *top;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *top;
	*top = (*top)->next;
	tail->next->next = NULL;
	ft_putstr_fd(str, 1);
	return ;
}

void	reverse_rotate(t_node **top, char *str)
{
	t_node		*temp;

	temp = *top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *top;
	*top = temp->next;
	temp->next = NULL;
	ft_putstr_fd(str, 1);
	return ;
}
