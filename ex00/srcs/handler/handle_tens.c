/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:08:40 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 01:07:16 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "printer.h"
#include "translator.h"
#include "utils.h"

/**
 * @fn int handle_tens(t_dict *dict, const char *input, int *is_first)
 * @brief Processes 2-digit numbers specifically not found in the dictionary.
 * @details Synthesizes numbers like "42" by isolating the tens position ("40"),
 * printing it, applying the hyphen bonus syntax ("-"), and passing the ones
 * position ("2") back into the translator.
 * @param dict The dictionary linked list.
 * @param input The 2-character numeric string.
 * @param is_first Pointer tracking output spacing.
 * @return 1 on success, 0 on failure.
 */
int	handle_tens(t_dict *dict, const char *input, int *is_first)
{
	t_dict	*node;
	char	tens[3];

	tens[0] = input[0];
	tens[1] = '0';
	tens[2] = '\0';
	node = ft_dict_find(dict, tens);
	if (!node)
	{
		print_error("Dict Error\n");
		return (0);
	}
	print_value(node->value, is_first);
	if (input[1] != '0')
	{
		write(STDOUT_FILENO, "-", 1);
		*is_first = 1;
		return (translate_number(dict, input + 1, is_first));
	}
	return (1);
}
