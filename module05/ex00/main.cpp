/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:32:55 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/16 11:45:58 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Bureaucrat.hpp"

# define RED "\x1b[31;1m"
# define GREEN "\e[1;32m"
# define RESET "\x1b[0m"

int	main( void )
{
	std::cout << GREEN << "WORKING BUREAUCRAT INITIALISATION" << RESET << std::endl;
	try {
		Bureaucrat	test("Jean", 1);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	std::cout << "\n" << std::endl;
	try {
		Bureaucrat	test("Jean", 150);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	std::cout << "\n" << std::endl;

	std::cout << RED << "TOO LOW BUREAUCRAT INITIALISATION" << RESET << std::endl;
	try {
		Bureaucrat	test("Jean", 151);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}

	std::cout << "\n" << std::endl;
	std::cout << RED << "TOO HIGH BUREAUCRAT INITIALISATION" << RESET << std::endl;
	try {
		Bureaucrat	test("Jean", 0);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}

	std::cout << "\n" << std::endl;
	std::cout << RED << "FAIL BUREAUCRAT INCREASE" << RESET << std::endl;
	Bureaucrat	test1("Jean", 1);
	Bureaucrat	test2("Jack", 150);

	try {
		test1.increaseGrade();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	std::cout << "\n" << std::endl;
	try {
		test2.decreaseGrade();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	std::cout << "\n" << std::endl;

	std::cout << " << OPERATOR BUREAUCRAT" << std::endl;
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << "\n" << std::endl;
	return (0);
}