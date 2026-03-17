/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:47:05 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 01:02:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "printer.h"
#include "utils.h"

/**
 * @fn static int open_file(int *fd, const char *file)
 * @brief Safely attempts to open the dictionary file.
 * @details Wraps the open() system call in read-only mode and validates 
 * the resulting file descriptor to prevent reading from an invalid source.
 * @param fd Pointer to the file descriptor to populate.
 * @param file The file path of the dictionary.
 * @return 1 on successful open, 0 if the file cannot be read or found.
 */
static int	open_file(int *fd, const char *file)
{
	if (!file)
		return (0);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

/**
 * @fn static int process_line(t_dict **dict, const char *line)
 * @brief Validates, splits, and trims a single dictionary line.
 * @details Extracts the numeric key and alphabetic value using the strict
 * `key : value` format. Skips empty lines and trims all surrounding whitespace.
 * @param dict Double pointer to the dictionary linked list.
 * @param line The raw string line read from the dictionary file.
 * @return 1 if successfully parsed or empty, 0 on formatting/memory errors.
 */
static int	process_line(t_dict **dict, const char *line)
{
	char	*trim_key;
	char	*final_key;
	char	*value;
	char	*colon;

	while (ft_isspace(*line))
		line++;
	if (!*line)
		return (1);
	colon = ft_strchr(line, ':');
	if (!colon)
		return (0);
	*colon = '\0';
	trim_key = ft_strtrim(line, " \t\v\f\r");
	final_key = ft_strdup(get_clean_number(trim_key));
	free(trim_key);
	value = ft_strtrim(colon + 1, " \t\n\v\f\r");
	if (!final_key || !value)
	{
		free(final_key);
		free(value);
		return (0);
	}
	ft_dict_push_back(dict, final_key, value);
	return (1);
}

/**
 * @fn int parser(t_dict **dict, const char *file)
 * @brief Core dictionary building function.
 * @details Uses get_next_line to read the target file iteratively, passing
 * each string to the processor. Handles file closure and cleanup upon error.
 * @param dict Double pointer to the dictionary linked list.
 * @param file The file path of the dictionary to parse.
 * @return 1 on complete success, 0 on any parsing or file error.
 */
int	parser(t_dict **dict, const char *file)
{
	int		fd;
	char	*line;

	if (!open_file(&fd, file))
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!(process_line(dict, line)))
		{
			print_error("Dict Error\n");
			ft_dict_clear(dict);
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
