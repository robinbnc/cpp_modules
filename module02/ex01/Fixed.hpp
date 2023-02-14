/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:53:13 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/14 18:32:10 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
 
class Fixed
{
	private:
		int					m_fixed_nb;
		static const int	m_fact_bits = 8;

	public:
	Fixed();
	Fixed( const Fixed &copy );
	Fixed( const int int_nbr );
	Fixed( const float float_nbr );
	~Fixed();

	Fixed			&operator=( const Fixed& a );
	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	int 			toInt( void ) const;
	float			toFloat( void ) const;
};

std::ostream 	&operator<<( std::ostream &flux, const Fixed &fixed );

#endif