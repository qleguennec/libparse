/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_manyrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:57:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 15:47:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

char		*uni_manyrange(t_parg arg, t_pfun p, char *inp)
{
	int		count;

	count = 0;
	while (*inp)
	{
		if (run_pfun(p, inp))
			count++;
		else
			break ;
		inp++;
	}
	if (arg.r.a == -1)
		return (inp);
	if (count >= arg.r.a && (arg.r.b == -1 || count <= arg.r.b))
		return (inp);
	return (NULL);
}
