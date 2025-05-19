/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:57 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/19 14:20:47 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*empty_content_allocate(char *content)
{
	content = malloc(sizeof(char) * 2);
	content[0] = ' ';
	content[1] = '\0';
	return (content);
}
