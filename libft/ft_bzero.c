/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:25:02 by marvin            #+#    #+#             */
/*   Updated: 2022/10/21 14:25:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t		i;
	char		*a;

	a = str;
	i = 0;
	if (!str)
		return ;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
