/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:37:14 by rbicanic          #+#    #+#             */
/*   Updated: 2022/05/18 14:35:38 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Form.hpp"

# define RED "\x1b[31;1m"
# define GREEN "\e[1;32m"
# define RESET "\x1b[0m"

class Form;
class Bureaucrat
{
	private:
		std::string const	m_name;
		int					m_grade;

	public:
		Bureaucrat( const std::string, int grade );
		Bureaucrat( Bureaucrat &copy );
		Bureaucrat	&operator=( Bureaucrat& a );
		virtual ~Bureaucrat();

		int					getGrade( void ) const;
		std::string const	getName( void ) const;
		void				increaseGrade( void );
		void				decreaseGrade( void );
		bool				signForm( Form &formulaire );
		bool				executeForm(Form const & form);

		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw(); 
		};
};

std::ostream 	&operator<<( std::ostream &flux, const Bureaucrat &bureaucrat );

#endif