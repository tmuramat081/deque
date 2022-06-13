/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_realloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:00:07 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/11 21:00:07 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cast_d;
	unsigned char	*cast_s;

	if (!dst && !src)
		return (NULL);
	cast_d = (unsigned char *)dst;
	cast_s = (unsigned char *)src;
	while (n--)
		*(cast_d++) = *(cast_s++);
	return (dst);
}

t_deque	*ft_deque_copy(t_deque *dst, t_deque *src)
{
	void	*src_i;
	void	*dst_i;
	size_t	len;

	if (src->len > dst->cap)
		return (NULL);
	src_i = src->begin;
	dst_i = dst->begin;
	len = src->len;
	while (len--)
	{
		ft_memcpy(dst_i, src_i, src->data_size);
		src_i = ft_deque_next(src, src_i, 1);
		dst_i = ft_deque_next(dst, dst_i, 1);
	}
	dst->end = dst_i;
	dst->len = src->len;
	return (dst);
}

t_deque	*ft_deque_realloc(t_deque *deque)
{
	t_deque	*new_deque;

	new_deque = ft_deque_init(deque->data_size, deque->cap * 2);
	if (!new_deque)
		return (NULL);
	ft_deque_copy(new_deque, deque);
	ft_deque_delete(&deque);
	deque = new_deque;
	return (deque);
}
