/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:26:40 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 00:08:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
# include "dict.h"

/* --------------------------- Internal Libraries --------------------------- */
# include <stdlib.h>
# include <unistd.h>

/* ========================================================================== */
/* MACROS                                                                     */
/* ========================================================================== */

/**
 * @def BUFFER_SIZE
 * @brief Determines the byte size of the read chunk for get_next_line.
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/**
 * @def FD_SIZE
 * @brief Defines the maximum number of concurrent file descriptors supported.
 */
# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

t_dict	*ft_dict_new_entry(char *key, char *value);
t_dict	*ft_dict_find(t_dict *dict, const char *key);
void	ft_dict_push_back(t_dict **dict, char *key, char *value);
void	ft_dict_clear(t_dict **dict);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*get_clean_number(char *str);

#endif
