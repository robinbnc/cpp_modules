/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:53:13 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/14 14:58:41 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
 
class Fixed
{
	private:
		int					m_fixed_nb;
		static const int	m_fact_bits = 8;

	public:
	Fixed();
	Fixed( Fixed &copy );
	Fixed &operator=( Fixed& a );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif