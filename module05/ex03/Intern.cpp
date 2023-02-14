/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#define ROBOTOMY_REQUEST 0
#define SHRUBERRY_CREATION 1
#define PRESIDENTIAL_PARDON 2

Intern::Intern( void )
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern( Intern &copy )
{
	*this = copy;
	std::cout << "Copy Intern constructor called" << std::endl;
}

int Intern::get_form_type(std::string form_name) const
{
	std::string	form_name_tab[3] = {
		"ROBOTOMY REQUEST", "SHRUBBERY CREATION" ,"PRESIDENTIAL PARDON"
	};

	for (size_t i = 0; i < form_name.length(); i++)
		form_name[i] = std::toupper(form_name[i]);
	for (int i = 0; i < 3; i++)
		if (form_name_tab[i] == form_name)
			return (i);
    return (-1);
}

Form	*Intern::makeForm( std::string form_name, std::string target )
{
    Form        *created_form = NULL;

    switch (get_form_type(form_name))
    {
        case ROBOTOMY_REQUEST:
            created_form = new RobotomyRequestForm(form_name, target);
            std::cout << GREEN << "Intern creates " << form_name << RESET << std::endl;
            break;
        case SHRUBERRY_CREATION:
            created_form = new ShrubberyCreationForm(form_name, target);
            std::cout << GREEN << "Intern creates " << form_name << RESET << std::endl;
            break;
        case PRESIDENTIAL_PARDON:
            created_form = new PresidentialPardonForm(form_name, target);
            std::cout << GREEN << "Intern creates " << form_name << RESET << std::endl;
            break;
        default:
            std::cout << RED << "No matching form name: " << form_name << RESET << std::endl;
    }
	return (created_form);
}

Intern &Intern::operator=( Intern &a )
{
    (void) a;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor Intern called" << std::endl;
}
