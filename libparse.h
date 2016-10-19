/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libparse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:28:35 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/19 15:47:20 by qle-guen         ###   ########.fr       */
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
	int					(*f)(char);
	t_range				r;
}						t_parg;

typedef union u_pfun_t	t_pfun_t;

typedef struct			s_pfun
{
	t_pfun_t			*t;
	int					type;
}						t_pfun;

typedef struct			s_cons
{
	char				*(*f)(t_parg, char *);
	t_parg				arg;
}						t_cons;
# define CONS			1 << 0
# define RUNCONS(x, i)	x.t->cons.f(x.t->cons.arg, i)

typedef struct			s_comb
{
	char				*(*f)(t_pfun, t_pfun, char *inp);
	t_pfun				p1;
	t_pfun				p2;
}						t_comb;

# define COMB			1 << 1
# define RUNCOMB(x, i)	x.t->comb.f(x.t->comb.p1, x.t->comb.p2, i)

typedef struct			s_uni
{
	char				*(*f)(t_parg, t_pfun, char *inp);
	t_parg				arg;
	t_pfun				p;
}						t_uni;

# define UNI			1 << 2
# define RUNUNI(x, i)	x.t->uni.f(x.t->uni.arg, x.t->uni.p, i)

typedef union			u_pfun_t
{
	t_cons				cons;
	t_comb				comb;
	t_uni				uni;
}						t_pfun_t;

char					*run_pfun(t_pfun p, char *inp);
char					*comb_and(t_pfun p1, t_pfun p2, char *inp);
char					*space(t_parg arg, char *inp);
char					*satisfy(t_parg arg, char *inp);
t_pfun			uni(char *(*f)(t_parg, t_pfun, char *), t_pfun pfun, t_parg arg);
t_pfun			cons(char *(*f)(t_parg, char *), t_parg arg);
t_parg			parg_range(int a, int b);
char		*uni_manyrange(t_parg arg, t_pfun p, char *inp);
char		*run_parser(char *fmt, char *inp);

#endif
