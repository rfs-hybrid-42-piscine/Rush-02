/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hundreds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:08:33 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 00:19:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "printer.h"
#include "translator.h"
#include "utils.h"

/**
 * @fn int handle_hundreds(t_dict *dict, const char *input, int *is_first)
 * @brief Processes the hundreds position of a 3-digit number.
 * @details Isolates the first digit, translates it, appends the "hundred"
 * dictionary value, and triggers the bonus "and" syntax if further digits
 * exist.
 * @param dict The dictionary linked list.
 * @param input The 3-character numeric string.
 * @param is_first Pointer tracking output spacing.
 * @return 1 on success, 0 if dictionary lookups fail.
 */
int	handle_hundreds(t_dict *dict, const char *input, int *is_first)
{
	t_dict	*node;
	char	hundreds[2];

	hundreds[0] = input[0];
	hundreds[1] = '\0';
	if (!translate_number(dict, hundreds, is_first))
		return (0);
	node = ft_dict_find(dict, "100");
	if (!node)
	{
		print_error("Dict Error\n");
		return (0);
	}
	print_value(node->value, is_first);
	if (input[1] == '0' && input[2] == '0')
		return (1);
	write(STDOUT_FILENO, " and", 4);
	*is_first = 0;
	return (translate_number(dict, input + 1, is_first));
}
