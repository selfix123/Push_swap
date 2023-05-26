/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:50:55 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/26 15:46:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles(t_data *data)
{
	t_data	*ptr;
	t_data	*tmp;

	ptr = data;
	while (ptr->next != data)
	{
		tmp = ptr->next;
		ft_xfree(ptr);
		ptr = tmp;
	}
	ft_xfree(ptr);
}

void	*free_all(t_piles *piles, char **av)
{
	int	i;

	if (piles->a != NULL)
		free_piles(piles->a);
	if (piles->b != NULL)
		free_piles(piles->b);
	i = 0;
	if (piles->av_checker)
	{
		while (av[i])
			ft_xfree(av[i++]);
		ft_xfree(av);
	}
	ft_xfree(piles);
	return (NULL);
}
