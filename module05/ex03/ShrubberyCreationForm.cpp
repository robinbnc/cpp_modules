/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string name, const std::string target ):
	Form(name, 145, 137), m_target(target)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &copy ): Form(copy), m_target(copy.m_target)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		new_filename(m_target + "_shrubbery");
	std::ofstream	oflux;

	try {
		Form::execute(executor);
	}
	catch (std::exception & e) {
		throw ;
	}
	oflux.open(new_filename.c_str());
	if (!oflux)
	{
		std::cout << "Error: opening " + new_filename << std::endl;
		return ;
	}
	oflux << "               ,@@@@@@@," << std::endl;
	oflux << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	oflux << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	oflux << "   ,%&%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	oflux << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	oflux << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	oflux << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	oflux << "       |o|        | |         | |" << std::endl;
	oflux << "       |.|        | |         | |" << std::endl;
	oflux << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	oflux.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm &a )
{
	if (this != &a)
		Form::operator=(a);
	std::cout << "Assignation operator ShrubberyCreationForm called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}
