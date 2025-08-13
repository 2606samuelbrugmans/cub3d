/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:51:28 by mucabrin          #+#    #+#             */
/*   Updated: 2025/08/10 14:33:21 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# include "../libft/libft.h"

# define ERR_DOUBLE "Error: Identifier already used\n"
# define ERR_ID "Error: Invalid identifier\n"
# define ERR_RGB "Error: Invalid RGB structure or values\n"
# define ERR_MAP_NULL "Error: Map null\n"
# define ERR_NO_MAP "Error: No map\n"
# define ERR_MAP "Error: Invalid map\n"
# define ERR_MAP_POS "Error: Invalid map position\n"
# define ERR_MAP_CHAR "Error: Invalid character in map\n"
# define ERR_MAP_DOUBLE "Error: More than one cardinal direction\n"
# define ERR_MAP_NO_CD "Error: No cardinal direction in map\n"
# define ERR_MAP_CLOSED "Error: Map not closed\n"
# define ERR_MLX_INIT "Error: Failed to init mlx\n"
# define ERR_MLX_WIN "Error: Failed to create window\n"
# define ERR_MLX_IMG "Error: Failed to create image\n"
# define ERR_MLX_XPM "Error: Failed to load XPM image\n"

#endif