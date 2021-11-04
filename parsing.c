/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:31:54 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/03 18:07:20 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parsing(char **str, int len)
{
    int     i;
    int     b;
    int     num;

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
        num = ft_atoi(str[i]);
        printf("%d\n", num);
    }
}