/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:06:14 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/19 14:06:17 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_arg(int argc)
{
	if (argc != 1)
	{
		printf(RED  "ERROR, program takes no arguement\n");
		exit(EXIT_SUCCESS);
	}
}
