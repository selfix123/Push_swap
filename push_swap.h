/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:52:04 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/29 10:31:45 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_data
{
	int				content;
	struct s_data	*next;
	struct s_data	*previous;
}	t_data;

typedef struct s_piles
{
	int		a_count;
	int		b_count;
	int		total;
	int		av_checker;
	t_data	*a;
	t_data	*b;
}	t_piles;

int		ft_dlstadd_back(t_data **lst, int *temp, int i, int ac);
t_data	*ft_dlstnew(int content);
void	ss(t_piles piles, bool print);
void	sb(t_data **b, int count, bool print);
void	sa(t_data **a, int count, bool print);
void	rrr(t_piles *piles, bool print);
void	rrb(t_data **data, bool print);
void	rra(t_data **data, bool print);
void	ra(t_data **data, bool print);
void	rb(t_data **data, bool print);
void	rr(t_piles *pile, bool print);
void	pa(t_piles *piles, bool print);
void	pb(t_piles *piles, bool print);
void	sort_three_a(t_piles *piles);
int		is_list_in_order(t_data **data);
void	radix_sort(t_piles *piles);
void	all_small_sort(t_piles *piles);
char	**get_total_args(int *ac, char **av, t_piles *piles);
void	sort_two_a(t_piles *piles);
void	sort_two_b(t_piles *piles);
int		*temp_array(int ac, char **av);
int		error_input(int ac, char **av);
void	*free_all(t_piles *piles, char **av);
void	free_piles(t_data *data);
int		init_all(int ac, char **av, t_piles *piles);
int		index_nb(int *temp, int index, int len);

#endif
