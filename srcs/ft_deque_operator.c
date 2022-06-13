/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:20:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 12:20:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deque_operator(t_deque *deque, size_t n)
{
	void	*itr;

	itr = ft_deque_begin(deque);
	itr = ft_deque_next(deque, itr, n);
	return (itr);
}
