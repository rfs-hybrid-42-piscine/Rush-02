/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:21:27 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/10 14:35:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn size_t ft_strlcpy(char *dest, const char *src, size_t size)
 * @brief Safely copies a string to a sized buffer.
 * @details Copies up to size - 1 characters from the NUL-terminated string
 * src to dest, NUL-terminating the result if size is not 0.
 * @param dest The destination buffer.
 * @param src The source string to be copied.
 * @param size The total size of the destination buffer.
 * @return The total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
