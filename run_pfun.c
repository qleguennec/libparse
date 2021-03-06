/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pfun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:21:22 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 15:24:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

char		*run_pfun(t_pfun p, char *inp)
{
	if (p.type == CONS)
		return (RUNCONS(p, inp));
	if (p.type == COMB)
		return (RUNCOMB(p, inp));
	return (RUNUNI(p, inp));
}
