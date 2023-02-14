/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:56:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/07 22:55:54 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	m_fixed_nb = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
		m_fixed_nb = copy.getRawBits();
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_fixed_nb);
}

void	Fixed::setRawBits( int const raw )
{
	m_fixed_nb = raw;
}

Fixed &Fixed::operator=( Fixed &a )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &a)
		return (*this);
	m_fixed_nb = a.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}