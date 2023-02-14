/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:34:52 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/25 18:22:15 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		int					m_nb;

	public:
	Data();
	Data( const Data &copy );
	Data( const int int_nbr );
	Data( const float float_nbr );
	~Data();

	int		getNumber( void ) const;
	Data	&operator=( const Data& a );
};

std::ostream 	&operator<<( std::ostream &flux, const Data &Data );

#endif