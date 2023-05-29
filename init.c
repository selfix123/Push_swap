/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:06:18 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/29 10:07:04 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init(int ac, char **av)
{
	int		*tmp;
	int		i;
	t_data	*a;

	tmp = temp_array(ac, av);
	if (!tmp)
		return (NULL);
	a = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!a)
		return (ft_xfree(tmp), NULL);
	a->next = a;
	a->previous = a;
	a->content = index_nb(tmp, 0, ac);
	i = 1;
	while (i < ac)
	{
		if (ft_dlstadd_back(&a, tmp, i, ac))
			return (free_piles(a), ft_xfree(tmp), NULL);
		i++;
	}
	return (ft_xfree(tmp), a);
}

int	init_all(int ac, char **av, t_piles *piles)
{
	piles->a = init(ac, av);
	if (!piles->a)
		return (1);
	return (0);
}
