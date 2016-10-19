/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cons.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:49:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 15:26:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

t_pfun			cons(char *(*f)(t_parg, char *), t_parg arg)
{
	t_pfun		ret;

	ret.t = malloc(sizeof(*ret.t));
	ret.t->cons.f = f;
	ret.t->cons.arg = arg;
	ret.type = CONS;
	return (ret);
}
