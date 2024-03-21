/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:34:41 by adebert           #+#    #+#             */
/*   Updated: 2024/03/21 18:12:20 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool     whats_cost(t_list **lst, t_list *node)
{
    if ((find_node(lst, node) +1) == ft_lstsize(*lst))
    {
        node->cost = 1;
        return (1);
    }
    if (lower_median(lst, node))
        node->cost = find_node(lst, node);
    else if (!lower_median(lst, node))
        node->cost = ft_lstsize(*lst) - find_node(lst, node);
    return (0);
}

void    give_cost(t_list **a, t_list **b, t_list *current)
{
        if (whats_cost(a, current) && whats_cost(b, current->target))
            current->cost = 1;
        else if (find_node(a, current) == 1 && find_node(b, current->target) == 1)
            current->cost = 1;
        else
        {
            whats_cost(a, current);
            whats_cost(b, current->target);
            current->cost += current->target->cost;
        }
}
void    higher_cost(t_list *current)
{
    while (current->next)
    {
        if (current->cost < current->next->cost)
            current->cost = current->next->cost;
        current = current->next;
    }
}
