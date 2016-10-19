/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:37:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 14:18:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

char		*comb_and(t_pfun p1, t_pfun p2, char *inp)
{
	char		*r1;

	r1 = run_pfun(p1, inp);
	if (!r1)
		return (NULL);
	return (run_pfun(p2, inp));
}
