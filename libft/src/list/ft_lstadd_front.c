/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:59:43 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:19:25 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* if no list the new node = list else change the new
node to the first link of the list */
void	ft_lstadd_front(t_list **lst, t_list *new_element)
{
	if (!new_element)
		return ;
	if (!lst)
	{
		*lst = new_element;
		return ;
	}
	new_element->next = *lst;
	*lst = new_element;
}
