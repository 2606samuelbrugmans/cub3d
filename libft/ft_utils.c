/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:27:19 by mucabrin          #+#    #+#             */
/*   Updated: 2025/05/30 21:34:51 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arraylen(char **strs)
{
	int	i;

	if (!strs || !strs[0])
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_free_strs(char **strs)
{
	int	i;
	int	len;

	if (!strs)
		return ;
	i = 0;
	len = ft_arraylen(strs);
	while (i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_error_malloc(void)
{
	ft_printf_fd(2, ERR_MALLOC);
	exit(EXIT_FAILURE);
}

void	ft_putarray(char **tab, bool p)
{
	int	i;

	i = 0;
	if (p)
		while (tab[i])
			ft_printf_fd(1, "%s\n", tab[i++]);
	else
		while (tab[i])
			ft_printf_fd(1, "%s", tab[i++]);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}
