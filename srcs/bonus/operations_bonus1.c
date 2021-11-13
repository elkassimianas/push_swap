/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:04:03 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 02:44:57 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	swap(t_node **top)
{
	int		temp;
	t_node	*next;

	if (len_linked_list(*top) <= 1)
		return ;
	next = (*top)->next;
	temp = next->data;
	next->data = (*top)->data;
	(*top)->data = temp;
}

void	push_to_stack(t_node **top1, t_node **top2)
{
	int		data;

	if (*top2 == NULL)
		return ;
	data = pop(top2);
	push(data, top1);
}

void	rotate(t_node **top)
{
	t_node	*tail;

	tail = *top;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *top;
	*top = (*top)->next;
	tail->next->next = NULL;
	return ;
}

void	reverse_rotate(t_node **top)
{
	t_node		*temp;

	temp = *top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *top;
	*top = temp->next;
	temp->next = NULL;
	return ;
}