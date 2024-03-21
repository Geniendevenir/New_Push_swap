/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:10:06 by adebert           #+#    #+#             */
/*   Updated: 2024/03/21 18:12:22 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list **a)
{
    t_list      *move;
    t_list      *save;
    t_list      *current;

    move = ft_lstnew(ft_lstlast(*a)->content);
    ft_lstadd_front(a, move);
    save = ft_lstlast(*a);
    current = *a;
    while (current->next)
    {
        if (current->next->next == NULL)
        {
            current->next = NULL;
            free(save);
            break ;
        }
        current = current->next;
    }
    write(1, "rra\n", 4);
}

void    rrb(t_list **b)
{
    t_list      *move;
    t_list      *current;
    t_list      *save;

    move = ft_lstnew(ft_lstlast(*b)->content);
    ft_lstadd_front(b, move);
    save = ft_lstlast(*b);
    current = *b;
    while (current->next)
    {
        if (current->next->next == NULL)
        {
            current->next = NULL;
            free(save);
            break ;
        }
        current = current->next;
    }
    write(1, "rrb\n", 4);
}

void    rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}
