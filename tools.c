/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:53:47 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/05 15:42:12 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display(t_node *top)
{
    t_node *temp;
 
    printf("stack\n");
    // Check for stack underflow
    if (top == NULL)
        exit(1);
    else
    {
        temp = top;
        while (temp != NULL)
        {
 
            // Print node data
            printf("%d\n", temp->data);
 
            // Assign temp link to temp
            temp = temp->next;
        }
    }
}

/* Function to reverse the linked list */
void reverse(t_node **top)
{
    t_node *prev = NULL;
    t_node *current = *top;
    t_node *next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *top = prev;
}

void    push(int data, t_node **top)
{
    t_node *temp;

    temp = (t_node *)malloc(sizeof(t_node));
    if (!temp)
    {
        ft_putstr_fd("error\n", 2);
        exit(EXIT_FAILURE);
    }
    // Initialize data into temp data field
    temp->data = data;
    // Put top pointer reference into temp link
    temp->next = *top;
    // Make temp as top of Stack
    *top = temp;
}

// Utility function to pop top
// element from the stack
int     pop(t_node **top)
{
    t_node  *temp;
    int     data;
 
    // Check for stack underflow
    if (*top == NULL)
    {
        ft_putstr_fd("error\n", 2);
        exit(EXIT_FAILURE);
    }
    else
    {
         
        // Top assign into temp
        temp = *top;
 
        // Assign second node to top
        *top = (*top)->next;
 
        // Destroy connection between
        // first and second
        data = temp->data;
        temp->next = NULL;
 
        // Release memory of top node
        free(temp);
    }
    return (data);
}

int len_linked_list(t_node *top)
{
    int i = 0;  // Initialize count 'i'
    t_node  *current = top;  // Initialize current
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return (i);
}