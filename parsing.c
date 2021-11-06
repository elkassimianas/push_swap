/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:31:54 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/05 15:47:17 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *parsing(char **str, int len, t_node *top_a)
{
    int     i;
    int     b;

    i = 0;
    while(++i < len)
    {
        b = i;
        while (++b < len)
        {
            if (strcmp(str[i], str[b]) == 0)
            {
                ft_putstr_fd("error\n", 2);
			    exit(EXIT_FAILURE);
            }
        }
    }
    i = 0;
    while(str[++i])
    {
        b = 0;
        if (str[i][b] == '-')
            b++;
        while (str[i][b])
        {
            if (ft_isdigit(str[i][b++]) == 0)
            {
                printf("error\n");
                exit(EXIT_FAILURE);
            }
        }
        push(ft_atoi(str[i]), &top_a); // if there some error do not forget to free the linked list "call function free inside ft_atoi"
    }
    reverse(&top_a);
    // display(top_a);
    return (top_a);
}