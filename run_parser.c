/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:31:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 15:36:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

char			*run_parser(char *fmt, char *inp)
{
	t_parg		dum;

	(void)inp;
	dum.c = 0;
	fmt = RUNUNI(uni(&uni_manyrange
				, cons(&space, dum)
				, parg_range(-1, 0))
			, fmt);
	return (fmt);
}
