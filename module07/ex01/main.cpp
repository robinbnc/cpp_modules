/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:54:11 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/16 12:22:38 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "iter.hpp"

class Awesome
 {
     public:
         Awesome( void ) : _n( 42 ) { return; }
         int get( void ) const { return this->_n; }
     private:
         int _n;
 };
 std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

 template< typename T >
 void print( T const & x ) { std::cout << x << std::endl; return; }

//  int main() {
//      int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//      Awesome tab2[5];
//      iter( tab, 5, print );
//      iter( tab2, 5, print );

//      return 0;
//  }

int	main( void )
{
	{
		std::cout << "___ ITER ON CHAR ___\n" << std::endl;
		char table[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

		for (int i = 0; i < 8; i++)
			std::cout << table[i];
		std::cout <<  std::endl;
		::iter<char>(table, 8, print<char>);
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "___ ITER ON INT ___\n" << std::endl;
		int table[8] = {1, 2, 3, 4, 5, 6, 7, 8};

		for (int i = 0; i < 8; i++)
			std::cout << table[i];
		std::cout <<  std::endl;
		::iter<int>(table, 8, print<int>);
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "___ ITER ON DOUBLE ___\n" << std::endl;
		double table[8] = {1.01, 2.01, 3.01, 4.01, 5.01, 6.01, 7.01, 8.01};

		for (int i = 0; i < 8; i++)
			std::cout << table[i] << " ";
		std::cout <<  std::endl;
		::iter<double>(table, 8, print<double>);
		std::cout << "\n" << std::endl;
	}
	return (0);
}
