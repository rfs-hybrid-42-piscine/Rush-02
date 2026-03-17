/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:20:51 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 00:15:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "parser.h"
#include "printer.h"
#include "translator.h"
#include "utils.h"

/**
 * @fn static char *process_input(int argc, char **argv)
 * @brief Determines the source of the numeric input string.
 * @details If no arguments are provided, it dynamically reads from standard
 * input (fd 0) to fulfill the bonus requirement. Otherwise, it uses the
 * provided argument vector.
 * @param argc The number of command line arguments.
 * @param argv The argument vector.
 * @return The target numeric string to translate.
 */
static char	*process_input(int argc, char **argv)
{
	char	*input;

	if (argc == 1)
	{
		input = get_next_line(0);
		if (!input)
			return (NULL);
		return (input);
	}
	return (argv[argc - 1]);
}

/**
 * @fn int main(int argc, char **argv)
 * @brief Entry point for the Rush 02 number-to-text translator.
 * @details Orchestrates the workflow: argument validation, dictionary parsing,
 * input processing, translation execution, and comprehensive memory cleanup.
 * @param argc Argument count.
 * @param argv Argument vector (can contain custom dictionary and number).
 * @return EXIT_SUCCESS (0) on success, EXIT_FAILURE (1) on error.
 */
int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*input;
	int		status;

	if (argc > 3)
	{
		print_error("Error\n");
		return (EXIT_FAILURE);
	}
	dict = NULL;
	if ((argc != 3 && !parser(&dict, "numbers.dict"))
		|| (argc == 3 && !parser(&dict, argv[1])))
	{
		ft_dict_clear(&dict);
		return (EXIT_FAILURE);
	}
	input = process_input(argc, argv);
	status = translator(dict, input);
	ft_dict_clear(&dict);
	if (argc == 1)
		free(input);
	if (!status)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
