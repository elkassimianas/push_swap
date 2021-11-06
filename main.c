/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:49:52 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/05 15:52:42 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_is_sorted(t_node *top_a)
{
    t_node  *cmp;

    cmp = top_a->next;
    while (cmp != NULL)
    {
        if (top_a->data > cmp->data)
            return (1);
        top_a = top_a->next;
        cmp = top_a->next;
    }
    return (0);
}

void    sort_small_stack()
{
    
}

void    push_swap(int len, t_node *top_a, t_node *top_b)
{
    
    len = 0;
    if (check_is_sorted(top_a) == 0)
        exit(EXIT_SUCCESS);
    // else if (len <= 5)
    // {
    printf("hello\n");
    push_an_stack(&top_b, &top_a);
    //swap(&top_a);
    display(top_b);
    write(1, "\n" , 1);
    display(top_a);
        
  //  }
        //sort_small_stack();
    // else
    //     sort_big_stack();
}

int     main(int argc, char **argv)
{
    t_node  *top_a;
    t_node  *top_b;

    top_a = NULL;
    top_b = NULL;
    top_a = parsing(argv, argc, top_a);
    push_swap(argc - 1, top_a, top_b);
    return 0;
}