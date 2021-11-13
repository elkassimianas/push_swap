/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <ael-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:33:20 by ael-kass          #+#    #+#             */
/*   Updated: 2021/11/13 21:33:52 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/get_next_line_bonus.h"

int	get_next_line_help(char **save, char ***line, int len)
{
	int		ret;

	ret = ft_linen(save, line, len);
	if (ret == 1)
		return (1);
	if ((*save)[len] == '\0')
	{
		**line = ft_substr(*save, 0, len);
		if (!**line)
			return (-1);
	}
	return (0);
}