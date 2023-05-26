/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/26 16:10:01 by zbeaumon         ###   ########.fr       */
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

// t_data	*ft_dlstnew(int content)
// {
// 	t_data	*new;

// 	new = ft_calloc(sizeof(t_data), 1);
// 	if (!new)
// 		return (NULL);
// 	new->index = 0;
// 	new->content = content;
// 	new->next = new;
// 	new->previous = new;
// 	return (new);
// }

// int	ft_dlstadd_back(t_data **lst, int *temp, int i, int ac)
// {
// 	t_data	*ptr;
// 	t_data	*head;

// 	if (!*lst)
// 		*lst = ft_dlstnew(index_nb(temp, i, ac));
// 	else
// 	{
// 		head = (*lst);
// 		ptr = ft_calloc(1, sizeof(t_data));
// 		if (!ptr)
// 			return (1);
// 		ptr->content = index_nb(temp, i, ac);
// 		ptr->previous = head->previous;
// 		ptr->next = head;
// 		ptr->next->previous = ptr;
// 		ptr->previous->next = ptr;
// 		(*lst) = head;
// 	}
// 	return (0);
// }

int	pile_add_end(int data, t_data **pile)
{
	t_data	*new;

	new = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!new)
		return (1);
	new->content = data;
	new->previous = (*pile)->previous;
	(*pile)->previous->next = new;
	new->next = *pile;
	(*pile)->previous = new;
	return (0);
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
