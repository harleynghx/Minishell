/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:08:31 by zstenger          #+#    #+#             */
/*   Updated: 2025/05/19 14:02:44 by harleyng         ###   ########.fr       */
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
