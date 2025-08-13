/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucabrin <mucabrin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:29:39 by mucabrin          #+#    #+#             */
/*   Updated: 2024/04/20 20:54:47 by mucabrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*clear;

	if (!lst || !del)
		return ;
	clear = *lst;
	while (clear)
	{
		tmp = clear;
		clear = clear->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
