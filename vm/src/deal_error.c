/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:37 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:38:39 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int32_t	print_usage(void)
{
	ft_printf("%s%s", USAGE_STR1, USAGE_STR2);
	ft_printf("\t%s%s\n", SEPARATOR, SEPARATOR);
	ft_printf("\t#        %s         #\n", PARENTHESIS);
	ft_printf("\t%s%s\n", SEPARATOR, SEPARATOR);
	ft_printf("\t# %s   #\n", DUMP_USAGE);
	ft_printf("\t# %s       #\n", DUMP_USAGE2);
	ft_printf("\t# %s #\n", VERBOSE_USAGE);
	ft_printf("\t# %s                                    ", VERBOSE_USAGE2);
	ft_printf("   #\n");
	ft_printf("\t# %s                     #\n", VERBOSE_USAGE3);
	ft_printf("\t# %s                               #\n", VERBOSE_USAGE4);
	ft_printf("\t# %s                              #\n", VERBOSE_USAGE5);
	ft_printf("\t# %s                          #\n", VERBOSE_USAGE6);
	ft_printf("\t# %s                              #\n", VERBOSE_USAGE7);
	ft_printf("\t# %s    #\n", VERBOSE_USAGE8);
	ft_printf("\t# %s      #\n", AFF_USAGE);
	ft_printf("\t# %s #\n", NBR_USAGE);
	ft_printf("\t%s%s\n", SEPARATOR, SEPARATOR);
	return (0);
}

void			deal_error(t_data *data, char *to_display, int code)
{
	ft_printf("%s\n", to_display);
	if (code == USAGE)
		print_usage();
	free_data(data);
	exit(1);
}
