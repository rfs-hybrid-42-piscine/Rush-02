/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:20:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/10 14:33:24 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn size_t ft_strlen(const char *s)
 * @brief Calculates the length of a string.
 * @details Iterates through the string to find the terminating null byte
 * ('\0'). Includes a safety check to prevent dereferencing a NULL pointer.
 * @param s The string to measure.
 * @return The number of characters preceding the terminating null byte.
 */
size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}
