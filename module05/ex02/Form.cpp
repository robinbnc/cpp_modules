/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:46:00 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/16 19:48:18 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string name, int sign_grade, int exec_grade ): m_name(name)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	else if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else
	{
		m_sign_grade = sign_grade;
		m_exec_grade = exec_grade;
		m_signed = false;
		std::cout << "Default Form constructor called" << std::endl;
	}
}

Form::Form( Form &copy )
{
	*this = copy;
	std::cout << "Copy Form constructor called" << std::endl;
}

int	Form::getSignGrade( void ) const
{
	return (m_sign_grade);
}

int	Form::getExecGrade( void ) const
{
	return (m_exec_grade);
}

int	Form::getSigned( void ) const
{
	return (m_signed);
}

std::string const	Form::getName( void ) const
{
	return (m_name);
}

void	Form::beSigned( Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > m_sign_grade)
		throw Form::GradeTooLowException();
	m_signed = 1;
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > m_exec_grade)
		throw Form::GradeTooLowException();
	else if (!m_signed)
		throw Form::SignatureException();
}

Form &Form::operator=( Form &a )
{
	if (this != &a)
	{
		m_signed = a.getSigned();
		m_sign_grade = a.getSignGrade();
		m_exec_grade = a.getExecGrade();
	}
	return (*this);
}

std::ostream 	&operator<<( std::ostream &flux, const Form &Form )
{
	flux << Form.getName() << ", Form sign grade " << Form.getSignGrade()
		<< ", Form exec grade " << Form.getExecGrade()
		<< (Form.getSigned() == 0 ? ", not signed" : ", signed") <<"."; 
	return (flux);
}

Form::~Form()
{
	std::cout << "Destructor Form called" << std::endl;
}

const char*	Form::GradeTooLowException::what( void ) const throw()
{
	return ("You should pass a higher grade");
}

const char*	Form::GradeTooHighException::what( void ) const throw()
{
	return ("You should pass a lower grade");
}

const char*	Form::SignatureException::what( void ) const throw()
{
	return ("The form is not signed");
}
