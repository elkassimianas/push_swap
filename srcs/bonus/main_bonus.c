/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:41:42 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 03:17:31 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"
#include "../../includes/get_next_line_bonus.h"

int    check_operations(t_node **top_a, t_node **top_b, char *str)
{  
    if (strcmp(str, "sa") || strcmp(str, "sb") || strcmp(str, "ss"))
    {
        if (strcmp(str, "sa"))
            swap(top_a);
        else if (strcmp(str, "sb"))
            swap(top_b);
        else
        {
            swap(top_a);
            swap(top_b);
        }
        return (1);
    }
    else if (str == "pa" || str == "pb")
    {
        if (str == "pa")
            push_to_stack(top_a, top_b);
        else
            push_to_stack(top_b, top_a);
        return (1);
    }
    if (check_operations1(top_a, top_b, str) != 1 ||
    check_operations2(top_a, top_b, str) != 1)
        return (0);
    else
        return (1);
}

int    check_operations1(t_node **top_a, t_node **top_b, char *str)
{
    if (str == "ra" || str == "rb" || str == "rr")
    {
        if (str == "ra")
            rotate(top_a);
        else if (str == "rb")
            rotate(top_b);
        else
        {
            rotate(top_a);
            rotate(top_b);
        }
        return (1);
    }
    return (0);
}

int    check_operations2(t_node **top_a, t_node **top_b, char *str)
{
    if (str == "rra" || str == "rrb" || str == "rrr")
    {
        if (str == "rra")
            reverse_rotate(top_a);
        else if (str == "rrb")
            reverse_rotate(top_b);
        else
        {
            reverse_rotate(top_a);
            reverse_rotate(top_b);
        }
        return (1);
    }
    else
        return (0);
}

int    read_operations(t_node **top_a, t_node **top_b)
{
    char    *line;
    int     ret;

    while (ret = get_next_line(0, &line) == 1)
    {
        if (!check_operations(top_a, top_b, line))
        {
            ft_putstr_fd("Error\n", 2);
            free(line);
            return (0);
        }
        free(line);
    }
    if (ret == 0 && line != NULL)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_node	*top_a;
    t_node	*top_b;
    int     ret;

    top_a = NULL;
    top_b = NULL;
    top_a = parsing(argv, argc, top_a);
    if (top_a == NULL)
        return (0);
    if (!read_operations(&top_a, &top_b))
        return (-1);
    else if (check_is_sorted(&top_a) && top_b == NULL)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 2);
    return (0);
}