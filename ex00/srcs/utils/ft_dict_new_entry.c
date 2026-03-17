/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_new_entry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:58:08 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/16 23:50:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn t_dict *ft_dict_new_entry(char *key, char *value)
 * @brief Allocates and initializes a new dictionary node.
 * @details Creates a new t_dict element using malloc, assigns the key and
 * value pointers, and safely initializes the next pointer to NULL.
 * @param key The dynamically allocated string representing the numeric key.
 * @param value The dynamically allocated string representing the written value.
 * @return Pointer to the newly created node, or NULL if allocation fails.
 */
t_dict	*ft_dict_new_entry(char *key, char *value)
{
	t_dict	*new;

	new = malloc(sizeof(t_dict));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}
