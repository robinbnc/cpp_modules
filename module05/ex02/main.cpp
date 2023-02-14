/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:32:55 by rbicanic          #+#    #+#             */
/*   Updated: 2022/06/16 11:43:19 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define RED "\x1b[31;1m"
# define GREEN "\e[1;32m"
# define RESET "\x1b[0m"

int	main( void )
{

	std::cout << GREEN << "\n!----- WORKING TESTS -----!" << RESET << std::endl;
	{
		Bureaucrat				test("Albert", 1);
		PresidentialPardonForm	pres_form("presidential pardon", "test");
		RobotomyRequestForm		rob_form("Robotomy", "test");
		ShrubberyCreationForm	shru_form("shrubbery", "test");

		std::cout << "\n" << std::endl;
		test.signForm(pres_form);
		test.executeForm(pres_form);

		std::cout << "\n" << std::endl;
		test.signForm(rob_form);
		test.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		test.signForm(shru_form);
		test.executeForm(shru_form);
		std::cout << "\n" << std::endl;
	}

	std::cout << RED << "\n!----- FAILING TESTS : SIGNATURE -----!" << RESET << std::endl;
	{
		Bureaucrat				test("Albert", 1);
		PresidentialPardonForm	pres_form("presidential pardon", "test");
		RobotomyRequestForm		rob_form("Robotomy", "test");
		ShrubberyCreationForm	shru_form("shrubbery", "test");

		std::cout << "\n" << std::endl;
		test.executeForm(pres_form);

		std::cout << "\n" << std::endl;
		test.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		test.executeForm(shru_form);
		std::cout << "\n" << std::endl;
	}

	std::cout << RED << "\n!----- FAILING TESTS : GRADE -----!" << RESET << std::endl;
	{
		Bureaucrat				test("Albert", 146);
		Bureaucrat				test2("Jean", 73);
		Bureaucrat				test3("Jack", 25);
		Bureaucrat				test4("Mickael", 1);
		PresidentialPardonForm	pres_form("presidential pardon", "test");
		RobotomyRequestForm		rob_form("Robotomy", "test");
		ShrubberyCreationForm	shru_form("shrubbery", "test");

		std::cout << "\n" << std::endl;
		test4.signForm(pres_form);
		test.executeForm(pres_form);

		std::cout << "\n" << std::endl;
		test4.signForm(rob_form);
		test.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		test4.signForm(shru_form);
		test.executeForm(shru_form);
		std::cout << "\n" << std::endl;
	}
	return (0);
}