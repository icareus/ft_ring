/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 18:55:47 by abarbaro          #+#    #+#             */
/*   Updated: 2016/07/05 18:56:04 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RING_H
# define FT_RING_H

# ifndef LIBFT_H
#  include <libft.h>
# endif
/*
** RB_INIT(int)
** expands to
**
**  typedef struct {
**      int     l; -> length
**      int     h; -> head (write)
**      int     t; -> tail (read)
**      int     *elems;
**  } int_ring;
*/
# define RB_DEF(T) typedef struct {int l;int h,int t, T* elems;} N_ring;

/*
** RB_DEF(int, int_ring)
**
** int_ring     iring_test;
** RB_INIT(&iring_test, 128, int, ft_memalloc)
** -> iring_test = {128, 0, 0, [128(int)0]}
*/
# define RB_INIT(P, L, T, f) P->size=L+1;P->h=0;P->t=0;P->elems=f(sizeof(T)*L);

# define RB_INC(P, var) P->var=P->var+1%P->size;

# define RB_NEXT_GET(P) ((P->t+1)%P->l)
# define RB_NEXT_PUT(P) ((P->h+1)%P->l)
# define RB_ISEMPTY(P) (P->h==P->t)
# define RB_ISFULL(P) RB_NEXT_PUT(P)==P->t

//# define RB_WRITE(P, E) P->elems[P->h]=E;RB_INC(P, h)if(RB_ISEMPTY(P))

#endif
