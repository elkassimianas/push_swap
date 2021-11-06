/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:31:15 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/05 15:46:07 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
#include <string.h>

typedef struct s_node
{
    /* data */
    int     data;
    struct s_node   *next;
    
}               t_node;

t_node  *parsing(char **str, int len, t_node *top_a);
void    push(int data, t_node **top);
int     pop(t_node **top);
void    reverse(t_node **top);
void    push_swap(int len, t_node *top_a, t_node *top_b);
void    display(t_node *top);
int     len_linked_list(t_node *top);
void    swap(t_node **top_a);
void    push_an_stack(t_node **top1, t_node **top2);

#endif