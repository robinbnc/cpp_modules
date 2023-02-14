/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:54:11 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/23 18:52:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "whatever.hpp"

int	main( void )
{
	{
		std::cout << "_____ Subject Tests _____\n" << std::endl;

		int a = 2;
		int b = 3;
		
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "_____Mes Tests_____\n" << std::endl;
		std::cout << "------INT------\n" << std::endl;
		int	a = 21;
		int	b = 42;

		std::cout << "Initial values a = " << a << " | b = " << b << std::endl;
		swap(a, b);
		std::cout << "After swap values a = " << a << " | b = " << b << std::endl;
		std::cout << "Max(a, b) = " << ::max<int>(a, b) << std::endl;
		std::cout << "Min(a, b) = " << ::min<int>(a, b) << std::endl;
		std::cout << "------------\n" << std::endl;
	}
	{
		std::cout << "------FLOAT------\n" << std::endl;
		float	a = 21.0f;
		float	b = 42.0f;

		std::cout << "Initial values a = " << a << " | b = " << b << std::endl;
		swap(a, b);
		std::cout << "After swap values a = " << a << " | b = " << b << std::endl;
		std::cout << "Max(a, b) = " << ::max<float>(a, b) << std::endl;
		std::cout << "Min(a, b) = " << ::min<float>(a, b) << std::endl;
		std::cout << "------------\n" << std::endl;
	}
	{
		std::cout << "------DOUBLE------\n" << std::endl;
		double	a = 21.01;
		double	b = 42.01;

		std::cout << "Initial values a = " << a << " | b = " << b << std::endl;
		swap(a, b);
		std::cout << "After swap values a = " << a << " | b = " << b << std::endl;
		std::cout << "Max(a, b) = " << ::max<double>(a, b) << std::endl;
		std::cout << "Min(a, b) = " << ::min<double>(a, b) << std::endl;
		std::cout << "------------\n" << std::endl;
	}
	{
		std::cout << "------STRING------\n" << std::endl;
		std::string	a = "21";
		std::string	b = "42";

		std::cout << "Initial values a = " << a << " | b = " << b << std::endl;
		swap(a, b);
		std::cout << "After swap values a = " << a << " | b = " << b << std::endl;
		std::cout << "Max(a, b) = " << ::max<std::string>(a, b) << std::endl;
		std::cout << "Min(a, b) = " << ::min<std::string>(a, b) << std::endl;
		std::cout << "------------\n" << std::endl;
	}
	return (0);
}
