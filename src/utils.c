/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/29 10:28:50 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_nb(int *temp, int index, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < len)
	{
		if (temp[i] < temp[index])
			count++;
		i++;
	}
	return (count + 1);
}

int	is_list_in_order(t_data **data)
{
	t_data	*ptr;

	ptr = *data;
	while (ptr->next != *data)
	{
		if (ptr->next->content < ptr->content)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	*temp_array(int ac, char **av)
{
	int	i;
	int	*temp;

	i = -1;
	temp = ft_calloc(ac + 1, sizeof(int));
	if (!temp)
		return (NULL);
	while (++i < ac)
		temp[i] = ft_atoi(av[i]);
	return (temp);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		trigger;

	i = 0;
	trigger = 1;
	count = 0;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || s[i] == 0) && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		else if (s[i] != c && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count + 1);
}

char	**get_total_args(int *ac, char **av, t_piles *piles)
{
	char	**new_argv;

	if (*ac == 2)
	{
		*ac = ft_word_count(av[1], ' ') - 1;
		new_argv = ft_split(av[1], ' ');
		piles->av_checker = 1;
	}
	else
	{
		*ac = *ac - 1;
		new_argv = av + 1;
	}
	return (new_argv);
}


