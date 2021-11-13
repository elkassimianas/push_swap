/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:29:49 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 03:12:21 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../Libft/libft.h"
# include <stdio.h>
#include <string.h>

typedef struct s_node
{
    /* data */
    int     data;
    struct s_node   *next;

}               t_node;

void    check_duplicate(char **str, int len);
t_node	*parsing(char **str, int len, t_node *top_a);
void    push(int data, t_node **top);
void	reverse(t_node **top);
int     check_operations(t_node **top_a, t_node **top_b, char *str);
int     check_operations1(t_node **top_a, t_node **top_b, char *str);
int     check_operations2(t_node **top_a, t_node **top_b, char *str);
void	swap(t_node **top);
void	push_to_stack(t_node **top1, t_node **top2);
void	rotate(t_node **top);
void	reverse_rotate(t_node **top);
int     check_is_sorted(t_node **top_a);
int     len_linked_list(t_node *top);
int		pop(t_node **top);

#endif