/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_manyrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:57:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 14:26:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

char		*uni_manyrange(t_parg arg, t_pfun p, char *inp)
{
	char	*new;
	int		count;

	new = inp;
	count = 0;
	while (*new)
	{
		new = run_pfun(p, inp);
		if (new)
			count++;
		else
			break ;
	}
	if (arg.r.a == -1)
		return (new);
	if (count >= arg.r.a && (arg.r.b == -1 || count <= arg.r.b))
		return (new);
	return (NULL);
}
