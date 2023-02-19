/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belkarto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:03:22 by belkarto          #+#    #+#             */
/*   Updated: 2023/02/19 17:52:06 by brahim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linux_fdf.h"

void	ft_free1(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free(char ***str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
		ft_free1(str[i]);
	free(str);
}
