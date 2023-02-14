/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name, int grade ): m_name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		m_grade = grade;
		std::cout << "Default Bureaucrat constructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat &copy )
{
	*this = copy;
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

int	Bureaucrat::getGrade( void ) const
{
	return (m_grade);
}

std::string const	Bureaucrat::getName( void ) const
{
	return (m_name);
}

void	Bureaucrat::increaseGrade( void )
{
	if (m_grade > 1)
	{
		m_grade--;
		std::cout << "Bureaucrat " << m_name << " grade increased, new grade " << m_grade << std::endl; 
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade( void )
{
	if (m_grade < 150)
	{
		m_grade++;
		std::cout << "Bureaucrat " << m_name << " grade decreased, new grade " << m_grade << std::endl; 
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

bool	Bureaucrat::signForm( Form &formulaire )
{
	try {
		formulaire.beSigned( *this );
	}
	catch (std::exception & e) {
		std::cout << m_name << " couldn’t sign " << formulaire.getName()
			<< " because " << e.what() << "." << std::endl;;
		return (1);
	}
	std::cout << m_name << " signed " << formulaire.getName() << "." << std::endl;
	return (0);
}

bool	Bureaucrat::executeForm(Form const & form)
{
	try {
		form.execute(*this);
	}
	catch (std::exception & e) {
		std::cout << m_name << " couldn't execute the form " << form.getName()
			<< " because " << e.what() << std::endl;
		return (1);
	}
	std::cout << m_name << " executed " << form.getName() << std::endl;
	return (0);
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat &a )
{
	if (this != &a)
		m_grade = a.m_grade;
	return (*this);
}

std::ostream 	&operator<<( std::ostream &flux, const Bureaucrat &bureaucrat )
{
	flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "."; 
	return (flux);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called" << std::endl;
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("You should pass a higher grade - Range => 1 to 150");
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("You should pass a lower grade - Range => 1 to 150");
}

