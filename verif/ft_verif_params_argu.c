/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_params_argu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:00:04 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 17:40:32 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_verif_params_argu(char **argv)
{
	if (ft_strstr(argv[1], ".ber") == 0)
		ft_error("Error\nPas le bon format de carte\n", NULL);
	if (ft_multiplepoint(argv[1]) == 0)
		ft_error("Error\nCe nom de carte n'est pas valable\n", NULL);
}
