/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:05:39 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/05 18:13:50 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_node **top)
{
    int     temp;
    t_node  *next;
    
    if (len_linked_list(*top) <= 1)
        return ;
    next = (*top)->next;
    temp = next->data;
    next->data = (*top)->data;
    (*top)->data = temp;
}

void    push_an_stack(t_node **top1, t_node **top2)
{
    int     data;

    data = pop(top2);
    push(data, top1);
}
void    rotate(t_node **top)
{
    int     data;
    t_node  *current;
    t_node  *temp;
    
    temp = (t_node *)malloc(sizeof(t_node));
    temp->data = pop(top);
    temp->next = NULL;
    current = *top;
    while (current->next != NULL)
        current = current->next;
    current->next = temp;
    return ;
}
