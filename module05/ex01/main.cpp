/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:32:55 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/16 11:44:29 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

# define RED "\x1b[31;1m"
# define GREEN "\e[1;32m"
# define RESET "\x1b[0m"

int	main( void )
{
	std::cout << GREEN << "WORKING FORM INITIALISATION" << RESET << std::endl;
	try {
		Form	test("Avis d'imposition", 1, 1);
		Form	test1("Avis d'imposition", 150, 150);
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

	std::cout << RED << "TOO LOW FORM INITIALISATION" << RESET << std::endl;
	try {
		Form	test("Avis d'imposition", 1, 151);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	try {
		Form	test("Avis d'imposition", 151, 18);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}

	std::cout << "\n" << std::endl;
	std::cout << RED << "TOO HIGH FORM INITIALISATION" << RESET << std::endl;
	try {
		Form	test("Avis d'imposition", 0, 16);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	try {
		Form	test("Avis d'imposition", 15, 0);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}

	std::cout << "\n" << std::endl;
	std::cout << GREEN << "WORKING FORM SIGN" << RESET << std::endl;
	Bureaucrat	test1("Jean", 1);
	Form		test2("Avis d'imposition", 10, 10);
	Bureaucrat	test3("Jack", 15);

	std::cout << "\n" << std::endl;
	std::cout << "<< OPERATOR FORM" << std::endl;
	std::cout << test2 << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "FAIL FORM SIGN" << std::endl;
	try {
		test3.signForm(test2);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	try {
		test1.signForm(test2);
	}
		catch (std::exception & e) {
		std::cerr << e.what() << std::endl; 
	}
	std::cout << "\n" << std::endl;
	std::cout << " << OPERATOR FORM" << std::endl;
	std::cout << test2 << std::endl;
	std::cout << "\n" << std::endl;
	return (0);
}