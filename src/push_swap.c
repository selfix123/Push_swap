/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:25 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/26 16:48:02 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_algo(t_piles *piles)
{
	if (piles->total == 2)
		sort_two_a(piles);
	if (piles->total > 2 && piles->total < 7)
		all_small_sort(piles);
	else
		radix_sort(piles);
}

void	printdata(t_data *data)
{
	t_data	*head;

	head = data;
	if (!data)
	{
		printf("(null)\n");
		return ;
	}
	printf("%d\n", data->content);
	data = data->next;
	while (data != head)
	{
		printf("%d\n", data->content);
		data = data->next;
	}
}

int	main(int ac, char **av)
{
	t_piles	*piles;
	char	**new_av;

	if (ac == 1)
		return (0);
	piles = (t_piles *)ft_calloc(1, sizeof(t_piles));
	if (!piles)
		return (ft_putendl_fd("Error", 2), 0);
	new_av = get_total_args(&ac, av, piles);
	if (!new_av)
		return (ft_putendl_fd("Error", 2), free_all(piles, new_av), 0);
	if (error_input(ac, new_av))
		return (ft_putendl_fd("Error", 2), free_all(piles, new_av), 0);
	piles->total = ac;
	piles->a_count = ac;
	if (init_all(ac, new_av, piles))
		return (ft_putendl_fd("Error", 2), free_all(piles, new_av), 0);
	if (is_list_in_order(&piles->a))
		select_algo(piles);
	return (free_all(piles, new_av), 0);
}
