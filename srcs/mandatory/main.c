/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:49:52 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/12 17:38:17 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int    check_is_sorted(t_node **top_a)
{
    t_node  *cmp;
	t_node	*current;

    current = *top_a;
	cmp = current->next;
    while (cmp != NULL)
    {
        if (current->data > cmp->data)
            return (0);
        current = current->next;
        cmp = current->next;
    }
    return (1);
}

void    push_swap(int len, t_node **top_a, t_node **top_b)
{
    if (check_is_sorted(top_a))
		return ;
    else if (len <= 5)
    	sort_small_stack(top_a, top_b, len);
	else
        sort_big_stack(top_a, top_b, len);
}

int     main(int argc, char **argv)
{
    t_node  *top_a;
    t_node  *top_b;

    top_a = NULL;
    top_b = NULL;
    top_a = parsing(argv, argc, top_a);
    push_swap(argc - 1, &top_a, &top_b);
	if (top_a != NULL)
		free_linked_list(&top_a);
	if (top_b != NULL)
		free_linked_list(&top_b);
    return 0;
}