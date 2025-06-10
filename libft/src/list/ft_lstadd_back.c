/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:13:01 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:19:23 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
if there is no new node returns null, if no list then the new node becames the
list otherwise checks for the last node of the list and adds a new one
*/
void	ft_lstadd_back(t_list **lst, t_list *new_element)
{
	t_list	*the;

	if (!new_element)
		return ;
	if (!*lst)
	{
		*lst = new_element;
		return ;
	}
	the = ft_lstlast(*lst);
	the->next = new_element;
}
