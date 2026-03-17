/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:48:24 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 01:03:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "utils.h"

/**
 * @fn void print_error(const char *str)
 * @brief Outputs standard error messages.
 * @details Writes strictly to file descriptor 2 (stderr) as is standard
 * practice.
 * @param str The error string to output.
 */
void	print_error(const char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

/**
 * @fn void print_value(const char *value, int *is_first)
 * @brief Writes dictionary values to standard output.
 * @details Safely manages spacing. If it is not the very first word printed,
 * it prepends a space character before printing the string.
 * @param value The alphabetical string to write.
 * @param is_first Pointer flagging whether this is the first word printed.
 */
void	print_value(const char *value, int *is_first)
{
	if (!*is_first)
		write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, value, ft_strlen(value));
	*is_first = 0;
}

/**
 * @fn int print_zero(t_dict *dict)
 * @brief Prints the value for 0 if it is the only digit provided.
 * @details Uses ft_dict_find to locate the "0" key within the loaded dictionary
 * and outputs its mapped alphabetic value to standard output.
 * @param dict The dictionary linked list.
 * @return 1 on success, 0 if the "0" key is missing from the dictionary.
 */
int	print_zero(t_dict *dict)
{
	t_dict	*node;

	node = ft_dict_find(dict, "0");
	if (!node)
	{
		print_error("Dict Error\n");
		return (0);
	}
	write(STDOUT_FILENO, node->value, ft_strlen(node->value));
	return (1);
}
