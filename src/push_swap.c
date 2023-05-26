/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:49:25 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/26 11:29:20 by zbeaumon         ###   ########.fr       */
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
	t_piles	piles;
	int		*temp;
	int		i;
	char	**new_av;

	i = -1;
	temp = temp_array(ac, av);
	ft_bzero(&piles, sizeof(t_piles));
	if (ac == 1)
		return (0);
	new_av = get_total_args(&ac, av);
	if (!new_av)
		return (ft_putendl_fd("Error", 2), free_all(&piles, new_av), 0);
	if (error_input(ac, av))
		return (ft_putendl_fd("non", 2), free_all(&piles, av), 0);
	piles.total = ac - 1;
	piles.a_count = ac - 1;
	if (init_all(ac, av, &piles))
		return (ft_putendl_fd("Error", 2), free_all(&piles, av), 0);
	if (is_list_in_order(piles.a))
		select_algo(&piles);
	printf("\n");
	printf("a\n");
	printdata(piles.a);
	printf("\n");
	printf("b\n");
	printdata(piles.b);
	printf("\n");
	return (0);
}
