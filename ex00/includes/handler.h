/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:09:01 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 00:19:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

/* ========================================================================== */
/* INCLUDES                                                                   */
/* ========================================================================== */

/* --------------------------- External Libraries --------------------------- */
# include "dict.h"

/* --------------------------- Internal Libraries --------------------------- */
# include <stdlib.h>
# include <unistd.h>

/* ========================================================================== */
/* FUNCTIONS                                                                  */
/* ========================================================================== */

int	handle_magnitude(t_dict *dict, const char *input, int *is_first);
int	handle_hundreds(t_dict *dict, const char *input, int *is_first);
int	handle_tens(t_dict *dict, const char *input, int *is_first);

#endif
