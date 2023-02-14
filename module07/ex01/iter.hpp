/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:34:31 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/08 12:31:37 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECONVERSION_HPP
# define TYPECONVERSION_HPP

template<typename T>
void	iter(T *table, size_t size, void (*func)(T const &))
{
	if (!table || size < 0 || !func)
		return ;
	for (unsigned int i  = 0; i < size; i++)
		func(table[i]);
}

#endif