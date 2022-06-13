/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:38:21 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/10 16:38:21 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deque_begin(t_deque *deque)
{
	if (deque->begin == NULL)
		return (NULL);
	return (deque->begin);
}

void	*ft_deque_end(t_deque *deque)
{
	if (deque->end == NULL)
		return (NULL);
	return ((char *)deque->end + deque->data_size);
}

void	*ft_deque_next(t_deque *deque, void *i, size_t n)
{
	size_t	size;
	size_t	offset;

	size = deque->data_size;
	offset = ((char *)i - (char *)deque->data) / size;
	offset = (offset + n) % deque->cap;
	return ((char *)deque->data + offset * size);
}

void	*ft_deque_prev(t_deque *deque, void *i, size_t n)
{
	size_t	size;
	size_t	offset;

	size = deque->data_size;
	offset = (i - deque->data) / size;
	if (offset < n)
		return ((char *)deque->data + deque->cap * size - (n - offset));
	return ((char *)deque->data + (offset - n) * size);
}

void	ft_deque_foreach(t_deque *deque, void (*func)(void *))
{
	void	*i;
	size_t	len;

	if (ft_deque_is_empty(deque) == true)
		return ;
	i = deque->begin;
	len = deque->len;
	while (0 < len--)
	{
		func(i);
		i = ft_deque_next(deque, i, 1);
	}
}
