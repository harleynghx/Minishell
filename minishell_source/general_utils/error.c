/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:06:14 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 19:11:26 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_arg(int argc)
{
	if (argc != 1)
	{
		printf(RED "ERROR, program takes no argument\n");
		exit(EXIT_SUCCESS);
	}
}
