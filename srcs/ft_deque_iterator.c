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

void	*ft_deque_front(t_deque *deque)
{
	if (deque->data == NULL)
		return (NULL);
	return (deque->begin);
}

void	*ft_deque_back(t_deque *deque)
{
	if (deque->data == NULL)
		return (NULL);
	return (ft_deque_prev(deque, deque->end, 1));
}

void	*ft_deque_next(t_deque *deque, void *i, size_t n)
{
	char	*start;
	size_t	size;
	size_t	offset;

	start = (char *)deque->data;
	size = deque->data_size;
	offset = ((char *)i - start) / size;
	offset = (offset + n) % deque->cap;
	return (start + offset * size);
}

void	*ft_deque_prev(t_deque *deque, void *i, size_t n)
{
	char	*start;
	size_t	size;
	size_t	offset;

	start = (char *)deque->data;
	size = deque->data_size;
	offset = ((char *)i - start) / size;
	if (offset < n)
		return (start + deque->cap * size - (n - offset) * size);
	return (start + (offset - n) * size);
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
