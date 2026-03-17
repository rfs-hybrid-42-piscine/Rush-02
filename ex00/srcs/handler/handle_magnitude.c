/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_magnitude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:08:18 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 01:04:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "printer.h"
#include "translator.h"
#include "utils.h"

/**
 * @fn static int free_memory(char *prefix, char *suffix, char *scale,
 * int is_error)
 * @brief Pipeline helper to safely deallocate magnitude parsing chunks.
 * @details Ensures no memory leaks occur during error cascading or successful
 * magnitude operations by freeing the prefix, suffix, and scale string
 * allocations.
 * @param prefix The dynamically allocated front chunk of the number.
 * @param suffix The dynamically allocated remainder of the number.
 * @param scale The dynamically allocated base-10 magnitude string.
 * @param is_error Flag indicating if this is called during an error state.
 * @return Returns 0 if triggered as an error cascade, 1 if successful cleanup.
 */
static int	free_memory(char *prefix, char *suffix, char *scale, int is_error)
{
	free(prefix);
	free(suffix);
	free(scale);
	if (is_error)
		return (0);
	return (1);
}

/**
 * @fn static void comma_injection(const char *suffix)
 * @brief Evaluates the remaining suffix to inject syntax commas (Bonus).
 * @details Iterates through leading zeros of the remaining chunk to determine
 * if a comma should be printed to the standard output before continuing.
 * @param suffix The remainder of the string after the current magnitude.
 */
static void	comma_injection(const char *suffix)
{
	while (*suffix == '0')
		suffix++;
	if (*suffix)
		write(STDOUT_FILENO, ",", 1);
}

/**
 * @fn static char *get_prefix_suffix(const char *input, int is_prefix)
 * @brief Slices the string to isolate the current magnitude base.
 * @details Divides by modulo 3 to grab chunks like "12" from "12000" (prefix),
 * or returns the remainder "000" (suffix).
 * @param input The number string to slice.
 * @param is_prefix Flag: 1 returns the isolated front chunk, 0 the back chunk.
 * @return A dynamically allocated string chunk.
 */
static char	*get_prefix_suffix(const char *input, int is_prefix)
{
	char	*prefix;
	size_t	size;
	size_t	chunk_len;

	size = ft_strlen(input);
	chunk_len = size % 3;
	if (chunk_len == 0)
		chunk_len = 3;
	if (is_prefix)
	{
		prefix = malloc(sizeof(char) * (chunk_len + 1));
		if (!prefix)
			return (NULL);
		ft_strlcpy(prefix, input, chunk_len + 1);
		return (prefix);
	}
	return (ft_strdup(input + chunk_len));
}

/**
 * @fn static char *get_scale(const char *input)
 * @brief Generates the base-10 string required for dictionary lookup.
 * @details Calculates the zeroes needed (e.g., "1000" for thousands) to query
 * the dictionary for the current magnitude word.
 * @param input The full numeric string currently being evaluated.
 * @return A dynamically allocated string representing the base-10 magnitude.
 */
static char	*get_scale(const char *input)
{
	char	*scale;
	size_t	size;
	size_t	chunk_len;
	size_t	i;

	size = ft_strlen(input);
	chunk_len = size % 3;
	if (chunk_len == 0)
		chunk_len = 3;
	scale = malloc(sizeof(char) * ((size - chunk_len) + 2));
	if (!scale)
		return (NULL);
	*scale = '1';
	i = 0;
	while (++i < (size - chunk_len) + 1)
		scale[i] = '0';
	scale[i] = '\0';
	return (scale);
}

/**
 * @fn int handle_magnitude(t_dict *dict, const char *input, int *is_first)
 * @brief Orchestrates translation for numbers larger than 999.
 * @details Recursively isolates the front chunk, finds the corresponding
 * magnitude word (thousand, million, etc.), and passes the remaining chunk
 * back into the translation loop.
 * @param dict The dictionary linked list.
 * @param input The long numeric string to evaluate.
 * @param is_first Pointer tracking output spacing.
 * @return 1 on success, 0 on failure.
 */
int	handle_magnitude(t_dict *dict, const char *input, int *is_first)
{
	t_dict	*node;
	char	*prefix;
	char	*suffix;
	char	*scale;

	prefix = get_prefix_suffix(input, 1);
	suffix = get_prefix_suffix(input, 0);
	scale = get_scale(input);
	if (!prefix || !suffix || !scale
		|| !translate_number(dict, prefix, is_first))
		return (free_memory(prefix, suffix, scale, 1));
	node = ft_dict_find(dict, scale);
	if (!node)
	{
		print_error("Dict Error\n");
		return (free_memory(prefix, suffix, scale, 1));
	}
	print_value(node->value, is_first);
	comma_injection(suffix);
	if (!translate_number(dict, suffix, is_first))
		return (free_memory(prefix, suffix, scale, 1));
	return (free_memory(prefix, suffix, scale, 0));
}
