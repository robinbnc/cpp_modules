/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:03:08 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/19 12:17:22 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	m_name;
		bool				m_signed;
		int					m_sign_grade;
		int					m_exec_grade;

	public:
		Form( const std::string name, int m_sign_grade, int m_exec_grade );
		Form( Form &copy );
		Form	&operator=( Form& a );
		virtual ~Form();

		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		int					getSigned( void ) const;
		std::string const	getName( void ) const;
		void				beSigned( Bureaucrat &bureaucrat );

		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw(); 
		};
};

std::ostream 	&operator<<( std::ostream &flux, const Form &Form );

#endif