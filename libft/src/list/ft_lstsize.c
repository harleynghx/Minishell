/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:25:46 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:19:34 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// counts the nodes on the list
int	ft_lstsize(t_list *lst)
{
	int	z;

	z = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		z++;
	}
	return (z);
}
