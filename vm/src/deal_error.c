/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:37 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:33:38 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int	print_usage(void)
{
	printf("Usage: ./corewar -n [1 - 4] file1.cor ... -n [1 - 4] file4.cor\n");
	return (0);
}

void		deal_error(t_data *data, char *to_display)
{
	if (ft_strequ(to_display, PRINT_USAGE) == true)
		print_usage();
	else
		printf("%s\n", to_display);
	free_data(data);
	exit(1);
}
