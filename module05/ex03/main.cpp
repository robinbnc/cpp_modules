/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:32:55 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/20 13:53:24 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main( void )
{

	std::cout << "\n1!----- WORKING TESTS -----!" << std::endl;
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("PresidentiaL PaRdOn", "Bender");
		delete rrf;
	}
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("SHrubbery CREATION", "Bender");
		delete rrf;
	}
	std::cout << "\n" << std::endl;
	std::cout << "\n1!----- FAILING TESTS -----!" << std::endl;
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("Some random Form", "Bender");
		delete rrf;
	}
	return (0);
}
