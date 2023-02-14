/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string name, const std::string target ):
	Form(name, 72, 45), m_target(target)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &copy ): Form(copy), m_target(copy.m_target)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try {
		Form::execute(executor);
	}
	catch (std::exception & e) {
		throw ;
	}
	srand((unsigned) time(NULL));
	std::cout << "Brrrrrrr ..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << m_target << " has been Robotomised successfully!" << std::endl;
	else
		std::cout << "Warning ! Robotomisation failure !" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm &a )
{
	if (this != &a)
		Form::operator=(a);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}
