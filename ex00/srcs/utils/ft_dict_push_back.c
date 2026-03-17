/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:47:20 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/16 23:50:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @fn void ft_dict_push_back(t_dict **dict, char *key, char *value)
 * @brief Adds a new entry to the end of the dictionary list.
 * @details Navigates to the end of the linked list and appends a newly
 * allocated node. Safely handles an empty list by updating the head double
 * pointer.
 * @param dict Double pointer to the head of the dictionary list.
 * @param key The string key for the new entry.
 * @param value The string value for the new entry.
 */
void	ft_dict_push_back(t_dict **dict, char *key, char *value)
{
	t_dict	*new;
	t_dict	*curr;

	if (!dict)
		return ;
	new = ft_dict_new_entry(key, value);
	if (!new)
		return ;
	if (!*dict)
	{
		*dict = new;
		return ;
	}
	curr = *dict;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
