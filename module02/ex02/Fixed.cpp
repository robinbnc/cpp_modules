/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:56:40 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/07 22:55:41 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	m_fixed_nb = 0;
}

Fixed::Fixed( const Fixed &copy )
{
	if (this == &copy)
		return ;
	m_fixed_nb = copy.getRawBits();
}

Fixed::Fixed( const int int_nbr )
{
	m_fixed_nb = int_nbr << m_fact_bits;
}

Fixed::Fixed( const float float_nbr )
{
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
	if (this == &a)
		return (*this);
	m_fixed_nb = a.getRawBits();
	return (*this);
}

bool	operator>( const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (true);
	return (false);
}

bool	operator<( const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (true);
	return (false);
}

bool	operator<=( const Fixed &a, const Fixed &b)
{
	if (!(a > b))
		return (true);
	return (false);
}

bool	operator>=( const Fixed &a, const Fixed &b)
{
	if (!(a < b))
		return (true);
	return (false);
}

bool	operator==( const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() == b.getRawBits())
		return (true);
	return (false);
}

bool	operator!=( const Fixed &a, const Fixed &b)
{
	if (!(a == b))
		return (true);
	return (false);
}

Fixed	operator+( const Fixed &a, const Fixed &b)
{
	Fixed	result;

	result.setRawBits(a.getRawBits() + b.getRawBits());
	return (result);
}

Fixed	operator-( const Fixed &a, const Fixed &b)
{
	Fixed	result;

	result.setRawBits(a.getRawBits() - b.getRawBits());
	return (result);
}

Fixed	operator*( const Fixed &a, const Fixed &b)
{
	Fixed	result;

	result = a.toFloat() * b.toFloat();
	return (result);
}

Fixed	operator/( const Fixed &a, const Fixed &b)
{
	Fixed	result;

	result = a.toFloat() / b.toFloat();
	return (result);
}

std::ostream &operator<<( std::ostream &flux, const Fixed &fixed )
{
	flux << fixed.toFloat();
	return (flux);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);

	m_fixed_nb++;
	return (tmp);
}

Fixed	&Fixed::operator++( void )
{
	++m_fixed_nb;
	return (*this);
}

Fixed	&Fixed::min( Fixed& a, Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max( Fixed& a, Fixed& b )
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed	&Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (b);
	return (a);
}

Fixed::~Fixed()
{
}