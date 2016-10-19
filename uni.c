/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:49:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 15:35:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

t_pfun			uni(char *(*f)(t_parg, t_pfun, char *), t_pfun pfun, t_parg arg)
{
	t_pfun		ret;

	ret.t = malloc(sizeof *ret.t);
	ret.t->uni.f = f;
	ret.t->uni.p = pfun;
	ret.t->uni.arg = arg;
	ret.type = UNI;
	return (ret);
}
