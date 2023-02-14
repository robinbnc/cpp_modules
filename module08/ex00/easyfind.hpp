/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:34:31 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/25 17:29:21 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <algorithm>
# include <iterator>


template<typename T>
typename T::iterator	easyfind(T &container, int to_find)
{
	return (std::find(container.begin(), container.end(), to_find));
}

#endif