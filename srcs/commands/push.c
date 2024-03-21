/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:38:07 by adebert           #+#    #+#             */
/*   Updated: 2024/03/21 18:12:22 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_list **a, t_list **b)
{
    t_list *move;
    t_list *save;

    save = *b;
    move = ft_lstnew((*b)->content);
    ft_lstadd_front(a, move);
    *b = (*b)->next;
    free(save);
    write(1, "pa\n", 3);;
}

void    pb(t_list **a, t_list **b)
{
    t_list *move;
    t_list *save;

    save = *a;
    move = ft_lstnew((*a)->content);
    ft_lstadd_front(b, move);
    *a = (*a)->next;
    free(save);
    write(1, "pb\n", 3);;
}
