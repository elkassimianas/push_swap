/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:49:52 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/03 11:42:51 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    int     i;
    int     b;

    printf("argc: %d\n", argc);
    i = 0;
    while(argv[++i])
    {
        b = 0;
        while (argv[i][b])
        {
            if (ft_isdigit(argv[i][b++]) == 0)
            {
                printf("error\n");
                return (-1);
            }
        }
        printf("%s\n", argv[i]);
    }
    return 0;
}