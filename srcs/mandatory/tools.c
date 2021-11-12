/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:53:47 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 17:09:15 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void display(t_node *top)
{
    t_node *temp;
 
    printf("\n");
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
        ft_putstr_fd("Error\n", 2);
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
        ft_putstr_fd("Error\n", 2);
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

void free_list(t_node *top)
{
   t_node *tmp;

   while (top != NULL)
    {
       tmp = top;
       top = top->next;
       free(tmp);
    }
}

void    merge(int *arr, int *right, int *left, int lenR, int lenL)
{
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    // lenR = ft_strlen(right);
    // lenL = ft_strlen(left);
    
    while (i < lenL && j < lenR)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i = i + 1;
        }
        else
        {
            arr[k] = right[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < lenL)
    {
        arr[k] = left[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < lenR)
    {
        arr[k] = right[j];
        j = j + 1;
        k = k + 1;
    }
}

void    merge_sort(int **arr, int len , int mid_len)
{
    int    *right;
    int    *left;
    int     i;

    // len = ft_strlen(arr);
    if (len < 2)
        return ;
    mid_len = len / 2;
    left = malloc(mid_len * sizeof(int));
    right = malloc((len - mid_len) * sizeof(int));
    if (right == NULL || left == NULL)
        exit (EXIT_FAILURE);
    i  = -1;
    while (++i < mid_len)
        left[i] = (*arr)[i];
    i = mid_len - 1;
    while (++i < len)
        right[i - mid_len] = (*arr)[i];
    merge_sort(&left, mid_len, mid_len);
    merge_sort(&right, len - mid_len, mid_len);
    merge(*arr, right, left, len - mid_len, mid_len);
    free(right);
    free(left);
}