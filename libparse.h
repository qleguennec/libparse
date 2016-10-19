/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libparse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:28:35 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 14:21:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPARSE_H
# define LIBPARSE_H

# include <stdlib.h>

typedef struct			s_range
{
	int					a;
	int					b;
}						t_range;

typedef union			u_parg
{
	char				c;
	char				*s;
	t_range				r;
}						t_parg;

typedef struct			s_pstate
{
	char				*inp;
	char				*pstack;
}						t_pstate;

typedef union u_pfun_t	t_pfun_t;

typedef struct			s_pfun
{
	t_pfun_t			*t;
	int					type;
}						t_pfun;

typedef struct			s_const
{
	char				*(*f)(t_parg, char *);
	t_parg				arg;
}						t_const;
# define CONST			1 << 0
# define RUNCONST(x, i)	x.t->const_t.f(x.t->const_t.arg, i)

typedef struct			s_comb
{
	char				*(*f)(t_pfun, t_pfun, char *inp);
	t_pfun				p1;
	t_pfun				p2;
}						t_comb;

# define COMB			1 << 1
# define RUNCOMB(x, i)	x.t->comb_t.f(x.t->comb_t.p1, x.t->comb_t.p2, i)

typedef struct			s_uni
{
	char				*(*f)(t_parg, t_pfun, char *inp);
	t_pfun				p;
	t_parg				arg;
}						t_uni;

# define UNI			1 << 2
# define RUNUNI(x, i)	x.t->uni_t.f(x.t->uni_t.arg, x.t->uni_t.p, i)

typedef union			u_pfun_t
{
	t_const				const_t;
	t_comb				comb_t;
	t_uni				uni_t;
}						t_pfun_t;

char					*run_pfun(t_pfun p, char *inp);
char					*com_and(t_pfun p1, t_pfun p2, char *inp);

#endif
