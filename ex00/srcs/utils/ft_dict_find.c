/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:16:24 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/16 23:49:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn t_dict *ft_dict_find(t_dict *dict, const char *key)
 * @brief Searches the dictionary for a specific key.
 * @details Iterates through the linked list and compares the target key against
 * stored keys using ft_strcmp.
 * @param dict Pointer to the head of the dictionary list.
 * @param key The numeric string key to search for.
 * @return Pointer to the matched dictionary node, or NULL if it is not found.
 */
t_dict	*ft_dict_find(t_dict *dict, const char *key)
{
	if (!key)
		return (NULL);
	while (dict)
	{
		if (!ft_strcmp(dict->key, key))
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}
