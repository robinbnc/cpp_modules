/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:27:34 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/23 18:15:52 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	static unsigned int call = 1;
	srand((unsigned) time(NULL) * call);
	int					random_value = std::rand() % 3;

	call = (call == 10 ? 1 : ++call);
	switch (random_value)
	{
		case 0:
			std::cout << "Test sur un A :" << std::endl;
			return (new A);
			break ;
		case 1:
			std::cout << "Test sur un B :" << std::endl;
			return (new B);
			break ;	
		default :
			std::cout << "Test sur un C :" << std::endl;
			return (new C);
			break ;
	}
}

void	identify(Base *p)
{
	if (A *a = dynamic_cast<A*>( p ))
		std::cout << "A";
	else if (B *b = dynamic_cast<B*>( p ))
		std::cout << "B";
	else if (C *b = dynamic_cast<C*>( p ))
		std::cout << "C";
}

void	identify(Base& p)
{
	try 
    {
		A &a = dynamic_cast<A&>( p );
        (void)a;
		std::cout << "A"; 
    } 
    catch ( const std::exception & ) {}
	try 
    {
		B &b = dynamic_cast<B&>( p );
		(void)b;
        std::cout << "B"; 
    } 
    catch ( const std::exception & ) {}
	try 
    {
		C &c = dynamic_cast<C&>( p );
		(void)c;
        std::cout << "C"; 
    } 
    catch ( const std::exception & ) {}
}

int	main( void )
{
	A test;

	for (int i = 0; i < 20; i++)
	{
		Base	*generated_base = generate();
		std::cout << "Mon retour par pointer => ";
		identify(generated_base);
		std::cout << "\tMon retour par référence => ";
		identify(*generated_base);
		delete generated_base;
		std::cout << "\n" << std::endl;;
	}
	return (0);
}
