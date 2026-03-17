/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 03:15:04 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/16 23:57:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- Internal Libraries --------------------------- */
# include <stdlib.h>

/* ========================================================================== */
/* STRUCTS                                                                    */
/* ========================================================================== */

/**
 * @struct s_dict
 * @brief Represents a single entry in the parsed dictionary linked list.
 * @var s_dict::key The numeric string representing the number.
 * @var s_dict::value The alphabetical string representation of the number.
 * @var s_dict::next Pointer to the next node in the dictionary list.
 */
typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

#endif
