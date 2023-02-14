/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:56:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/14 18:44:02 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	m_nb = 0;
}

Data::Data( const Data &copy )
{
	m_nb = copy.getNumber();
}

Data::Data( const int int_nbr )
{
	m_nb = int_nbr;
}

int	Data::getNumber( void ) const {return (m_nb);}


Data &Data::operator=( const Data &a )
{
	if (this == &a)
		return (*this);
	m_nb = a.getNumber();
	return (*this);
}

std::ostream &operator<<( std::ostream &flux, const Data &Data )
{
	flux << Data.getNumber();
	return (flux);
}

Data::~Data() {}