/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:31:15 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 18:23:10 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdio.h>
#include <string.h>

typedef struct s_node
{
    /* data */
    int     data;
    int     index;
    struct s_node   *next;
    
}               t_node;

typedef struct s_merge
{
    int     len_l;
    int     len_r;
}               t_merge;


t_node  *parsing(char **str, int len, t_node *top_a);
void    push(int data, t_node **top);
int     pop(t_node **top);
void    reverse(t_node **top);
void    push_swap(int len, t_node **top_a, t_node **top_b);
int     len_linked_list(t_node *top);
void    swap(t_node **top_a, char *str);
void    push_to_stack(t_node **top1, t_node **top2, char *str);
void    rotate(t_node **top, char *str);
void    reverse_rotate(t_node **top, char *str);
void    sort_small_stack(t_node **top_a, t_node **top_b, int len);
void    three_numbers(t_node **top_a, t_node *current);
void	free_list(t_node *top);
void    four_numbers(t_node **top_a, t_node **top_b, t_node *current);
int		find_min_num(t_node **top_a, t_node *current);
void    five_numbers(t_node **top_a, t_node **top_b, t_node *current);
int		check_is_sorted(t_node **top_a);
void    merge_sort(int **arr, int len , int mid_len);
void    sort_big_stack(t_node **top_a, t_node **top_b, int len);
void	position_1(t_node **top_a, t_node **top_b);
void	position_2(t_node **top_a, t_node **top_b);
void	position_3(t_node **top_a, t_node **top_b);
void	position_4(t_node **top_a, t_node **top_b);

#endif