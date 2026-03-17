/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:05:05 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/16 23:49:37 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn void ft_dict_clear(t_dict **dict)
 * @brief Frees the entire dictionary linked list.
 * @details Iterates through the list, freeing the dynamically allocated key
 * string, value string, and the node itself to completely prevent memory leaks.
 * @param dict Double pointer to the head of the dictionary list.
 */
void	ft_dict_clear(t_dict **dict)
{
	t_dict	*tmp;

	if (!dict)
		return ;
	while (*dict)
	{
		tmp = (*dict)->next;
		free((*dict)->key);
		free((*dict)->value);
		free(*dict);
		*dict = tmp;
	}
}
