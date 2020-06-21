/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byteswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:16:09 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 19:26:07 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	ft_4byteswap(const uint32_t byte)
{
	uint8_t content[4];

	*((uint32_t*)content) = byte;
	return (((uint32_t)content[3] << 0)
		| ((uint32_t)content[2] << 8)
		| ((uint32_t)content[1] << 16)
		| ((uint32_t)content[0] << 24));
}

uint16_t	ft_2byteswap(const uint16_t byte)
{
	uint8_t content[2];

	*((uint16_t*)content) = byte;
	return (((uint16_t)content[1] << 0)
		| ((uint16_t)content[0] << 8));
}
