/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parg_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:12:08 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 14:13:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libparse.h"

t_parg			parg_str(char *s)
{
	t_parg		ret;

	ret.s = s;
	return (ret);
}