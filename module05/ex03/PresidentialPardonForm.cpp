/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string name, const std::string target ):
	Form(name, 25, 5), m_target(target)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &copy ): Form(copy), m_target(copy.m_target)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try {
		Form::execute(executor);
	}
	catch (std::exception & e) {
		throw ;
	}
	std::cout << m_target << " has been forgiven by Zaphod Beeblebrox.." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm &a )
{
	if (this != &a)
		Form::operator=(a);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}
