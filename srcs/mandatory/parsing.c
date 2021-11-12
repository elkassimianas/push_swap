/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:31:54 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 17:38:51 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    check_duplicat(char **str, int len)
{
    int     i;
    int     b;
 
    i = 0;
    while(++i < len)
    {
        b = i;
        while (++b < len)
        {
            if (strncmp(str[i], str[b], 4) == 0)
            {
                ft_putstr_fd("Error\n", 2);
			    exit(EXIT_FAILURE);
            }
        }
    }
}

int    check_grammar(char **str, t_node **top_a)
{
    int     i;
    int     b;
    
    i = 0;
    while(str[++i])
    {
        b = 0;
        if (str[i][b] == '-' && str[i][b + 1])
            b++;
        while (str[i][b])
            if (ft_isdigit(str[i][b++]) == 0)
            {
                ft_putstr_fd("Error\n", 2);
                return (0);
            }
        b = ft_atoi(str[i]);
        if (b == -1)
            return (0);
        push(b, top_a);
    }
    return (1);
}

t_node  *parsing(char **str, int len, t_node *top_a)
{
    check_duplicat(str, len);
    if (!check_grammar(str, &top_a))
    {
        free_linked_list(&top_a);
        exit (EXIT_FAILURE);
    }
    reverse(&top_a);
    return (top_a);
}