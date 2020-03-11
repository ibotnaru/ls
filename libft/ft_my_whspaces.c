/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_whspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:55:10 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/28 18:52:16 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_my_whspaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' ||
			c == '\n' || c == '\r' || c == '\f')
	{
		return (1);
	}
	else
		return (0);
}
