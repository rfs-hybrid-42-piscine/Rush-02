/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clean_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:52:56 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/16 23:32:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn char *get_clean_number(char *str)
 * @brief Cleans a numeric string by parsing the sign and leading zeros.
 * @details Skips an optional leading '+' sign, iterates past leading '0's
 * (leaving at least one if the number is exactly zero), and verifies that
 * the rest of the string contains strictly digits.
 * @param str The raw string to clean.
 * @return A pointer to the start of the clean number within the original
 * string, or NULL if invalid characters are found.
 */
char	*get_clean_number(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	if (*str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (NULL);
	while (*str == '0' && ft_isdigit(*(str + 1)))
		str++;
	tmp = str;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (NULL);
	return (str);
}
