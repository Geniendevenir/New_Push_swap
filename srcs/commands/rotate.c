/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:02:21 by adebert           #+#    #+#             */
/*   Updated: 2024/03/21 18:12:23 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_list **a)
{
    t_list    *save;
    t_list	*last;

    last = ft_lstnew((*a)->content);
    save = *a;
    ft_lstadd_back(a, last);
    *a = (*a)->next;
    free(save);
    write(1, "ra\n", 3);
}

void    rb(t_list **b)
{
    t_list    *save;
    t_list	*last;

    last = ft_lstnew((*b)->content);
    save = *b;
    ft_lstadd_back(b, last);
    *b = (*b)->next;
    free(save);
    write(1, "rb\n", 3);
}

void    rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}
