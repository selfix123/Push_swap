/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:50:06 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/29 10:28:44 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_dlstnew(int content)
{
	t_data	*new;

	new = ft_calloc(sizeof(t_data), 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = new;
	new->previous = new;
	return (new);
}

int	ft_dlstadd_back(t_data **lst, int *temp, int i, int ac)
{
	t_data	*ptr;
	t_data	*head;

	if (!*lst)
		*lst = ft_dlstnew(index_nb(temp, i, ac));
	else
	{
		head = (*lst);
		ptr = ft_calloc(1, sizeof(t_data));
		if (!ptr)
			return (1);
		ptr->content = index_nb(temp, i, ac);
		ptr->previous = head->previous;
		ptr->next = head;
		ptr->next->previous = ptr;
		ptr->previous->next = ptr;
		(*lst) = head;
	}
	return (0);
}

