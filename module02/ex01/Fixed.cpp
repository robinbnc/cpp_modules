/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:56:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/07 22:55:30 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	m_fixed_nb = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	if (this == &copy)
		return ;
	m_fixed_nb = copy.getRawBits();
}

Fixed::Fixed( const int int_nbr )
{
	std::cout << "Int constructor called" << std::endl;
	m_fixed_nb = int_nbr << m_fact_bits;
}

Fixed::Fixed( const float float_nbr )
{
	std::cout << "Float constructor called" << std::endl;
	m_fixed_nb = roundf(float_nbr * (1 << m_fact_bits));
}

int	Fixed::getRawBits( void ) const
{
	return (m_fixed_nb);
}

void	Fixed::setRawBits( int const raw )
{
	m_fixed_nb = raw;
}

int Fixed::toInt( void ) const
{
	return (m_fixed_nb >> m_fact_bits);
}

float Fixed::toFloat( void ) const
{
	return ((float)m_fixed_nb / (1 << m_fact_bits));
}

Fixed &Fixed::operator=( const Fixed &a )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &a)
		return (*this);
	m_fixed_nb = a.getRawBits();
	return (*this);
}

std::ostream &operator<<( std::ostream &flux, const Fixed &fixed )
{
	flux << fixed.toFloat();
	return (flux);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}