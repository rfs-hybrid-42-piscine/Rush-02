/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:01:33 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 01:09:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "printer.h"
#include "translator.h"
#include "utils.h"

/**
 * @fn int translate_number(t_dict *dict, const char *input, int *is_first)
 * @brief Core recursive algorithm for breaking down numbers.
 * @details Evaluates the length of the string to delegate parsing to specific
 * magnitude, hundreds, or tens handlers. Drops leading zeros to prevent errors.
 * @param dict The dictionary linked list.
 * @param input The current numeric string chunk being evaluated.
 * @param is_first Pointer tracking spacing to prevent leading spaces.
 * @return 1 on success, 0 on dictionary failure.
 */
int	translate_number(t_dict *dict, const char *input, int *is_first)
{
	t_dict	*node;

	while (*input == '0')
		input++;
	if (!*input)
		return (1);
	if (ft_strlen(input) <= 2)
	{
		node = ft_dict_find(dict, input);
		if (node)
		{
			print_value(node->value, is_first);
			return (1);
		}
	}
	if (ft_strlen(input) > 3)
		return (handle_magnitude(dict, input, is_first));
	if (ft_strlen(input) == 3)
		return (handle_hundreds(dict, input, is_first));
	if (ft_strlen(input) == 2)
		return (handle_tens(dict, input, is_first));
	print_error("Dict Error\n");
	return (0);
}

/**
 * @fn int translator(t_dict *dict, const char *input)
 * @brief Initiates and finalizes the translation sequence.
 * @details Cleans the raw input string, explicitly handles the "0" edge case,
 * triggers the recursive translation sequence, and appends the final newline.
 * @param dict The dictionary linked list.
 * @param input The raw input string provided by the user/stdin.
 * @return 1 on success, 0 if translation fails.
 */
int	translator(t_dict *dict, const char *input)
{
	char	*trim_input;
	char	*final_input;
	int		is_first;

	trim_input = ft_strtrim(input, " \t\n\v\f\r");
	final_input = ft_strdup(get_clean_number(trim_input));
	free(trim_input);
	if (!final_input)
	{
		print_error("Error\n");
		return (0);
	}
	is_first = 1;
	if ((!ft_strcmp(final_input, "0") && !print_zero(dict))
		|| (ft_strcmp(final_input, "0") != 0
			&& !translate_number(dict, final_input, &is_first)))
	{
		free(final_input);
		return (0);
	}
	free(final_input);
	write(STDOUT_FILENO, "\n", 1);
	return (1);
}
