/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:29:51 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/10 14:30:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn char *ft_strchr(const char *s, int c)
 * @brief Locates the first occurrence of c (converted to a char) in the
 * string s.
 * @details The terminating null character is considered to be part of the
 * string; therefore if c is '\0', the functions locate the terminating '\0'.
 * @param s The string to search.
 * @param c The character to find.
 * @return A pointer to the located character, or NULL if the character does
 * not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
