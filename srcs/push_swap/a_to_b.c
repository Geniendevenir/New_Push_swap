/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:11:15 by adebert           #+#    #+#             */
/*   Updated: 2024/03/21 18:12:12 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *whos_biggest(t_list *b)
{
    t_list  *biggest;
    
    biggest = b;
    while (b)
    {
        if (biggest->content < b->content)
            biggest = b;
        b = b->next;
    }
    return (biggest);
}

int    is_neg(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    if (a > b)
        a -= b;
    else if (a < b)
        a = b - a;
    return (a);
}

void    a_target_b(t_list *a, t_list *b, t_list **blist)
{
    a->target = b;
    long    difference;
    int     min;
    
    min = 0;
    difference = 4200000;
    while (b)
    {
        if (a->content > b->content)
        {
            min = 1;
            if (is_neg(a->content, b->content) < difference)
            {
                difference = is_neg(a->content, b->content);
                a->target = b;
            }
        }
        b = b->next;
    }
    if (min == 0)
        a->target = whos_biggest(*blist);
}

void    top_of_a(t_list **a, t_list **b, t_list *node)
{
    t_list  *save;

    save = ft_lstnew(node->content);
    save->target = node->target;
    while (find_node(a, save) != 0)
    {
        if (lower_median(a, save))
        {
            if (whats_cost(a, save) && whats_cost(b, save->target))
                rr(a, b);
            else
                ra(a);
        }
        else if (!lower_median(a, save))
        {
            if (whats_cost(a, save) && whats_cost(b, save->target))
                rrr(a, b);
            else
                rra(a);
        }
    }
    free(save);
}

void    top_of_b(t_list **b, t_list *node)
{
    t_list  *save;

    save = ft_lstnew(node->content);
    while (find_node(b, save) != 0)
    {

        if (lower_median(b, save))
        {
            rb(b);
        }
        else if (!lower_median(b, save))
            rrb(b);
    }
    free(save);
}

