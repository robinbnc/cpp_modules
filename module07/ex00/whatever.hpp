/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:34:31 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/08 18:30:14 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp = a;

	a = b;
	b = temp;
}

template<typename T>
const T	min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
const T	max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif